

#include <stdio.h>
#include <omp.h>

int main() {

  omp_set_num_threads(2);
  #pragma omp task
  {
    printf("task 1a tid = %d\n", omp_get_thread_num());
    #pragma omp critical
    {
      printf("task 1b tid = %d\n", omp_get_thread_num());
      #pragma omp task
      {
        printf("task 3 tid = %d\n", omp_get_thread_num());
      }
    }
  }

  #pragma omp task
  {
    #pragma omp critical
    {
      printf("task 2 tid = %d\n", omp_get_thread_num());
    }
  }
  return 0;
}