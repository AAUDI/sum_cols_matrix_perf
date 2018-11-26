#ifndef MATRIX_TEMPLATE_HPP
#define MATRIX_TEMPLATE_HPP

#include "stdlib.h"
#include "stdio.h"
#include <time.h>
#include <omp.h>
#include <cstring>
#include <iostream>
#include <pthread.h>
#ifdef KOKKOS_ENABLE_OPENMP
#include "OpenMPTimer.h"
#else
#include "CudaTimer.h" 
#endif
#include "kokkos_shared.h"
#include "kokkos_functor.h"


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
                mtx[j*m + i] = 1;//T(rand()) / double(RAND_MAX) * (max_rand - min_rand) + min_rand;
            }
        }
    }

    /* ***************************************** OPERATOR ADDITION (TEMPLATE) ****************************************** */
    void operator+(){
        
        Kokkos::InitArguments args;
        args.num_threads = nb_threads; 
        args.num_numa = 1;
        args.device_id = 0;
        Kokkos::initialize(args);
        {
          std::ostringstream msg;
          //std::cout << "Kokkos configuration" << std::endl;
          if ( Kokkos::hwloc::available() ) {
              msg << "  hwloc( NUMA[" << Kokkos::hwloc::get_available_numa_count()
                  << "  ] x CORE["    << Kokkos::hwloc::get_available_cores_per_numa()
                  << "  ] x HT["      << Kokkos::hwloc::get_available_threads_per_core()
                  << "  ] )"
                  << std::endl ;
          }
          //Kokkos::print_configuration( std::cout );
          //std::cout << msg.str();
	    }
        #ifdef KOKKOS_ENABLE_CUDA
        CudaTimer computing_time;
        #else
        OpenMPTimer computing_time;
        #endif
        
        DataArrayMTX kmtx = DataArrayMTX("matrix", m*n);
        DataArrayMTXHost kmtxHost = Kokkos::create_mirror_view(kmtx);

        for(int j=0; j<n; j++){
            for(int i=0; i<m; i++){
                kmtxHost(j*m + i) = mtx[j*m + i];
            }
        }
        Kokkos::deep_copy(kmtx, kmtxHost);
  
        DataArraySUMCOLS_atomic ksumcols = DataArraySUMCOLS_atomic("sum of matrix columns", m);
        DataArraySUMCOLS_atomicHost ksumcolsHost = Kokkos::create_mirror_view(ksumcols);

        computing_time.start();
        SumColsMatrix functor_sum_cols_mtx(kmtx, ksumcols, m, n);
        Kokkos::parallel_for(m*n, functor_sum_cols_mtx);
        computing_time.stop();
        
        Kokkos::deep_copy(ksumcolsHost, ksumcols);
        printf("NON OPTIMIZED addition computing time : %lf\n", computing_time.elapsed());
        computing_time.reset();
        
        printf("--------------------------------\n");
        for(int i=0; i<m; ++i){
            if(i>=0 && i<=9){
                cout << ksumcolsHost(i) << " ";
            }
        }
        printf("\n");
        Kokkos::finalize();
       
    }

    /* ****************************************** OPERATOR SUBSTRACTION (TEMPLATE) ****************************************** */
    void operator-(){

        #ifdef KOKKOS_ENABLE_OPENMP
        OpenMPTimer computing_time;
        #endif
        #ifdef KOKKOS_ENABLE_CUDA
        CudaTimer computing_time;
        #endif

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

        #ifdef KOKKOS_ENABLE_OPENMP
        OpenMPTimer computing_time;
        #endif
        #ifdef KOKKOS_ENABLE_CUDA
        CudaTimer computing_time;
        #endif
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
            printf("%d:: ", j);
            for(int i=0; i<m; i++){
                cout << mtx[j*m + i] << " ";//printf("%f ", mtx[j*m + i]);
            }
           printf("\n");
        }
        printf("-----------------------------------\n");
    }
    
     /* **************************************** PRINT SUMS OF COLUMNS OF MATRIX  *************************************** */
    void print_op_cols_mtx(){
        for(int i=0; i<m; i++){
            cout << op_cols_mtx[i] << " ";//printf("%f ", op_cols_mtx[i]);
        }
        printf("\n");
        printf("-----------------------------------\n");
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
