

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <omp.h>


int main() {

  int x = 5;
  #pragma omp parallel num_threads(10) default(none) private(x)
  {
    int rank = omp_get_thread_num();
    printf("Before tid = %d and x = %d\n", rank, x);
    x = rank * 2  + 1;
    printf("After tid = %d and x = %d\n", rank, x);
  }

  printf("final x = %d\n", x);
  return 0;
}
