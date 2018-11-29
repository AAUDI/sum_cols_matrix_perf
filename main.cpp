#include <iostream>
#include "matrix.hpp"
#include "matrix_template.hpp"

void printHelpAndExitVersion1(){
    std::cerr << "Usage : ./main.bin NB_ROWS_MATRIX NB_COLUMNS_MATRIX" << std::endl;
    exit(-1);
}

void printHelpAndExitVersion2Optim(){
    std::cerr << "Usage : ./main.bin NB_ROWS_MATRIX NB_COLUMNS_MATRIX NB_THREADS" << std::endl;
    exit(-1);
}


int main(int argc, char **argv) {


    #if defined(VERSION1) || defined (VERSION2)
    if(argc != 3)
        printHelpAndExitVersion1();
    #endif

    #if defined (VERSION2_OPENMP) || defined (VERSION2_PTHREADS)
    if(argc != 4)
        printHelpAndExitVersion2Optim();
    #endif

    int nb_rows_matrix = atoi(argv[1]);
    int nb_cols_matrix = atoi(argv[2]);

    #if defined (VERSION1) || defined(VERSION2)
    printf("NB_ROWS_MATRIX %d NB_COLUMNS_MATRIX %d\n", nb_rows_matrix, nb_cols_matrix);
    #endif

    #if defined (VERSION2_OPENMP) || defined(VERSION2_PTHREADS)
     int nb_threads = atoi(argv[3]);
    printf("NB_ROWS_MATRIX %d NB_COLUMNS_MATRIX %d NB_THREADS %d\n", nb_rows_matrix, nb_cols_matrix, nb_threads);
    #endif
    

/* ********************************* Only floating type and addition operation ********************************** */ 

     /* VERSION  1 */
    #ifdef VERSION1
    matrix m0(nb_cols_matrix, nb_rows_matrix, 0.0, 10.0);
    m0.sum_cols_matrix_v1();
    m0.memset_sum_cols_mtx();
    #endif

    //  /* VERSION  2 */
    // #ifdef VERSION2
    // matrix m(nb_cols_matrix, nb_rows_matrix, 0.0, 10.0);
    // m.sum_cols_matrix_v2();
    // m.memset_sum_cols_mtx();
    // #endif

    // /* OPENMP VERSION 2 */
    // #ifdef VERSION2_OPENMP
    // matrix m(nb_cols_matrix, nb_rows_matrix, nb_threads, 0.0, 10.0);
    // m.sum_cols_matrix_openmp_v2();
    // m.memset_sum_cols_mtx();
    // #endif

    // /* PTHREADS VERSION 2 */
    // #ifdef VERSION2_PTHREADS
    // matrix m(nb_cols_matrix, nb_rows_matrix, nb_threads, 0.0, 10.0);
    // m.sum_cols_matrix_pthreads_v2();
    // m.memset_sum_cols_mtx();
    // #endif



/* ************************************************* Using Templates ************************************************* */ 
    #ifdef VERSION2
    matrix_template<int> m2(nb_cols_matrix, nb_rows_matrix, 0, 10);
    //m.print_matrix();
    +m2;
    m2.print_op_cols_mtx();
    m2.memset_op_cols_mtx();  
    -m2;
    m2.print_op_cols_mtx();
    m2.memset_op_cols_mtx();
    *m2;
    m2.print_op_cols_mtx();
    m2.memset_op_cols_mtx();
    #endif

    #if defined (VERSION2_OPENMP) || defined(VERSION2_PTHREADS)
    matrix_template<int> m(nb_cols_matrix, nb_rows_matrix, nb_threads, 0, 10);
    //m.print_matrix();
    +m;
    m.print_op_cols_mtx();
    m.memset_op_cols_mtx();   
    -m;
    m.print_op_cols_mtx();
    m.memset_op_cols_mtx();
    *m;
    m.print_op_cols_mtx();
    m.memset_op_cols_mtx();
    #endif



    return 1;
}
