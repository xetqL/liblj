#ifndef COMMON_H
#define COMMON_H

#define XMIN 0.0
#define YMIN 0.0
#define XMAX 20.0
#define YMAX 20.0

#include <vector>

float compute_LJ_scalar(float r2, float eps, float sig2);
float potential_LJ(float r2, float eps, float sig2);

void leapfrog1(int n, float dt, float* x, float* v, float* a);

void leapfrog2(int n, float dt, float* v, float* a);

void apply_reflect(int n, float* x, float* v, float* a);
void apply_reflect(int n, float* x, float* v, float* a, float simsize);

#endif /* COMMON_H */
