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



void* sum_columns(void* thread_arg) { 

    tdata_t *thread_d = (tdata_t*) thread_arg;

    int size_work = 0, row_start = 0, row_end = 0;
    
    size_work = thread_d->nb_rows/thread_d->nb_threads;
    
    if(((thread_d->nb_rows % thread_d->nb_threads) != 0) && (thread_d->id_thread == 0))
        size_work += 1;
        
    row_start = thread_d->id_thread*size_work; 
    row_end = (thread_d->id_thread+1)*size_work;   

    if(((thread_d->nb_rows % thread_d->nb_threads) != 0) && (thread_d->id_thread != 0)){
        row_start += 1;
        row_end += 1;
    }

    printf("ID_THREAD %d, T_ID %d size_work %d row_start %d row_end %d\n", 
            (int)pthread_self(), thread_d->id_thread, size_work, row_start, row_end);

    for(int j=row_start; j<row_end; j++){
        for(int i=0; i<thread_d->nb_columns; i++){  
             thread_d->sum_cols[i] += thread_d->data_matrix[j*thread_d->nb_columns + i];
             printf("ROW %d : sum_cols[COLS : %d] %f\n", j, i, thread_d->sum_cols[i]);
        }
    }
} 

void matrix::sum_cols_matrix_pthreads(){

    pthread_t threads[nb_threads];

    tdata_t thr_data[nb_threads];

    for(int j=0; j<nb_threads; j++){
        
        float* sum_cols = NULL;
        if((sum_cols = (float*)malloc(m*sizeof(float))) == NULL){
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
    for(int k=0; k<m; k++){
        printf("sum_total %f ", sum_cols_mtx[k]); 
    }
    printf("\n");
   
}


void matrix::memset_sum_cols_mtx(){
    memset(sum_cols_mtx, 0, sizeof(float)*m);
}