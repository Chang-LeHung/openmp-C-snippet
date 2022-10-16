
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <omp.h>
#include <unistd.h>


int x = 1024;

#pragma omp threadprivate(x)

int main() {

  omp_set_num_threads(10);

  #pragma omp parallel 
  {
      sleep(1);
    #pragma omp single copyprivate(x)
    {
      printf("tid = %d\n", omp_get_thread_num());
      x = omp_get_thread_num();
    }
    printf("tid = %d x = %d\n", omp_get_thread_num(), x);
  }

  return 0;
}