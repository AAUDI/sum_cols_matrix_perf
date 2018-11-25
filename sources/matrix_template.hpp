#ifndef MATRIX_TEMPLATE_HPP
#define MATRIX_TEMPLATE_HPP

#include "stdlib.h"
#include "stdio.h"
#include <time.h>
#include <omp.h>
#include <cstring>
#include <iostream>
#include <pthread.h>
#include "OpenMPTimer.h"


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
        printf("Generating the RANDOM MATRIX [ROWS:%d][COLS:%d]\nPlease WAIT ...\n", n, m);
        int j = 0, i = 0;
        for(j=0; j<n; j++){
            for(i=0; i<m; i++){
                mtx[j*m + i] = T(rand()) / double(RAND_MAX) * (max_rand - min_rand) + min_rand;
            }
        }
    }

    /* ***************************************** OPERATOR ADDITION (TEMPLATE) ****************************************** */
    void operator+(){
        OpenMPTimer computing_time;

        computing_time.start();
        for(int j=0; j<n; j++){
            for(int i=0; i<m; i++){
                op_cols_mtx[i] += mtx[j*m + i];
            }
        }
        computing_time.stop();
        printf("NON OPTIMIZED addition computing time : %lf\n", computing_time.elapsed());
        computing_time.reset();
       
    }

    /* ****************************************** OPERATOR SUBSTRACTION (TEMPLATE) ****************************************** */
    void operator-(){

        OpenMPTimer computing_time;

        computing_time.start();
        for(int i=0; i<m; i++){
            op_cols_mtx[i] = mtx[i];
        }
        for(int j=1; j<n; j++){
            for(int i=0; i<m; i++){
                op_cols_mtx[i] -= mtx[j*m + i];
            }
        }
        computing_time.stop();
        printf("NON OPTIMIZED substraction computing time : %lf\n", computing_time.elapsed());
        computing_time.reset();
    }

    /* ****************************************** OPERATOR MULTIPLICATION (TEMPLATE) ****************************************** */
    void operator*(){

        OpenMPTimer computing_time;
        computing_time.start(); 
        for(int i=0; i<m; i++){
            op_cols_mtx[i] = mtx[i];
        }
        for(int j=1; j<n; j++){
            for(int i=0; i<m; i++){
                op_cols_mtx[i] *= mtx[j*m + i];
            }   
        }
        computing_time.stop();
        printf("NON OPTIMIZED multiplication computing time : %lf\n", computing_time.elapsed());
        computing_time.reset();
    }

      /* ************************************************* PRINT MATRIX  ************************************************ */
    void print_matrix(){
        for(int j=0; j<n; j++){
            for(int i=0; i<m; i++){
                cout <<  mtx[j*m + i] << " ";
            }
            cout << "\n";
        }
        cout << "-----------------------------------\n";
    }
    
     /* **************************************** PRINT SUMS OF COLUMNS OF MATRIX  *************************************** */
    void print_op_cols_mtx(){
        for(int i=0; i<m; i++){
            cout <<  op_cols_mtx[i] << " ";
        }
        cout << "\n";
        cout << "-----------------------------------\n";
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
    int nb_threads;
};
 
#endif
