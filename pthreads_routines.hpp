#ifndef PTHREADS_ROUTINE
#define PTHREADS_ROUTINE

#ifdef PTHREADS
template <typename T>
struct thread_data_t{
    int id_thread;
    int nb_rows;
    int nb_columns; 
    int nb_threads;
    T* data_matrix;
    T* op_cols;
};
#endif


#ifdef PTHREADS

template <typename T>
void* op_columns(void* thread_arg);


template <typename T>
void* op_sum_columns(void* thread_arg) { 

    struct thread_data_t<T> *thread_d = (struct thread_data_t<T>  *) thread_arg;

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
             thread_d->op_cols[i] += thread_d->data_matrix[j*thread_d->nb_columns + i];
            //printf(" THREAD_ID %d ROW %d :sum_cols[COLS : %d] %f\n", thread_d->id_thread, j, i, thread_d->op_cols[i]);
        }
    }
} 


template <typename T>
void* op_sub_columns(void* thread_arg) { 

    struct thread_data_t<T> *thread_d = (struct thread_data_t<T>  *) thread_arg;

    int size_work = 0, rest_work = 0, row_start = 0, row_end = 0;
    
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

    if(thread_d->id_thread == 0){
        for(int k=0; k<thread_d->nb_columns; k++){
            thread_d->op_cols[k] = thread_d->data_matrix[row_start*thread_d->nb_columns + k];
        }
    }

    if(thread_d->id_thread != 0){
        for(int k=0; k<thread_d->nb_columns; k++){
            thread_d->op_cols[k] = -thread_d->data_matrix[row_start*thread_d->nb_columns + k];
        }
    }
 
    //printf("ID_THREAD %d, T_ID %d size_work %d row_start %d row_end %d\n", 
    //        (int)pthread_self(), thread_d->id_thread, size_work, row_start, row_end);

   
    for(int j=row_start+1; j<row_end; j++){
        for(int i=0; i<thread_d->nb_columns; i++){  
            thread_d->op_cols[i] -= thread_d->data_matrix[j*thread_d->nb_columns + i];
            //printf(" THREAD_ID %d ROW %d :sum_cols[COLS : %d] %f\n", thread_d->id_thread, j, i, thread_d->op_cols[i]);
        }
    }
} 


template <typename T>
void* op_mul_columns(void* thread_arg) { 

    struct thread_data_t<T> *thread_d = (struct thread_data_t<T>  *) thread_arg;

    int size_work = 0, rest_work = 0, row_start = 0, row_end = 0;
    
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

    //printf("ID_THREAD %d, THREAD_ID %d size_work %d row_start %d row_end %d\n", 
    //        (int)pthread_self(), thread_d->id_thread, size_work, row_start, row_end);

    for(int j=row_start; j<row_end; j++){
        for(int i=0; i<thread_d->nb_columns; i++){  
             thread_d->op_cols[i] *= thread_d->data_matrix[j*thread_d->nb_columns + i];
             //printf(" THREAD_ID %d ROW %d : mul_cols[COLS : %d] %f\n", thread_d->id_thread, j, i, thread_d->op_cols[i]);
        }
    }
} 


#endif



#endif
