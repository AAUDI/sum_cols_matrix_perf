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

//row major access
void matrix::sum_cols_matrix_v2(){

    for(int j=0; j<n; j++)
        for(int i=0; i<m; i++)
            sum_cols_mtx[i] += mtx[j*m + i];
    print_sumcols_matrix(sum_cols_mtx);
}

//row major access
void matrix::sum_cols_matrix_openmp_v2(){

    int i=0, j=0;
 
    #pragma omp parallel num_threads(nb_threads)
    {
        float sum_cols_mtx_private[m] = {0};
        #pragma omp for private(i) schedule(static)
        for(j=0; j<n; j++){
            for(i=0; i<m; i++){
                sum_cols_mtx_private[i] += mtx[j*m + i]; 
            }
        }
        #pragma omp critical
        {
            for(i=0; i<m; i++){
                sum_cols_mtx[i] += sum_cols_mtx_private[i];
            }
        }
    }
    print_sumcols_matrix(sum_cols_mtx);
}



void* sum_columns(void* thread_arg) { 

    struct thread_data *thread_d = (struct thread_data*) thread_arg;

    int size_work = 0, rest_work, row_start = 0, row_end = 0;
    
    size_work = thread_d->nb_rows/thread_d->nb_threads;
    rest_work = thread_d->nb_rows%thread_d->nb_threads;

    
    if((rest_work != 0) && (thread_d->id_thread == 0)){
        size_work += rest_work;
    }
        
    row_start = thread_d->id_thread*size_work; 
    row_end = (thread_d->id_thread+1)*size_work;   


    if((rest_work != 0) && (thread_d->id_thread != 0)){
        row_start += rest_work;
        row_end += rest_work;
    }

    //printf("ID_THREAD %d, T_ID %d size_work %d row_start %d row_end %d\n", 
    //        (int)pthread_self(), thread_d->id_thread, size_work, row_start, row_end);

    for(int j=row_start; j<row_end; j++){
        for(int i=0; i<thread_d->nb_columns; i++){  
             thread_d->sum_cols[i] += thread_d->data_matrix[j*thread_d->nb_columns + i];
            //printf(" THREAD_ID %d ROW %d :sum_cols[COLS : %d] %f\n", thread_d->id_thread, j, i, thread_d->sum_cols[i]);
        }
    }
} 

void matrix::sum_cols_matrix_pthreads_v2(){

    pthread_t threads[nb_threads];
    struct thread_data thr_data[nb_threads];
    
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
        //printf("End of thread ID : %d\n", (int)threads[j]);
    }   
    
    for(int j=0; j<nb_threads; j++){
        for(int k=0; k<m; k++){
            sum_cols_mtx[k] += thr_data[j].sum_cols[k];
        }
    }
    
    for(int j=0; j<nb_threads; j++){
        free(thr_data[j].sum_cols);
    }
   
}


void matrix::memset_sum_cols_mtx(){
    memset(sum_cols_mtx, 0, sizeof(float)*m);
}