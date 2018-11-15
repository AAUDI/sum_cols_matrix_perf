#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "stdlib.h"
#include "stdio.h"
#include <time.h>

using namespace std;

#define MAX_RAND 100.0
#define MIN_RAND 0.0

class matrix
{

    public:
    
        matrix (int m_, int n_) : m(m_), n(n_){

            mtx = (float**)malloc(n*sizeof(float*));

            for(int j=0; j<n; j++){
                mtx[j] = (float*)malloc(m*sizeof(float));
                for(int i=0; i<m; i++)
                    mtx[j][i] = (rand() / (double) RAND_MAX) * (MAX_RAND - MIN_RAND) + MIN_RAND;
            }

        }
        
        void print_matrix();
        void print_sumcols_matrix();
        float* sum_cols_matrix_v1();
        float* sum_cols_matrix_v2();

        ~matrix(){
            for(int j=0; j<n; j++)
                free(mtx[j]);
            free(mtx);
            free(sum_cols_mtx);
        }

    protected:
        double n, m;
        float** mtx;
        float* sum_cols_mtx;
};




#endif
