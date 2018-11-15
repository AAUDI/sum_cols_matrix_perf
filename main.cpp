#include "matrix.hpp"
#include <iostream>
#include "OpenMPTimer.h"

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

    matrix m(nb_rows_matrix, nb_cols_matrix);
    //m.print_matrix();
    
    OpenMPTimer t_sum_cols_matrix;
    t_sum_cols_matrix.start();
    m.sum_cols_matrix_v1();
    t_sum_cols_matrix.stop();
    printf("time t_sum_cols_matrix V1 %lf\n", t_sum_cols_matrix.elapsed());
    t_sum_cols_matrix.reset();

    t_sum_cols_matrix.start();
    m.sum_cols_matrix_v2();
    t_sum_cols_matrix.stop();
    printf("time t_sum_cols_matrix V2 %lf\n", t_sum_cols_matrix.elapsed());
    t_sum_cols_matrix.reset();

    //m.print_sumcols_matrix();

    return 1;
}
