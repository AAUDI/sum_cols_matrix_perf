#ifndef FUNCTORKOKKOS_H
#define FUNCTORKOKKOS_H

#include "kokkos_shared.h"

class SumColsMatrix{
public:
    SumColsMatrix(DataArrayMTX mtx, DataArraySUMCOLS sum_cols_vec, int m, int n): 
    mtx_(mtx), sum_cols_vec_(sum_cols_vec), m_(m), n_(n){}

    KOKKOS_INLINE_FUNCTION
    void operator()(int index) const{
        
        int j = 0;
        int i = 0;
        index2coord(index, i, j, m_, n_);
        sum_cols_vec_[i] += mtx_[j*m_ + i];
        //printf("index %d i %d j %d val %f mtx_[%d] %f\n", index, i, j, sum_cols_vec_[i], j*m_ + i, mtx_[j*m_ + i]);

    }   
 
    DataArrayMTX mtx_; 
    DataArraySUMCOLS sum_cols_vec_;
    int m_;
    int n_;
};

#endif
