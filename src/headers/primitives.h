//
// Created by slahmer on 1/5/20.
//

#ifndef BLASTER_PRIMITIVES_H
#define BLASTER_PRIMITIVES_H


void init_fvec(const int N,float *X,float val);


void matrix_copy (int N, int M, float **, float **);
void matrix_init (int N, int M, const float, float **);
void matric_scale(int N, int M, const float, float **);


#endif //BLASTER_PRIMITIVES_H
