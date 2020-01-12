//
// Created by slahmer on 1/5/20.
//

#include "headers/primitives.h"
void init_fvec(const int N,float *X,float val){
    for (int i = 0; i < N ; ++i)
        X[i] = val;
}


void matrix_copy (int N, int M, float ** Mat1, float** Mat2){

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            Mat1[i][j] = Mat2[i][j];
        }
    }
}
void matrix_init (int N, int M, const float val, float **Mat){
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            Mat[i][j] = val;
        }
    }
}
void matric_scale(int N, int M, const float val, float **Mat){

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            Mat[i][j] *= val;
        }
    }
}