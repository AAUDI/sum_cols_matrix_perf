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
    
   void print_matrix(){
        for(int j=0; j<n; j++){
            for(int i=0; i<m; i++){
                cout <<  mtx[j*m + i] << " ";
            }
            cout << "\n";
        }
    }


    void print_op_cols_mtx(){
        for(int i=0; i<m; i++){
            cout <<  op_cols_mtx[i] << " ";
        }
        cout << "\n";
    }

    void operator+(){
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                op_cols_mtx[i] += mtx[j*m + i];
            }   
        }
    }

    void operator-(){


    }

    void operator*(){


    }

    void operator/(int n){


    }

    ~matrix_template(){
        free(mtx);
        free(op_cols_mtx);
    }

protected:
    int n, m;
    T* mtx;
    T* op_cols_mtx;
    int nb_threads;
};


#endif
