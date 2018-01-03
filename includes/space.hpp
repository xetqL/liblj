/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   space.hpp
 * Author: xetql
 *
 * Created on April 23, 2017, 3:53 PM
 */

#ifndef SPACE_HPP
#define SPACE_HPP

#include <memory>
#include <vector>

#include "atomic_cells.hpp"
namespace liblj {
    
    //const double C = 0.034;
    const double SIG = 1e-2;
    const double RCUT = (2.5*SIG);

    class space_t {
        std::vector<atomic_cell_t> borders;
        std::vector<atomic_cell_t>   cells; //also includes bordering cells
    public:

        space_t() {}

        void add_cell(atomic_cell_t c) {
            if (c.is_bordering_cell) borders.push_back(c);
            cells.push_back(c);
        }

        /**
         * Checks if a work unit interacts outside of this space
         * @param wu
         * @return 
         */
        bool is_interacting_outside(work_unit_t wu) {
            for (atomic_cell_t border_cell : borders) {
                if(border_cell.distance2(wu) < std::pow(RCUT, 2)) return true;
            }
            return false;
        }
    };
}

#endif /* SPACE_HPP */

