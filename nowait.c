

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>

int main() {

  #pragma omp parallel num_threads(10)
  {
    int id = omp_get_thread_num();
    #pragma omp barrier

    #pragma omp nowait
    {
      sleep(id);
    }
    printf("tid = %d\n", id);
  }
  return 0;
}