//
// Created by slahmer on 1/5/20.
//

#include "headers/primitives.h"
void init_fvec(const int N,float *X,float val){
    for (int i = 0; i < N ; ++i)
        X[i] = val;
}


