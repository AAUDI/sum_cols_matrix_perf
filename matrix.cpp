#include "matrix.hpp"

void matrix::print_matrix(){
    for(int j=0; j<n; j++){
        for(int i=0; i<m; i++){
            printf("mtx[%d][%d] %f ", j, i, mtx[j*m + i]);
        }
        printf("\n");
    }
}

void matrix::print_sumcols_matrix(){
    for(int i=0; i<m; i++)
        printf("sum_cols[%d] %f ", i, sum_cols_mtx[i]);
    printf("\n");
}

//column major access
float* matrix::sum_cols_matrix_v1(){

    sum_cols_mtx = (float*)malloc(m*sizeof(float));

    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            sum_cols_mtx[i] += mtx[j*m + i];

    return sum_cols_mtx;

}

//row major access
float* matrix::sum_cols_matrix_v2(){

    sum_cols_mtx = (float*)malloc(m*sizeof(float));

    for(int j=0; j<n; j++)
        for(int i=0; i<m; i++)
            sum_cols_mtx[i] += mtx[j*m + i];

    return sum_cols_mtx;


}
