#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <omp.h>
#include <unistd.h>


int main() {

  #pragma omp parallel num_threads(3)
  {
    printf("start from tid = %d\n", omp_get_thread_num()); 
    #pragma omp single
    {
      int i = 0;
      while (i < 10)
      {
        usleep(500);
        i++;
        printf("hello from tid = %d\n", omp_get_thread_num());
      }
      
    }
    #pragma omp master
    printf("finish from tid = %d\n", omp_get_thread_num());
  }
  printf("finished\n");
  return 0;
}
