
#include <stdio.h>
#include <string.h>
#include <omp.h>
#include <stdio.h>


int main() {

  omp_set_num_threads(5);
  #pragma omp parallel
  {
    printf("tid = %d\n", omp_get_thread_num());
  }
  return 0;
}