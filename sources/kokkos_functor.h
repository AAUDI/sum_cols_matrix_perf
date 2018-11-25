#ifndef FUNCTORKOKKOS_H
#define FUNCTORKOKKOS_H

#include "kokkos_shared.h"

class signals_parallel{
public:
    sum_cols_parallel( DataArrayMTX mtx, DataArraySUMCOLS sum_cols_vec): mtx_(mtx), sum_cols_vec_(sum_cols_vec){


    }

    KOKKOS_INLINE_FUNCTION
    void operator()(int index, int & va) const{

    }   

    
    DataArrayMTX mtx_; 
    DataArraySUMCOLS sum_cols_vec_;


};

#endif
