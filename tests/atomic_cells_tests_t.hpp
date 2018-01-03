/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   atomic_cells_tests_t.hpp
 * Author: xetql
 *
 * Created on Apr 10, 2017, 6:42:55 PM
 */

#ifndef ATOMIC_CELLS_TESTS_T_HPP
#define ATOMIC_CELLS_TESTS_T_HPP

#include <cppunit/extensions/HelperMacros.h>

class atomic_cells_tests_t : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(atomic_cells_tests_t);

    CPPUNIT_TEST(testAtomic_cell_t);
    CPPUNIT_TEST(testGet_memory_size);
    CPPUNIT_TEST(testSerialize);
    CPPUNIT_TEST(testAdd_work_unit);
    CPPUNIT_TEST(testContains);
    CPPUNIT_TEST(testScan);
    CPPUNIT_TEST(testRemove);
    CPPUNIT_TEST(testDecomposeSpace);
    CPPUNIT_TEST(testInitWorkUnitsRandom);
    CPPUNIT_TEST(testBind);
    
    CPPUNIT_TEST_SUITE_END();

public:
    atomic_cells_tests_t();
    virtual ~atomic_cells_tests_t();
    void setUp();
    void tearDown();

private:
    void testAtomic_cell_t();
    void testGet_memory_size();
    void testSerialize();
    void testAdd_work_unit();
    void testContains();
    void testScan();
    void testRemove();
    void testDecomposeSpace();
    void testInitWorkUnitsRandom();
    void testBind();
};

#endif /* ATOMIC_CELLS_TESTS_T_HPP */

