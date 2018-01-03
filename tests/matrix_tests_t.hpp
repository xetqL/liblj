/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   matrix_tests_t.hpp
 * Author: xetql
 *
 * Created on Apr 21, 2017, 2:38:27 PM
 */

#ifndef MATRIX_TESTS_T_HPP
#define MATRIX_TESTS_T_HPP

#include <cppunit/extensions/HelperMacros.h>

class matrix_tests_t : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(matrix_tests_t);
    
    CPPUNIT_TEST(testAccessElement);
    CPPUNIT_TEST(testSubSquare);
    CPPUNIT_TEST_SUITE_END();

public:
    matrix_tests_t();
    virtual ~matrix_tests_t();
    void setUp();
    void tearDown();

private:
    void testMethod();
    void testFailedMethod();
    void testAccessElement();
    void testSubSquare();
};

#endif /* MATRIX_TESTS_T_HPP */

