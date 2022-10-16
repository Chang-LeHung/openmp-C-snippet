

#include <stdio.h>
#include <omp.h>


int main() {
  omp_set_num_threads(4);

  #pragma omp parallel
  {
    printf("S\n");
    #pragma omp task
    printf("race(tid = %d)\n", omp_get_thread_num());
    printf("Car\n");
  }
  return 0;
}
