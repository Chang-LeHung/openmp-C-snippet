
#include <stdio.h>
#include <omp.h>


int main() {

  omp_set_num_threads(4);
  #pragma omp parallel
  {
    printf("hello from tid = %d\n", omp_get_thread_num());
  }
  return 0;
}