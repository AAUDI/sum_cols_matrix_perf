#ifndef MATRIX_TEMPLATE_HPP
#define MATRIX_TEMPLATE_HPP

#include "stdlib.h"
#include "stdio.h"
#include <time.h>
#include <omp.h>
#include <cstring>
#include <iostream>
#include <pthread.h>
#include "pthreads_routines.hpp"
#include "OpenMPTimer.hpp"


using namespace std;

template <typename T>
class matrix_template{

public:

    #ifdef VERSION2
    matrix_template(int m_, int n_, T min_rand, T max_rand) : m(m_), n(n_){

        if((op_cols_mtx = (T*)malloc(m*sizeof(T))) == NULL){
			printf("error while allocating memory for op_cols_mtx\n");
			exit(1);
		}
        if((mtx = (T*)malloc(m*n*sizeof(T))) == NULL){
			printf("error while allocating memory for mtx\n");
			exit(1);
		}
        printf("Generating the RANDOM MATRIX [ROWS:%d][COLS:%d]\nPlease WAIT ...\n", n, m);
        for(int j=0; j<n; j++){
            for(int i=0; i<m; i++){
                mtx[j*m + i] = 1;//T(rand()) / double(RAND_MAX) * (max_rand - min_rand) + min_rand;
            }
        }
    }
    #endif


    #if defined (VERSION2_OPENMP) || defined(VERSION2_PTHREADS)
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
                mtx[j*m + i] = 1;//T(rand()) / double(RAND_MAX) * (max_rand - min_rand) + min_rand;
            }
        }
    }
    #endif

    /* ***************************************** OPERATOR ADDITION (TEMPLATE) ****************************************** */
    void operator+(){

        #if defined (VERSION2) || (VERSION2_OPENMP) || defined(VERSION2_PTHREADS)
        OpenMPTimer computing_time;
        #endif

        #ifdef VERSION2
        computing_time.start();
        for(int j=0; j<n; j++){
            for(int i=0; i<m; i++){
                op_cols_mtx[i] += mtx[j*m + i];
            }
        }
        computing_time.stop();
        printf("NON OPTIMIZED (OPENMP OR PTHREADS) addition computing time : %lf\n", computing_time.elapsed());
        computing_time.reset();
        #endif


        #ifdef VERSION2_PTHREADS
        computing_time.start();
        pthread_t threads[nb_threads];
        struct thread_data_t<T> thr_data[nb_threads];

        for(int j=0; j<nb_threads; j++){
            T* op_cols = NULL;
            if((op_cols = (T*)malloc(m*sizeof(T))) == NULL){
	            printf("error while allocating memory for sum_cols\n");
	            exit(1);
	        }

            thr_data[j].id_thread = j;
            thr_data[j].nb_columns = m;
            thr_data[j].nb_rows = n;
            thr_data[j].nb_threads = nb_threads;
            thr_data[j].data_matrix = mtx;
            thr_data[j].op_cols = op_cols;

            if((pthread_create(&threads[j], NULL, op_sum_columns<T>, &thr_data[j]) != 0)){
                perror("Problem when creating a thread");
            }
        }

        for(int j=0; j<nb_threads; j++){
            pthread_join(threads[j], NULL);
            //printf("End of thread ID : %d\n", (int)threads[j]);
        }   
        for(int j=0; j<nb_threads; j++){
            for(int k=0; k<m; k++){
                op_cols_mtx[k] += thr_data[j].op_cols[k];
            }
        }
        for(int j=0; j<nb_threads; j++){
            free(thr_data[j].op_cols);
        }
        computing_time.stop();
        printf("OPTIMIZED addition (with PTHREADS) computing time : %lf\n", computing_time.elapsed());
        computing_time.reset();
        printf("\n");
        #endif


        #ifdef VERSION2_OPENMP
        int i=0, j=0;
        computing_time.start(); 
        #pragma omp parallel num_threads(nb_threads)
        {
            T op_cols_mtx_private[m] = {0};
            #pragma omp for simd private(i) schedule(static)
            for(j=0; j<n; j++){
                for(i=0; i<m; i++){
                    op_cols_mtx_private[i] += mtx[j*m + i]; 
                }
            }
            #pragma omp critical
            {
                for(i=0; i<m; i++){
                    op_cols_mtx[i] += op_cols_mtx_private[i];
                }
            }
        }
        computing_time.stop();
        printf("OPTIMIZED addition (with OPENMP) computing time : %lf\n", computing_time.elapsed());
        computing_time.reset();
        #endif
    }

    /* ****************************************** OPERATOR SUBSTRACTION (TEMPLATE) ****************************************** */
    void operator-(){

        #if defined (VERSION2) || (VERSION2_OPENMP) || defined(VERSION2_PTHREADS)
        OpenMPTimer computing_time;
        #endif

        #ifdef VERSION2
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
        printf("NON OPTIMIZED (OPENMP OR PTHREADS) substraction computing time : %lf\n", computing_time.elapsed());
        computing_time.reset();
        #endif


        #ifdef VERSION2_PTHREADS
        computing_time.start();

        pthread_t threads[nb_threads];
        struct thread_data_t<T> thr_data[nb_threads];

        for(int j=0; j<nb_threads; j++){
            T* op_cols = NULL;
            if((op_cols = (T*)malloc(m*sizeof(T))) == NULL){
	            printf("error while allocating memory for sub_cols\n");
	            exit(1);
	        }

            thr_data[j].id_thread = j;
            thr_data[j].nb_columns = m;
            thr_data[j].nb_rows = n;
            thr_data[j].nb_threads = nb_threads;
            thr_data[j].data_matrix = mtx;
            thr_data[j].op_cols = op_cols;

            if((pthread_create(&threads[j], NULL, op_sub_columns<T>, &thr_data[j]) != 0)){
                perror("Problem when creating a thread");
            }
        }

        for(int j=0; j<nb_threads; j++){
            pthread_join(threads[j], NULL);
            //printf("End of thread ID : %d\n", (int)threads[j]);
        }   
        for(int j=0; j<nb_threads; j++){
            for(int k=0; k<m; k++){
                op_cols_mtx[k] += thr_data[j].op_cols[k];
            }
        }
        for(int j=0; j<nb_threads; j++){
            free(thr_data[j].op_cols);
        }
        computing_time.stop();
        printf("OPTIMIZED substraction (with PTHREADS) computing time : %lf\n", computing_time.elapsed());
        computing_time.reset();
        printf("\n");
        #endif


        #ifdef VERSION2_OPENMP    
        computing_time.start();       
        #pragma omp parallel num_threads(nb_threads)
        {
            int i=0, j=0;
            int row_start_thread = 0;
            int size_per_thread = n/nb_threads;
            T op_cols_mtx_private[m] = {0};
            row_start_thread = omp_get_thread_num()*(size_per_thread);
          
            //initialization of private array for each thread!
            #pragma omp master
            {
                for(int k=0; k<m; k++){
                    op_cols_mtx_private[k] = mtx[row_start_thread*m + k];
                }
            }
            if(omp_get_thread_num() != 0){
                for(int k=0; k<m; k++){
                    op_cols_mtx_private[k] = -mtx[row_start_thread*m + k];
                }
            }
            #pragma omp for private(i) schedule(static, size_per_thread)
            for(j=0; j<n; j++){
                for(i=0; i<m; i++){
                    if(j != row_start_thread){
                        op_cols_mtx_private[i] -= mtx[j*m + i]; 
                    }
                }
            }
            #pragma omp critical
            {
                for(i=0; i<m; i++){
                    op_cols_mtx[i] += op_cols_mtx_private[i];
                }
            }
        }
        computing_time.stop();
        printf("OPTIMIZED substraction (with OPENMP) computing time : %lf\n", computing_time.elapsed());
        computing_time.reset();
        #endif

    }

    /* ****************************************** OPERATOR MULTIPLICATION (TEMPLATE) ****************************************** */
    void operator*(){

        #if defined (VERSION2) || defined (VERSION2_OPENMP) || defined(VERSION2_PTHREADS)
        OpenMPTimer computing_time;
        #endif

        #ifdef VERSION2
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
        printf("NON OPTIMIZED (OPENMP OR PTHREADS) multiplication computing time : %lf\n", computing_time.elapsed());
        computing_time.reset();
        #endif


        #ifdef VERSION2_PTHREADS
        computing_time.start();
        pthread_t threads[nb_threads];
        struct thread_data_t<T> thr_data[nb_threads];

        for(int k=0; k<m; k++)
             op_cols_mtx[k] = 1;


        for(int j=0; j<nb_threads; j++){
            T* op_cols = NULL;
            if((op_cols = (T*)malloc(m*sizeof(T))) == NULL){
	            printf("error while allocating memory for mul_cols\n");
	            exit(1);
	        }

            thr_data[j].id_thread = j;
            thr_data[j].nb_columns = m;
            thr_data[j].nb_rows = n;
            thr_data[j].nb_threads = nb_threads;
            thr_data[j].data_matrix = mtx;
            thr_data[j].op_cols = op_cols;

            for(int k=0; k<m; k++)
                 thr_data[j].op_cols[k] = 1;


            if((pthread_create(&threads[j], NULL, op_mul_columns<T>, &thr_data[j]) != 0)){
                perror("Problem when creating a thread");
            }
        }

        for(int j=0; j<nb_threads; j++){
            pthread_join(threads[j], NULL);
            //printf("End of thread ID : %d\n", (int)threads[j]);
        }   
        for(int j=0; j<nb_threads; j++){
            for(int k=0; k<m; k++){
                op_cols_mtx[k] *= thr_data[j].op_cols[k];
            }
        }
        for(int j=0; j<nb_threads; j++){
            free(thr_data[j].op_cols);
        }
        computing_time.stop();
        printf("OPTIMIZED multiplication (with PTHREADS) computing time : %lf\n", computing_time.elapsed());
        computing_time.reset();
        printf("\n");
        #endif

        #ifdef VERSION2_OPENMP
        computing_time.start();
        for(int k=0; k<m; k++){
            op_cols_mtx[k] = 1;
        }
        #pragma omp parallel num_threads(nb_threads)
        {
            int i=0, j=0;
            int row_start_thread = 0;
            int size_per_thread = n/nb_threads;
            T op_cols_mtx_private[m] = {0};
            row_start_thread = omp_get_thread_num()*(size_per_thread);
          
            //initialization of private array for each thread!
            for(int k=0; k<m; k++){
                op_cols_mtx_private[k] = mtx[row_start_thread*m + k];
            }

            #pragma omp for private(i) schedule(static, size_per_thread)
            for(j=0; j<n; j++){
                for(i=0; i<m; i++){
                    if(j != row_start_thread){
                        op_cols_mtx_private[i] *= mtx[j*m + i]; 
                    }
                }
            }

            #pragma omp critical
            {
                for(i=0; i<m; i++){
                    op_cols_mtx[i] *= op_cols_mtx_private[i];
                }
            }
        }
        computing_time.stop();
        printf("OPTIMIZED multiplication (with OPENMP) computing time : %lf\n", computing_time.elapsed());
        computing_time.reset();
        #endif
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
            if(i>=0 && i<=9){
                cout << op_cols_mtx[i] << " ";
            }
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
    #if defined (VERSION2_OPENMP) || defined(VERSION2_PTHREADS)
    int nb_threads;
    #endif
};
 


#endif
