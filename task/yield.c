

#include <stdio.h>
#include <omp.h>
#include <unistd.h>

int main() {

  omp_set_num_threads(1);
  #pragma omp parallel
  {
    #pragma omp task
    {
      #pragma omp taskyield
      #pragma omp taskyield
      #pragma omp taskyield
      #pragma omp taskyield
      #pragma omp taskyield
      printf("Hello World from last task tid = %d\n", omp_get_thread_num());
    }

    #pragma omp task
    {
      // sleep(5);
      printf("Hello world tid = %d\n", omp_get_thread_num());
    }
  }

  return 0;
}