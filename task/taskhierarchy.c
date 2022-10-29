
#include <stdio.h>
#include <omp.h>
#include <unistd.h>


int main() {
  omp_set_num_threads(2);
  #pragma omp parallel
  {
    #pragma omp single
    {
      sleep(1);
      printf("starting to create task\n");
      int i = 1;
      #pragma omp task
      {
        printf("i = %d\n", i);
        printf("hello from pid = %d\n", omp_get_thread_num());
      }
    }
    #pragma omp task
    {
      printf("hello from pid = %d\n", omp_get_thread_num());
    }
  }
  return 0;
}