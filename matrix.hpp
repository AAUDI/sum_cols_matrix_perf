#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "stdlib.h"
#include "stdio.h"
#include <time.h>
#include <omp.h>
#include <cstring>
#include <pthread.h>
#include "stdint.h"
#include "OpenMPTimer.hpp"

using namespace std;

#ifdef VERSION2_PTHREADS
struct thread_data{

    int id_thread;
    int nb_rows;
    int nb_columns; 
    int nb_threads;
    float* data_matrix;
    float* sum_cols;
};
#endif

class matrix
{
    public:
        #if defined(VERSION1) || defined(VERSION2)
        matrix(int m_, int n_, float min_rand, float max_rand) : m(m_), n(n_){
            
            printf("GENERATING RANDOM MATRIX, PLEASE WAIT ...\n");
            
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
                    mtx[j*m + i] = ((rand() / (double) RAND_MAX) * (max_rand - min_rand) + min_rand);
                }
            }
        }
        #endif

        #if defined(VERSION2_OPENMP) || defined(VERSION2_PTHREADS)
        matrix(int m_, int n_, int nb_threads_, float min_rand, float max_rand) : m(m_), n(n_), nb_threads(nb_threads_){
            
            printf("GENERATING RANDOM MATRIX, PLEASE WAIT ...\n");
            
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
                    mtx[j*m + i] = ((rand() / (double) RAND_MAX) * (max_rand - min_rand) + min_rand);
                }
            }
        }
        #endif
        
        void print_matrix();
        void print_sumcols_matrix();
        #ifdef VERSION1
        void sum_cols_matrix_v1();
        #endif
        #ifdef VERSION2
        void sum_cols_matrix_v2();
        #endif
        #ifdef VERSION2_OPENMP
        void sum_cols_matrix_openmp_v2();
        #endif
        #ifdef VERSION2_PTHREADS
        void sum_cols_matrix_pthreads_v2();
        #endif
        void memset_sum_cols_mtx();


        ~matrix(){
            free(mtx);
            free(sum_cols_mtx);
        }

    protected:
        int n, m;
        float* mtx;
        float* sum_cols_mtx;
        #if defined(VERSION2_OPENMP) || defined(VERSION2_PTHREADS)
        int nb_threads;
        #endif
};




#endif
