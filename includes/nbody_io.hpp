#ifndef NBODY_IO_H
#define NBODY_IO_H
#include <vector>
void write_header(FILE* fp, int n);
void write_header(FILE* fp, int n, float simsize);
void write_frame_data(FILE* fp, int n, float* x);
void write_frame_data(FILE* fp, int n, std::vector<float> x);
#endif /* NBODY_IO_H */
