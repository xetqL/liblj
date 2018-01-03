/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <cppcheck/cppcheck.hpp>
#include "../includes/common.hpp"
#include <tuple>
#include <iostream>
#include <memory>
using namespace std;

typedef tuple<float*, float*, float*> ParticleData;

int main(int argc, char const *argv[]) {
    float p[] = {9.1, 3.0};
    float v[] = {1.1, 3.0};
    float a[] = {1.1, 3.0};

    TestsRunner runner("liblj bound tests");

    for(float x = -10.0f; x < 10.0f; x += 0.01){
        for(float y = -10.0f; y < 10.0f; y += 0.01){
            p[0] = x; p[1]=y;
            auto test_reflect = make_shared<UnitTest<ParticleData>>("Reflect at the border of the simulation", [p,v,a]() mutable {
                apply_reflect(1, p, v, a, 3.0f);
                return make_tuple(p, v, a);
            }, [](tuple<float*, float*, float*> t ){
                //within the simulation
                return get<0>(t)[0] < 3.0f && get<0>(t)[1] < 3.0f && get<0>(t)[0] >= 0.0f && get<0>(t)[1] >= 0.0f;
            });
            runner.add_test(test_reflect);
        }
    }

    runner.run();
    runner.summarize();

    return runner.are_tests_passed();
}
