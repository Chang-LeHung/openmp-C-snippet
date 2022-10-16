

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <unistd.h>


int main() {

  #pragma omp parallel num_threads(10)
  {
    if((omp_get_thread_num() & 1) == 0) {
      #pragma omp critical(A)
      {
        sleep(1);
        printf("tid = %d in if\n", omp_get_thread_num());
      }
    }else {
      #pragma omp critical(B)
      {
        sleep(1);
        printf("tid = %d in else\n", omp_get_thread_num());
      }
    }
  }

  return 0;
}