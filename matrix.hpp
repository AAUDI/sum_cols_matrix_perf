#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "stdlib.h"
#include "stdio.h"
#include <time.h>
#include <omp.h>
#include <cstring>
#include <pthread.h>
#include "stdint.h"

using namespace std;

#define MAX_RAND 100.0
#define MIN_RAND 0.0


struct thread_data{

    int id_thread;
    int nb_rows;
    int nb_columns; 
    int nb_threads;
    float* data_matrix;
    float* sum_cols;
};


class matrix
{
    public:
    
        matrix(int m_, int n_, int nb_threads_) : m(m_), n(n_), nb_threads(nb_threads_){

            if((sum_cols_mtx = (float*)malloc(m*sizeof(float))) == NULL){
			    printf("error while allocating memory for sum_cols_mtx\n");
			    exit(1);
		    }
            if((mtx = (float*)malloc(m*n*sizeof(float))) == NULL){
			    printf("error while allocating memory for mtx\n");
			    exit(1);
		    }

            for(int j=0; j<n; j++){
                for(int i=0; i<m; i++){
                    mtx[j*m + i] = ((rand() / (double) RAND_MAX) * (MAX_RAND - MIN_RAND) + MIN_RAND);
                }
            }
        }

        
        void print_matrix();
        void print_sumcols_matrix(float* sum_cols_mtx);
        void sum_cols_matrix_v1();
        void sum_cols_matrix_v2();
        void sum_cols_matrix_openmp_v2();
        void sum_cols_matrix_pthreads_v2();
        void memset_sum_cols_mtx();


        ~matrix(){
            free(mtx);
            free(sum_cols_mtx);
        }

    protected:
        int n, m;
        float* mtx;
        float* sum_cols_mtx;
        int nb_threads;
};




#endif
