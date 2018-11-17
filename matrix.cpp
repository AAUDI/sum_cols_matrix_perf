#include "matrix.hpp"

void matrix::print_matrix(){
    for(int j=0; j<n; j++){
        for(int i=0; i<m; i++){
            printf("%f ", mtx[j*m + i]);
        }
        printf("\n");
    }
}

void matrix::print_sumcols_matrix(float* sum_cols_mtx){
    for(int i=0; i<m; i++)
        printf("%f ", sum_cols_mtx[i]);
    printf("\n");
}

//column major access
void matrix::sum_cols_matrix_v1(){

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            sum_cols_mtx[i] += mtx[j*m + i];
        }
    }
    print_sumcols_matrix(sum_cols_mtx);
}

void matrix::sum_cols_matrix_openmp_v1(){

    int i = 0, j = 0;
    #pragma omp parallel for private(j) schedule(dynamic) num_threads(nb_threads)
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++){
            sum_cols_mtx[i] += mtx[j*m + i];
            printf("thread_ID %d SUM_COLS_[C %d][R %d] %f\n", omp_get_thread_num(), i, j, sum_cols_mtx[i]);
        }
    print_sumcols_matrix(sum_cols_mtx);
}


//row major access
void matrix::sum_cols_matrix_v2(){

    for(int j=0; j<n; j++)
        for(int i=0; i<m; i++)
            sum_cols_mtx[i] += mtx[j*m + i];
    print_sumcols_matrix(sum_cols_mtx);
}

//row major access
void matrix::sum_cols_matrix_openmp_v2(){

    int i = 0, j = 0;
    #pragma omp parallel for private(i) schedule(dynamic) num_threads(nb_threads)
    for(j=0; j<n; j++){
        for(i=0; i<m; i++){
            sum_cols_mtx[i] +=  mtx[j*m + i];
            printf("thread_ID %d SUM_COLS_[C %d][R %d] %f\n", omp_get_thread_num(), i, j, sum_cols_mtx[i]);
        }
    }
    print_sumcols_matrix(sum_cols_mtx);
}


void matrix::memset_sum_cols_mtx(){
    memset(sum_cols_mtx, 0, sizeof(float)*m);
}