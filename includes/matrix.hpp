/* 
 * File:   matrix.hpp
 * Author: xetql
 *
 * Created on April 21, 2017, 2:07 PM
 */

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <memory>
#include <vector>

namespace liblj {

    template<typename t_content>
    class matrix_t {
        t_content* matrix;
        const size_t row, col;
    public:

        matrix_t(const size_t row, const size_t col) : row(row), col(col) {
            matrix = new t_content[row * col];
        }

        virtual ~matrix_t() {
            delete[] matrix;
        }

        /**
         * Get the col
         * @param index
         * @return 
         */
        std::vector<t_content> operator[](std::size_t index) {
            std::vector<t_content> v;
            for (size_t i = 0; i < col; i++) {
                v.push_back(this->matrix[i * row + index]);
            }
            return v;
        }

        void set(const size_t row, const size_t col, t_content value) {
            matrix[col + col * row] = value;
        }
        
        void set(const size_t cell_idx, t_content value) {
            matrix[cell_idx] = value;
        }
        /**
         * Retrieve a sub-square from the entire matrix 
         * @param top_left_col
         * @param top_left_row
         * @param border_size
         * @return 
         */
        matrix_t<t_content> subsquare(const size_t top_left_col, const size_t top_left_row, const size_t border_size) {
            matrix_t<t_content> sqr(border_size, border_size);
            for (size_t r = 0; r < border_size; r++) {
                for (size_t c = 0; c < border_size; c++) {
                    sqr.set(r, c, matrix[(top_left_col + c) + (top_left_col * (top_left_row + r))]);
                }
            }
            return sqr;
        }
        /**
         * Get the number of rows
         * @return number of rows
         */
        int rsize() const {
            return (int) row;
        }
        /**
         * Get the number of columns
         * @return number of columns
         */
        int csize() const {
            return (int) col;
        }
        /**
         * Get the total size of the matrix: row * col
         * @return number of cells
         */
        int size() const {
            return ((int) col) * ((int) row);
        }
    };
}
#endif /* MATRIX_HPP */

