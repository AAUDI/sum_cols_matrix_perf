#include "matrix.hpp"
#include <iostream>
#include "OpenMPTimer.h"
#include "matrix_template.hpp"

void printHelpAndExit()
{
    std::cerr << "Usage : ./main.bin NB_ROWS_MATRIX NB_COLUMNS_MATRIX NB_THREADS" << std::endl;
    exit(-1);
}



int main(int argc, char **argv) {


    if(argc != 4)
        printHelpAndExit();

    int nb_rows_matrix = atoi(argv[1]);
    int nb_cols_matrix = atoi(argv[2]);
    int nb_threads = atoi(argv[3]);

    printf("NB_ROWS_MATRIX %d NB_COLUMNS_MATRIX %d NB_THREADS %d\n", nb_rows_matrix, nb_cols_matrix, nb_threads);

    // matrix m(nb_cols_matrix, nb_rows_matrix, nb_threads);
    // m.print_matrix();
    // printf("--------------------------------------------------------------------------------\n");
    // printf("\n");
    // printf("\n");
    // printf("\n");
    // printf("\n");
    
    // OpenMPTimer t_sum_cols_matrix;
    
    
    // printf("------------------------- SUM COLS MATRIX COLUMN MAJOR -------------------------\n");
    // t_sum_cols_matrix.start();
    // m.sum_cols_matrix_v1();
    // t_sum_cols_matrix.stop();
    // printf("TIME %lf\n", t_sum_cols_matrix.elapsed());
    // t_sum_cols_matrix.reset();
    // printf("--------------------------------------------------------------------------------\n");
    // printf("\n");
    // printf("\n");
    // printf("\n");
    // printf("\n");
    // m.memset_sum_cols_mtx();
    // m.sum_cols_matrix_pthreads();

    // printf("----------------------- SUM COLS MATRIX OPENMP COLUMN MAJOR -----------------------\n");
    // t_sum_cols_matrix.start();
    // m.sum_cols_matrix_openmp_v1();
    // t_sum_cols_matrix.stop();
    // printf("TIME %lf\n", t_sum_cols_matrix.elapsed());
    // t_sum_cols_matrix.reset();
      
    // printf("--------------------------------------------------------------------------------\n");
    // printf("\n");
    // printf("\n");
    // printf("\n");
    // printf("\n");
    // m.memset_sum_cols_mtx();

    // printf("--------------------------- SUM COLS MATRIX ROW MAJOR --------------------------\n");
    // t_sum_cols_matrix.start();
    // m.sum_cols_matrix_v2();
    // t_sum_cols_matrix.stop();
    // printf("TIME %lf\n", t_sum_cols_matrix.elapsed());
    // t_sum_cols_matrix.reset();


    // printf("--------------------------------------------------------------------------------\n");
    // printf("\n");
    // printf("\n");
    // printf("\n");
    // printf("\n");
    // m.memset_sum_cols_mtx();
    // printf("----------------------- SUM COLS MATRIX OPENMP ROW MAJOR -----------------------\n");
    // t_sum_cols_matrix.start();
    // m.sum_cols_matrix_openmp_v2();
    // t_sum_cols_matrix.stop();
    // printf("TIME %lf\n", t_sum_cols_matrix.elapsed());
    // t_sum_cols_matrix.reset();
    // printf("--------------------------------------------------------------------------------\n");
    // m.memset_sum_cols_mtx();

    // #ifdef NO_OPENMP_GPU
    // matrix_template<float> m(nb_cols_matrix, nb_rows_matrix, 0.0, 100.0);
    // #endif

    #if defined (OPENMP) || defined(PTHREADS)
    matrix_template<float> m(nb_cols_matrix, nb_rows_matrix, nb_threads, 0.0, 100.0);
    

    m.print_matrix();
     
    +m;
    m.print_op_cols_mtx();
    m.memset_op_cols_mtx();
    #endif
    
    // -m;
    // //m.print_op_cols_mtx();
    // m.memset_op_cols_mtx();
    // *m;
    // //m.print_op_cols_mtx();
    // m.memset_op_cols_mtx();
    // m/1;
    // //m.print_op_cols_mtx();
    // m.memset_op_cols_mtx();

    return 1;
}
