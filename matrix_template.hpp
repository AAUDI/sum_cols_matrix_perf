#ifndef MATRIX_TEMPLATE_HPP
#define MATRIX_TEMPLATE_HPP

#include "stdlib.h"
#include "stdio.h"
#include <time.h>
#include <omp.h>
#include <cstring>
#include <iostream>

using namespace std;

template <typename T>
class matrix_template{

public:
    #ifdef OPENMP
    matrix_template(int m_, int n_, int nb_threads_, T min_rand, T max_rand) : m(m_), n(n_), nb_threads(nb_threads_){

        if((op_cols_mtx = (T*)malloc(m*sizeof(T))) == NULL){
			printf("error while allocating memory for op_cols_mtx\n");
			exit(1);
		}
        if((mtx = (T*)malloc(m*n*sizeof(T))) == NULL){
			printf("error while allocating memory for mtx\n");
			exit(1);
		}

        for(int j=0; j<n; j++){
            for(int i=0; i<m; i++){
                mtx[j*m + i] = T(rand()) / double(RAND_MAX) * (max_rand - min_rand) + min_rand;
            }
        }
    }
    #endif

    #ifdef NO_OPENMP_GPU
    matrix_template(int m_, int n_, T min_rand, T max_rand) : m(m_), n(n_){

        if((op_cols_mtx = (T*)malloc(m*sizeof(T))) == NULL){
			printf("error while allocating memory for op_cols_mtx\n");
			exit(1);
		}
        if((mtx = (T*)malloc(m*n*sizeof(T))) == NULL){
			printf("error while allocating memory for mtx\n");
			exit(1);
		}

        for(int j=0; j<n; j++){
            for(int i=0; i<m; i++){
                mtx[j*m + i] = T(rand()) / double(RAND_MAX) * (max_rand - min_rand) + min_rand;
            }
        }
    }
    #endif
    
   void print_matrix(){
        for(int j=0; j<n; j++){
            for(int i=0; i<m; i++){
                cout <<  mtx[j*m + i] << " ";
            }
            cout << "\n";
        }
        cout << "-----------------------------------\n";
    }
    
    void print_op_cols_mtx(){
        for(int i=0; i<m; i++){
            cout <<  op_cols_mtx[i] << " ";
        }
        cout << "\n";
    }

    void operator+(){
        #ifdef NO_OPENMP_GPU
        for(int j=0; j<n; j++)
            for(int i=0; i<m; i++)
                op_cols_mtx[i] += mtx[j*m + i];
        #endif

        #ifdef OPENMP
        int i=0, j=0; 
        #pragma omp parallel for private(i) schedule(dynamic) num_threads(nb_threads)
        for(j=0; j<n; j++)
            for(i=0; i<m; i++)
                op_cols_mtx[i] += mtx[j*m + i];
        #endif

        #ifdef GPU
        for(int j=0; j<n; j++)
            for(int i=0; i<m; i++)
                op_cols_mtx[i] += mtx[j*m + i];
        #endif
    }

    void operator-(){
        #ifdef NO_OPENMP_GPU
        for(int i=0; i<m; i++)
            op_cols_mtx[i] = mtx[i];
        for(int j=1; j<n; j++)
            for(int i=0; i<m; i++)
                op_cols_mtx[i] -= mtx[j*m + i];
        #endif

        #ifdef OPENMP      
        for(int i=0; i<m; i++)
            op_cols_mtx[i] = mtx[i];
        int i=0, j=0; 
        #pragma omp parallel for private(i) schedule(dynamic) num_threads(nb_threads)
        for(j=1; j<n; j++){
            for(i=0; i<m; i++){
                op_cols_mtx[i] -= mtx[j*m + i];
            }   
        }
        #endif

        #ifdef GPU
        for(int i=0; i<m; i++){
            op_cols_mtx[i] = mtx[i];
        }
        for(int j=1; j<n; j++){
            for(int i=0; i<m; i++){
                op_cols_mtx[i] -= mtx[j*m + i];
            }   
        }
        #endif
    }

    void operator*(){
        #ifdef NO_OPENMP_GPU
        for(int i=0; i<m; i++){
            op_cols_mtx[i] = mtx[i];
        }
        for(int j=1; j<n; j++){
            for(int i=0; i<m; i++){
                op_cols_mtx[i] *= mtx[j*m + i];
            }   
        }
        #endif

        #ifdef OPENMP
        for(int i=0; i<m; i++){
            op_cols_mtx[i] = mtx[i];
        }
        int i=0, j=0; 
        #pragma omp parallel for private(i) schedule(dynamic) num_threads(nb_threads)
        for(j=1; j<n; j++){
            for(i=0; i<m; i++){
                op_cols_mtx[i] *= mtx[j*m + i];
            }   
        }
        #endif

        #ifdef GPU
        for(int i=0; i<m; i++){
            op_cols_mtx[i] = mtx[i];
        }
        for(int j=1; j<n; j++){
            for(int i=0; i<m; i++){
                op_cols_mtx[i] *= mtx[j*m + i];
            }   
        }
        #endif
    }

    void operator/(int k){
        #ifdef NO_OPENMP_GPU
        for(int i=0; i<m; i++){
            op_cols_mtx[i] = mtx[i];
        }
        for(int j=1; j<n; j++){
            for(int i=0; i<m; i++){
                op_cols_mtx[i] /= mtx[j*m + i];
            }   
        }
        #endif

        #ifdef OPENMP
        for(int i=0; i<m; i++){
            op_cols_mtx[i] = mtx[i];
        }  
        int i=0, j=0; 
        #pragma omp parallel for private(i) schedule(dynamic) num_threads(nb_threads)
        for(j=1; j<n; j++){
            for(i=0; i<m; i++){
                op_cols_mtx[i] /= mtx[j*m + i];
            }   
        }
        #endif

        #ifdef GPU
        for(int i=0; i<m; i++){
            op_cols_mtx[i] = mtx[i];
        }
        for(int j=1; j<n; j++){
            for(int i=0; i<m; i++){
                op_cols_mtx[i] /= mtx[j*m + i];
            }   
        }
        #endif
    }

    void memset_op_cols_mtx(){
        memset(op_cols_mtx, 0.0, sizeof(T)*m);
    }

    ~matrix_template(){
        free(mtx);
        free(op_cols_mtx);
    }

protected:
    int n, m;
    T* mtx;
    T* op_cols_mtx;
    #ifdef OPENMP
    int nb_threads;
    #endif
};


#endif
