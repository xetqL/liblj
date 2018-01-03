/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   matrix_tests_t.cpp
 * Author: xetql
 *
 * Created on Apr 21, 2017, 2:38:27 PM
 */

#include "matrix_tests_t.hpp"
#include "../includes/matrix.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(matrix_tests_t);

matrix_tests_t::matrix_tests_t() {
}

matrix_tests_t::~matrix_tests_t() {
}

void matrix_tests_t::setUp() {
}

void matrix_tests_t::tearDown() {
}

void matrix_tests_t::testAccessElement() {
    liblj::matrix_t<int> m(10, 10);

    for (int i = 0; i < (10 * 10); i++) m.set(i, i);

    for (int i = 0; i < (10 * 10); i++)
        CPPUNIT_ASSERT_EQUAL(i, m[i % 10][i / 10]);
}

void matrix_tests_t::testSubSquare() {
    liblj::matrix_t<int> m(10, 10);

    for (int i = 0; i < (10 * 10); i++) m.set(i, i);

    auto subm = m.subsquare(2, 2, 3);

    for (int i = 2; i < (2 + 3); i++)
        for (int j = 2; j < (2 + 3); j++)
            CPPUNIT_ASSERT_EQUAL(i + j * 10, m[i][j]);
}

