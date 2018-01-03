/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ljsim.hpp
 * Author: xetql
 *
 * Created on March 31, 2017, 11:25 AM
 */

#ifndef LJSIM_HPP
#define LJSIM_HPP

#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <stdexcept>
#include "params.hpp"
#include <random>
#include <algorithm>

void create_cell_linkedlist(const int nsub, const float lsub, const int nparticle, const float* x, int* particleslklist, int* head) {
    int cell_of_particle;
    for (int icell = 0; icell < nsub * nsub; icell++) head[icell] = -1;
    for (int iparticle = 0; iparticle < nparticle; iparticle++) {
        cell_of_particle = (int) (std::floor(x[2 * iparticle] / lsub)) + nsub * (std::floor(x[2 * iparticle + 1] / lsub));
        if (cell_of_particle >= (nsub * nsub)) throw std::runtime_error(std::to_string(cell_of_particle) + " is out of range");
        particleslklist[iparticle] = head[cell_of_particle];
        head[cell_of_particle] = iparticle;
    }
}

/*@T
 *
 * \subsection{The force computation}
 *
 * Right now, we take local and global arrays of positions and a
 * local array of forces, and compute the force into a local array.
 * The local position array corresponds to indices [[istart <= i < iend]]
 * in the global array.  Apart from not trying to be clever about
 * re-using computations, this looks much the same as (though not identical
 * to) the serial code.
 *@c*/
void compute_forces(int n, const std::vector<float> x,
        int istart, int iend,
        const std::vector<float> xlocal, std::vector<float>& Flocal,
        sim_param_t* params) {

    int nlocal = iend - istart;
    float g = params->G;
    float eps = params->eps_lj;
    float sig = params->sig_lj;
    float sig2 = sig*sig;

    /* Global force downward (e.g. gravity) */
    for (int i = 0; i < nlocal; ++i) {
        Flocal[2 * i + 0] = 0;
        Flocal[2 * i + 1] = -g;
    }

    /* Particle-particle interactions (Lennard-Jones) */
    for (int i = istart; i < iend; ++i) {
        int ii = i - istart;
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                float dx = x[2 * j + 0] - xlocal[2 * ii + 0];
                float dy = x[2 * j + 1] - xlocal[2 * ii + 1];
                float C_LJ = compute_LJ_scalar(dx * dx + dy*dy, eps, sig2);
                Flocal[2 * ii + 0] += (C_LJ * dx);
                Flocal[2 * ii + 1] += (C_LJ * dy);
            }
        }
    }
}

void compute_forces(int n, const std::vector<float> x,
        const std::vector<float> xlocal, std::vector<float>& Flocal,
        sim_param_t* params) {

    float g = params->G;
    float eps = params->eps_lj;
    float sig = params->sig_lj;

    float sig2 = sig*sig;
    int nlocal = xlocal.size() / 2;

    /* Global force downward (e.g. gravity) */
    for (size_t i = 0; i < nlocal; i++) {
        Flocal[2 * i + 0] = 0;
        Flocal[2 * i + 1] = -g;
    }

    /* Particle-particle interactions (Lennard-Jones) */
    for (size_t i = 0; i < nlocal; i++) {
        int ii = i;
        for (size_t j = 0; j < (size_t) n; ++j) {
            if (i != j) {
                float dx = x[2 * j + 0] - xlocal[2 * ii + 0];
                float dy = x[2 * j + 1] - xlocal[2 * ii + 1];
                float C_LJ = compute_LJ_scalar(dx * dx + dy*dy, eps, sig2);
                Flocal[2 * ii + 0] += (C_LJ * dx);
                Flocal[2 * ii + 1] += (C_LJ * dy);
            }
        }
    }
}

/*@T
 *
 * Despite the function abstraction, right now there's only one force
 * computation: Lennard-Jones potential plus a gravitational field.
 *@c*/
void compute_forces(
        const int n, /* Number of particle */
        const int M, /* Number of subcell in a row  */
        const float lsub, /* length of a cell */
        const std::vector<float> x, /* Particles position */
        const int istart,
        const int iend,
        const std::vector<float> xlocal,
        std::vector<float>& Flocal,
        const std::vector<int> head, /* Starting neighboring particles */
        const std::vector<int> plklist, /* Neighboring subcell particles organized as a linkedlist */
        const sim_param_t* params) /* Simulation parameters */ {

    float g = params->G;
    float eps = params->eps_lj;
    float sig = params->sig_lj;
    float sig2 = sig*sig;

    /* Global force downward (e.g. gravity) */
    for (int i = 0; i < (iend - istart); ++i) {
        Flocal[2 * i + 0] = 0;
        Flocal[2 * i + 1] = -g;
    }

    int linearcellidx;
    int nlinearcellidx;
    int nparticleidx;

    // process only the particle we are interested in
    for (int particleidx = istart; particleidx < iend; ++particleidx) {

        int ii = particleidx - istart;

        // find cell from particle position
        linearcellidx = (int) (std::floor(x[2 * particleidx] / lsub)) + M * (std::floor(x[2 * particleidx + 1] / lsub));

        // convert linear index to grid position
        int xcellidx = linearcellidx % M;
        int ycellidx = linearcellidx / M;

        /* Explore neighboring cells */
        for (int neighborx = -1; neighborx < 2; neighborx++) {
            for (int neighbory = -1; neighbory < 2; neighbory++) {

                /* Check boundary conditions */
                if (xcellidx + neighborx < 0 || xcellidx + neighborx >= M) continue;
                if (ycellidx + neighbory < 0 || ycellidx + neighbory >= M) continue;

                nlinearcellidx = (xcellidx + neighborx) + M * (ycellidx + neighbory);

                nparticleidx = head[nlinearcellidx];
                while (nparticleidx != -1) {
                    if (particleidx != nparticleidx) {

                        float dx = x[2 * nparticleidx + 0] - x[2 * particleidx + 0];
                        float dy = x[2 * nparticleidx + 1] - x[2 * particleidx + 1];

                        float C_LJ = compute_LJ_scalar(dx * dx + dy * dy, eps, sig2);

                        Flocal[2 * ii + 0] += (C_LJ * dx);
                        Flocal[2 * ii + 1] += (C_LJ * dy);
                    }
                    nparticleidx = plklist[nparticleidx];
                }
            }
        }
    }
}

/*@T
 *
 * Despite the function abstraction, right now there's only one force
 * computation: Lennard-Jones potential plus a gravitational field.
 *@c*/
void compute_forces(int n, /* Number of particle */
        int M, /* Number of subcell in a row  */
        const float* x, /* Particles position */
        float* F, /* Forces to compute */
        const int* head, /* Starting neighboring particles */
        const int* plklist, /* Neighboring subcell particles organized as a linkedlist */
        sim_param_t* params) /* Simulation parameters */ {
    // sim_param_t* params = (sim_param_t*) fdata;
    float g = params->G;
    float eps = params->eps_lj;
    float sig = params->sig_lj;
    float sig2 = sig*sig;

    /* Global force downward (e.g. gravity) */
    for (int i = 0; i < n; ++i) {
        F[2 * i + 0] = 0;
        F[2 * i + 1] = -g;
    }

    int linearcellidx;
    int nlinearcellidx;
    int particleidx;
    int nparticleidx;

    /* For each cell in the Lennard-Jones simulation */
    for (int xcellidx = 0; xcellidx < M; xcellidx++) {
        for (int ycellidx = 0; ycellidx < M; ycellidx++) {
            linearcellidx = xcellidx + M * ycellidx;
            /* Explore neighboring cells */
            for (int neighborx = -1; neighborx < 2; neighborx++) {
                for (int neighbory = -1; neighbory < 2; neighbory++) {

                    /* Check boundary conditions */
                    if (xcellidx + neighborx < 0 || xcellidx + neighborx >= M) continue;
                    if (ycellidx + neighbory < 0 || ycellidx + neighbory >= M) continue;

                    nlinearcellidx = (xcellidx + neighborx) + M * (ycellidx + neighbory);
                    particleidx = head[linearcellidx];

                    while (particleidx != -1) {
                        nparticleidx = head[nlinearcellidx];
                        while (nparticleidx != -1) {
                            if (particleidx < nparticleidx) {
                                float dx = x[2 * nparticleidx + 0] - x[2 * particleidx + 0];
                                float dy = x[2 * nparticleidx + 1] - x[2 * particleidx + 1];
                                float C_LJ = compute_LJ_scalar(dx * dx + dy*dy, eps, sig2);
                                F[2 * particleidx + 0] += (C_LJ * dx);
                                F[2 * particleidx + 1] += (C_LJ * dy);
                                F[2 * nparticleidx + 0] -= (C_LJ * dx);
                                F[2 * nparticleidx + 1] -= (C_LJ * dy);
                            }
                            nparticleidx = plklist[nparticleidx];
                        }
                        particleidx = plklist[particleidx];
                    }
                }
            }
        }
    }
}

/*@T
 *
 * Despite the function abstraction, right now there's only one force
 * computation: Lennard-Jones potential plus a gravitational field.
 *@c*/
void compute_forces(int n, /* Number of particle */
        int M, /* Number of subcell in a row  */
        const std::vector<float> x, /* Particles position */
        std::vector<float>& F, /* Forces to compute */
        const std::vector<int> head, /* Starting neighboring particles */
        const std::vector<int> plklist, /* Neighboring subcell particles organized as a linkedlist */
        void* fdata) /* Simulation parameters */ {

    sim_param_t* params = (sim_param_t*) fdata;

    float g = params->G;
    float eps = params->eps_lj;
    float sig = params->sig_lj;
    float sig2 = sig*sig;

    /* Global force downward (e.g. gravity) */
    for (int i = 0; i < n; ++i) {
        F[2 * i + 0] = 0;
        F[2 * i + 1] = -g;
    }
    int linearcellidx;
    int nlinearcellidx;
    int particleidx;
    int nparticleidx;

    /* For each cell in the Lennard-Jones simulation */
    for (int xcellidx = 0; xcellidx < M; xcellidx++) {
        for (int ycellidx = 0; ycellidx < M; ycellidx++) {
            linearcellidx = xcellidx + M * ycellidx;
            /* Explore neighboring cells */
            for (int neighborx = -1; neighborx < 2; neighborx++) {
                for (int neighbory = -1; neighbory < 2; neighbory++) {

                    /* Check boundary conditions */
                    if (xcellidx + neighborx < 0 || xcellidx + neighborx >= M) continue;
                    if (ycellidx + neighbory < 0 || ycellidx + neighbory >= M) continue;

                    nlinearcellidx = (xcellidx + neighborx) + M * (ycellidx + neighbory);
                    particleidx = head[linearcellidx];

                    while (particleidx != -1) {
                        nparticleidx = head[nlinearcellidx];
                        while (nparticleidx != -1) {
                            if (particleidx < nparticleidx) {
                                float dx = x[2 * nparticleidx + 0] - x[2 * particleidx + 0];
                                float dy = x[2 * nparticleidx + 1] - x[2 * particleidx + 1];
                                float C_LJ = compute_LJ_scalar(dx * dx + dy*dy, eps, sig2);
                                F[2 * particleidx + 0] += (C_LJ * dx);
                                F[2 * particleidx + 1] += (C_LJ * dy);
                                F[2 * nparticleidx + 0] -= (C_LJ * dx);
                                F[2 * nparticleidx + 1] -= (C_LJ * dy);
                            }
                            nparticleidx = plklist[nparticleidx];
                        }
                        particleidx = plklist[particleidx];
                    }
                }
            }
        }
    }
}

template<typename Iter>
void shuffle_particles(Iter it, Iter end) {

    std::random_device rd; //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()

    for (; std::distance(it, end) > 2; it += 2) {
        std::uniform_int_distribution<> dist(1, (std::distance(it, end) - 2) / 2);

        int swap_with_a = dist(gen) * 2;
        int swap_with_b = swap_with_a + 1;

        auto swap_value_a = *(it + swap_with_a);
        auto swap_value_b = *(it + swap_with_b);

        // xor swap a
        *(it + swap_with_a) = *it;
        *it = swap_value_a;

        // xor swap b
        *(it + swap_with_b) = *(it + 1);
        *(it + 1) = swap_value_b;
    }
}

#endif /* LJSIM_HPP */
