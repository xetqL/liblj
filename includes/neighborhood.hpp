/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   neighborhood.hpp
 * Author: xetql
 *
 * Created on April 7, 2017, 11:23 AM
 */

#ifndef NEIGHBORHOOD_HPP
#define NEIGHBORHOOD_HPP

#include <cmath>
#include <vector>
#include "atomic_cells.hpp"

namespace liblj {
    
    // Structure that represents a neighboring processor.
    struct neighboring_processor_t {
        int rank; /* Processor communication ID */
        std::vector< atomic_cell_t > borders; /* the atomic cells that builds the border with the neighbor */
    };

    class neighborhood_t {
    public:
        neighborhood_t() {
        };
    private:
        std::vector<neighboring_processor_t> neighborhood;
    };
}
#endif /* NEIGHBORHOOD_HPP */

