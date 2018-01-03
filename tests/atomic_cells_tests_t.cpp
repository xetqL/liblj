/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   atomic_cells_tests_t.cpp
 * Author: xetql
 *
 * Created on Apr 10, 2017, 6:42:55 PM
 */
#include <iostream>
#include <memory>

#include "atomic_cells_tests_t.hpp"
#include "../includes/atomic_cells.hpp"

using namespace liblj;

CPPUNIT_TEST_SUITE_REGISTRATION(atomic_cells_tests_t);

atomic_cells_tests_t::atomic_cells_tests_t() {
}

atomic_cells_tests_t::~atomic_cells_tests_t() {
}

void atomic_cells_tests_t::setUp() {
}

void atomic_cells_tests_t::tearDown() {
}

/**
 * Deserialization
 */
void atomic_cells_tests_t::testAtomic_cell_t() {

    std::vector<float> data;
    data.push_back(0.5);
    data.push_back(0.4);
    data.push_back(0.3);
    data.push_back(0.2);

    data.push_back(1.0);
    data.push_back(1.0);
    data.push_back(1.1);
    data.push_back(1.1);

    data.push_back(2.0);
    data.push_back(2.0);
    data.push_back(2.1);
    data.push_back(2.1);

    atomic_cell_t _atomic_cell_t(data);

    CPPUNIT_ASSERT_MESSAGE("LENGHT SHOULD BE", _atomic_cell_t.number_of_work_unit() == 2);
    CPPUNIT_ASSERT_MESSAGE("Y SHOULD BE", (_atomic_cell_t.y == 0.4f));
    CPPUNIT_ASSERT_MESSAGE("WIDTH SHOULD BE", _atomic_cell_t.width == 0.3f);
    CPPUNIT_ASSERT_MESSAGE("HEIGHT SHOULD BE", _atomic_cell_t.height == 0.2f);
}

void atomic_cells_tests_t::testGet_memory_size() {
    std::vector<float> data;
    data.push_back(0.5);
    data.push_back(0.4);
    data.push_back(0.3);
    data.push_back(0.2);

    data.push_back(1.0);
    data.push_back(1.0);
    data.push_back(1.1);
    data.push_back(1.1);

    data.push_back(2.0);
    data.push_back(2.0);
    data.push_back(2.1);
    data.push_back(2.1);

    atomic_cell_t _atomic_cell_t(data);
    int result = _atomic_cell_t.get_memory_size();
    CPPUNIT_ASSERT(result == (data.size() * sizeof (float)));
}

void atomic_cells_tests_t::testSerialize() {
    std::vector<float> data;

    data.push_back(0.5f);
    data.push_back(0.4f);
    data.push_back(0.3f);
    data.push_back(0.2f);

    data.push_back(1.0f);
    data.push_back(1.0f);
    data.push_back(1.1f);
    data.push_back(1.1f);

    data.push_back(2.0f);
    data.push_back(2.0f);
    data.push_back(2.1f);
    data.push_back(2.1f);

    atomic_cell_t _atomic_cell_t(data);

    auto result = _atomic_cell_t.serialize();
    for (int i = 0; i < data.size(); i++) {
        CPPUNIT_ASSERT_EQUAL(data[i], (*result)[i]);
    }
}

void atomic_cells_tests_t::testAdd_work_unit() {
    atomic_cell_t _atomic_cell_t(0.5, 0.2);

    auto wu_builder = work_unit_builder_t::get_instance();

    auto wu1 = wu_builder.with_posx(0.50001f).with_posy(0.20002f).with_velx(0.0f).with_vely(0.0f).build(); //std::make_unique<work_unit_t>(0.50001f, 0.20001f, 0.0f, 0.0f);
    auto wu2 = wu_builder.with_posx(0.50001f).with_posy(0.20002f).with_velx(0.0f).with_vely(0.0f).build();
    auto wu3 = wu_builder.with_posx(0.50001f).with_posy(0.20002f).with_velx(0.0f).with_vely(0.0f).build();
    auto wu4 = wu_builder.with_posx(0.50001f).with_posy(0.20002f).with_velx(0.0f).with_vely(0.0f).build();

    _atomic_cell_t.add_work_unit(wu1);

    _atomic_cell_t.add_work_unit(wu2);

    _atomic_cell_t.add_work_unit(wu3);

    CPPUNIT_ASSERT_MESSAGE("SHOULD CONTAIN", _atomic_cell_t.is_attributed(wu1) &&
            _atomic_cell_t.is_attributed(wu2) &&
            _atomic_cell_t.is_attributed(wu3));
    CPPUNIT_ASSERT_EQUAL(3, (int) _atomic_cell_t.number_of_work_unit());
    CPPUNIT_ASSERT_MESSAGE("SHOULD NOT CONTAIN", !_atomic_cell_t.is_attributed(wu4));
}

void atomic_cells_tests_t::testContains() {
    atomic_cell_t _atomic_cell_t(0.5, 0.2);

    auto wu_builder = work_unit_builder_t::get_instance();

    auto wu1 = wu_builder.with_posx(0.50001f).with_posy(0.20002f).with_velx(0.0f).with_vely(0.0f).build();
    auto wu3 = wu_builder.with_posx(0.50001f).with_posy(0.20002f).with_velx(0.0f).with_vely(0.0f).build();

    auto wu2 = wu_builder.with_posx(0.60001f).with_posy(0.70002f).with_velx(0.0f).with_vely(0.0f).build();
    auto wu4 = wu_builder.with_posx(0.50001f).with_posy(0.80002f).with_velx(0.0f).with_vely(0.0f).build();
    auto wu5 = wu_builder.with_posx(0.40001f).with_posy(0.90002f).with_velx(0.0f).with_vely(0.0f).build();

    _atomic_cell_t.add_work_unit(wu1);

    CPPUNIT_ASSERT_MESSAGE("SHOULD CONTAIN", _atomic_cell_t.contains(wu1));
    CPPUNIT_ASSERT_MESSAGE("SHOULD CONTAIN", _atomic_cell_t.contains(wu3));

    CPPUNIT_ASSERT_MESSAGE("SHOULD NOT CONTAIN", !_atomic_cell_t.contains(wu2));
    CPPUNIT_ASSERT_MESSAGE("SHOULD NOT CONTAIN", !_atomic_cell_t.contains(wu4));
    CPPUNIT_ASSERT_MESSAGE("SHOULD NOT CONTAIN", !_atomic_cell_t.contains(wu5));
}

void atomic_cells_tests_t::testScan() {
    atomic_cell_t _atomic_cell_t(0.5, 0.2);

    auto wu_builder = work_unit_builder_t::get_instance();

    /* Initiate the work units */
    auto wu1 = wu_builder.with_posx(0.50001f).with_posy(0.20001f).with_velx(0.0f).with_vely(0.0f).build();
    auto wu2 = wu_builder.with_posx(0.50001f).with_posy(0.20002f).with_velx(0.0f).with_vely(0.0f).build();
    auto wu3 = wu_builder.with_posx(0.50001f).with_posy(0.20003f).with_velx(0.0f).with_vely(0.0f).build();
    auto wu4 = wu_builder.with_posx(0.50001f).with_posy(0.20004f).with_velx(0.0f).with_vely(0.0f).build();

    /* Add the work units */
    _atomic_cell_t.add_work_unit(wu1);
    _atomic_cell_t.add_work_unit(wu2);
    _atomic_cell_t.add_work_unit(wu3);
    _atomic_cell_t.add_work_unit(wu4);

    /* Modify work units */
    for (auto it = _atomic_cell_t.get_first_work_unit(); it != _atomic_cell_t.get_last_work_unit(); std::advance(it, 2)) {
        it->x = it->x + 1.0f;
        it->y = it->y + 1.0f;
    }

    /* Which ones are out ?*/
    auto wu_out = _atomic_cell_t.scan();
    CPPUNIT_ASSERT_EQUAL(2, (int) wu_out->size());

    atomic_cell_t _atomic_cell_t1(0.5, 0.5);

    /* Initiate the work units */
    auto wu5 = wu_builder.with_posx(0.50001f).with_posy(0.50002f).with_velx(0.0f).with_vely(0.0f).build();
    auto wu6 = wu_builder.with_posx(0.50001f).with_posy(0.50002f).with_velx(0.0f).with_vely(0.0f).build();
    auto wu7 = wu_builder.with_posx(0.50001f).with_posy(0.50002f).with_velx(0.0f).with_vely(0.0f).build();
    auto wu8 = wu_builder.with_posx(0.50001f).with_posy(0.50002f).with_velx(0.0f).with_vely(0.0f).build();

    /* Add the work units */
    _atomic_cell_t1.add_work_unit(wu5);
    _atomic_cell_t1.add_work_unit(wu6);
    _atomic_cell_t1.add_work_unit(wu7);
    _atomic_cell_t1.add_work_unit(wu8);

    /* Modify work units */
    for (auto it = _atomic_cell_t1.get_first_work_unit(); it != _atomic_cell_t1.get_last_work_unit(); std::advance(it, 1)) {
        it->x = it->x + 1.0f;
        it->y = it->y + 1.0f;
    }

    /* Which ones are out ?*/
    auto wu_out_1 = _atomic_cell_t1.scan();

    CPPUNIT_ASSERT_MESSAGE("4 WORK UNITS SHOULD GOES OUT", wu_out_1->size() == 4);
}

void atomic_cells_tests_t::testRemove() {
    atomic_cell_t _atomic_cell_t(0.5, 0.2);

    auto wu_builder = work_unit_builder_t::get_instance();

    /* Initiate the work units */
    auto wu1 = wu_builder.with_posx(0.50001f).with_posy(0.20002f).with_velx(0.0f).with_vely(0.0f).build();
    auto wu2 = wu_builder.with_posx(0.50001f).with_posy(0.20002f).with_velx(0.0f).with_vely(0.0f).build();
    auto wu3 = wu_builder.with_posx(0.50001f).with_posy(0.20002f).with_velx(0.0f).with_vely(0.0f).build();
    auto wu4 = wu_builder.with_posx(0.50001f).with_posy(0.20002f).with_velx(0.0f).with_vely(0.0f).build();

    /* Add the work units */
    _atomic_cell_t.add_work_unit(wu1);
    _atomic_cell_t.add_work_unit(wu2);
    _atomic_cell_t.add_work_unit(wu3);
    _atomic_cell_t.add_work_unit(wu4);

    /* Modify work units */
    for (auto it = _atomic_cell_t.get_first_work_unit(); it != _atomic_cell_t.get_last_work_unit(); std::advance(it, 2)) {
        it->x = it->x + 1.0f;
        it->y = it->y + 1.0f;
    }

    /* Which ones are out ? */
    auto wu_out_bef_rmv = _atomic_cell_t.scan();
    CPPUNIT_ASSERT_EQUAL(2, (int) wu_out_bef_rmv->size());

    /* Remove the ones that are out */
    _atomic_cell_t.remove();

    auto wu_out_aft_rmv = _atomic_cell_t.scan();
    CPPUNIT_ASSERT_EQUAL(0, (int) wu_out_aft_rmv->size());
}

void atomic_cells_tests_t::testDecomposeSpace() {
    /* Arbitrary size */
    auto cells_100 = decompose_space(0.0f, 0.0f, 1.0f, 1.0f);
    int n = (1.0 / ATOMIC_CELL_WIDTH) * (1.0 / ATOMIC_CELL_HEIGHT);
    int expected_n_bordering_cells = (std::sqrt(n)) * 4 - 4; //4 borders and 4 corners are shared by 2 borders each.
    int actual_n_bordering_cells = 0;

    for (auto const& cell : *cells_100) actual_n_bordering_cells += cell.is_bordering_cell ? 1 : 0;

    CPPUNIT_ASSERT_EQUAL(expected_n_bordering_cells, actual_n_bordering_cells);

    CPPUNIT_ASSERT_EQUAL(n, (int) cells_100->size());
    int n_diag = 0;
    for (auto const& cell : *cells_100) {
        n_diag += cell.x == cell.y ? 1 : 0;
    }
    int diag = (1.0 / ATOMIC_CELL_WIDTH);

    CPPUNIT_ASSERT_EQUAL(diag, n_diag);

    /* Space is null */
    auto cells_0 = decompose_space(0.0f, 1.0f, 0.0f, 0.0f);
    int sz = cells_0->size();
    CPPUNIT_ASSERT_EQUAL(0, sz);

    /* Smaller than an atomic cell*/
    auto cells_1 = decompose_space(2.0f, 3.0f, 0.001f, 0.001f);
    CPPUNIT_ASSERT_EQUAL(1, (int) cells_1->size());
}

void atomic_cells_tests_t::testInitWorkUnitsRandom() {
    std::vector<work_unit_t> v;
    float px = 0.0f, py = 0.0f, sx = 1.0f, sy = 1.0f;
    int n = init_work_unit_random<std::uniform_real_distribution<double>>(1000, v, px, py, sx, sy);
    
    for (int i = 0; i < n; i++) {
        CPPUNIT_ASSERT(v[i].x >= px && v[i].x <= (px + sx));
        CPPUNIT_ASSERT(v[i].y >= py && v[i].y <= (py + sy));
    }
    CPPUNIT_ASSERT(v.size() == n);
}

void atomic_cells_tests_t::testBind() {
    float px = 0.0f, py = 0.0f, sx = 0.05f, sy = 0.05f;
    auto cells_100 = decompose_space(px, py, sx, sy);
    std::vector<work_unit_t> v;
    int n = init_work_unit_random<std::uniform_real_distribution<double>>(10, v, px, py, sx, sy);
    CPPUNIT_ASSERT_EQUAL((int) v.size(), n);
    liblj::bind_cell(*cells_100, v);
    int attributed_cell = 0;
    /* Compute the number of cells effectively attriuted */
    for (auto& cell : *cells_100) {
        attributed_cell += cell.number_of_work_unit();
    }
    CPPUNIT_ASSERT_EQUAL(attributed_cell, n);
}
