#include <stdio.h>
#include <omp.h>

int main(){
    int m = omp_get_thread_num();
    printf("thread=%d in serial region\n", m);
    
    #pragma omp parallel 
    {
        #pragma omp single
        {
            int s = omp_get_thread_num();
            printf("thread=%d in single region is creating tasks\n", s);
            
            #pragma omp taskloop num_tasks(3)
            for(int i=0; i<16; i++)
            {
                int t = omp_get_thread_num();
                printf("thread=%d executed iteration %d\n", t, i);
                
            } // implicit barrier here
        } // implicit barrier here
    } // implicit barrier here
    
    m = omp_get_thread_num();
    printf("thread=%d in serial region\n", m);
}