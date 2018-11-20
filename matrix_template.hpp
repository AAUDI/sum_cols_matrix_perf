#ifndef MATRIX_TEMPLATE_HPP
#define MATRIX_TEMPLATE_HPP

#include "stdlib.h"
#include "stdio.h"
#include <time.h>
#include <omp.h>
#include <cstring>
#include <iostream>
#include <pthread.h>

using namespace std;


template <typename T>
struct thread_data{
    int id_thread;
    int nb_rows;
    int nb_columns; 
    int nb_threads;
    T* data_matrix;
    T* sum_cols;
};



template <typename T>
class matrix_template{

public:

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


    #if defined (OPENMP) || defined(PTHREADS)
    matrix_template(int m_, int n_, int nb_threads_, T min_rand, T max_rand) : m(m_), n(n_), nb_threads(nb_threads_){

        if((op_cols_mtx = (T*)malloc(m*sizeof(T))) == NULL){
			printf("error while allocating memory for op_cols_mtx\n");
			exit(1);
		}
        if((mtx = (T*)malloc(m*n*sizeof(T))) == NULL){
			printf("error while allocating memory for mtx\n");
			exit(1);
		}
        printf("Generating the RANDOM MATRIX [ROWS:%d][COLS:%d]\nPlease WAIT ...\n", m, n);
        for(int j=0; j<n; j++){
            for(int i=0; i<m; i++){
                mtx[j*m + i] = T(rand()) / double(RAND_MAX) * (max_rand - min_rand) + min_rand;
            }
        }
    }
    #endif

    
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
    }

    /* ***************************************** OPERATOR ADDITION (TEMPLATE) ****************************************** */
    void operator+(){

        OpenMPTimer computing_time;

        #ifdef NO_OPENMP_GPU
        computing_time.start();
        for(int j=0; j<n; j++)
            for(int i=0; i<m; i++)
                op_cols_mtx[i] += mtx[j*m + i];
        computing_time.stop();
        printf("NON OPTIMIZED addition computing time : %lf\n", computing_time.elapsed());
        computing_time.reset();
        #endif


        #ifdef PTHREADS
        computing_time.start();
        pthread_t threads[nb_threads];
        tdata_t thr_data[nb_threads];

        for(int j=0; j<nb_threads; j++){
            T* sum_cols = NULL;
            if((sum_cols = (T*)malloc(m*sizeof(T))) == NULL){
	            printf("error while allocating memory for sum_cols\n");
	            exit(1);
	        }

            thr_data[j].id_thread = j;
            thr_data[j].nb_columns = m;
            thr_data[j].nb_rows = n;
            thr_data[j].nb_threads = nb_threads;
            thr_data[j].data_matrix = mtx;
            thr_data[j].sum_cols = sum_cols;

            if((pthread_create(&threads[j], NULL, sum_columns, &thr_data[j]) != 0)){
                perror("Problem when creating a thread");
            }
        }

        for(int j=0; j<nb_threads; j++){
            pthread_join(threads[j], NULL);
            printf("End of thread ID : %d\n", (int)threads[j]);
        }   
        for(int j=0; j<nb_threads; j++){
            for(int k=0; k<m; k++){
                sum_cols_mtx[k] += thr_data[j].sum_cols[k];
            }
        }
        for(int j=0; j<nb_threads; j++){
            free(thr_data[j].sum_cols);
        }
        printf("-------------------------------------------\n");
        computing_time.stop();
        printf("OPTIMIZED addition (with PTHREADS) computing time : %lf\n", computing_time.elapsed());
        computing_time.reset();
        for(int k=0; k<m; k++){
            cout <<  sum_cols_mtx[k] << " ";
        }
        printf("\n");
        #endif


        #ifdef OPENMP
        int i=0, j=0;
        computing_time.start(); 
        #pragma omp parallel for private(i) schedule(dynamic) num_threads(nb_threads)
        for(j=0; j<n; j++)
            for(i=0; i<m; i++)
                op_cols_mtx[i] += mtx[j*m + i]; 
        computing_time.stop();
        printf("OPTIMIZED addition (with OPENMP) computing time : %lf\n", computing_time.elapsed());
        computing_time.reset();
        #endif

        #ifdef GPU
        for(int j=0; j<n; j++)
            for(int i=0; i<m; i++)
                op_cols_mtx[i] += mtx[j*m + i];
        #endif
    }

    /* ****************************************** OPERATOR SUBSTRACTION (TEMPLATE) ****************************************** */
    void operator-(){

        OpenMPTimer computing_time;

        #ifdef NO_OPENMP_GPU
        computing_time.start();
        for(int i=0; i<m; i++)
            op_cols_mtx[i] = mtx[i];
        for(int j=1; j<n; j++)
            for(int i=0; i<m; i++)
                op_cols_mtx[i] -= mtx[j*m + i];
        computing_time.stop();
        printf("NON OPTIMIZED substraction computing time : %lf\n", computing_time.elapsed());
        computing_time.reset();
        #endif

        #ifdef OPENMP    
        computing_time.start();  
        for(int i=0; i<m; i++)
            op_cols_mtx[i] = mtx[i];
        int i=0, j=0; 
        #pragma omp parallel for private(i) schedule(dynamic) num_threads(nb_threads)
        for(j=1; j<n; j++){
            for(i=0; i<m; i++){
                op_cols_mtx[i] -= mtx[j*m + i];
            }   
        }
        computing_time.stop();
        printf("OPTIMIZED substraction (with OPENMP) computing time : %lf\n", computing_time.elapsed());
        computing_time.reset();
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

    /* ****************************************** OPERATOR MULTIPLICATION (TEMPLATE) ****************************************** */
    void operator*(){

        OpenMPTimer computing_time;

        #ifdef NO_OPENMP_GPU
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
        #endif

        #ifdef OPENMP
        computing_time.start(); 
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
        computing_time.stop();
        printf("OPTIMIZED multiplication (with OPENMP) computing time : %lf\n", computing_time.elapsed());
        computing_time.reset();
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
     /* ****************************************** OPERATOR DIVISION (TEMPLATE) ****************************************** */
    void operator/(int k){

        OpenMPTimer computing_time;

        #ifdef NO_OPENMP_GPU
        computing_time.start(); 
        for(int i=0; i<m; i++){
            op_cols_mtx[i] = mtx[i];
        }
        for(int j=1; j<n; j++){
            for(int i=0; i<m; i++){
                op_cols_mtx[i] /= mtx[j*m + i];
            }   
        }
        computing_time.stop();
        printf("NON OPTIMIZED division computing time : %lf\n", computing_time.elapsed());
        computing_time.reset();
        #endif

        #ifdef OPENMP
        computing_time.start(); 
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
        computing_time.stop();
        printf("OPTIMIZED division (with OPENMP) computing time : %lf\n", computing_time.elapsed());
        computing_time.reset();
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
