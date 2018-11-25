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



/* ******************************* RANDOM MATRIX ******************************* */ 
    #ifdef NO_OPENMP_GPU
    matrix_template<int> m(nb_cols_matrix, nb_rows_matrix, 0.0, 100.0);
    //m.print_matrix();
    +m;

    m.print_op_cols_mtx();
    m.memset_op_cols_mtx();  
    //-m;
    //m.print_op_cols_mtx();
    //m.memset_op_cols_mtx();
    //*m;
    //m.print_op_cols_mtx();
    //m.memset_op_cols_mtx();
    #endif

    #if defined (OPENMP) || defined(PTHREADS)
    matrix_template<int> m(nb_cols_matrix, nb_rows_matrix, nb_threads, 0.0, 100.0);
    //m.print_matrix();
    +m;
    m.print_op_cols_mtx();
    m.memset_op_cols_mtx();   
    // -m;
    // m.print_op_cols_mtx();
    // m.memset_op_cols_mtx();
    // *m;
    // m.print_op_cols_mtx();
    // m.memset_op_cols_mtx();
    #endif
    return 1;
}
