

#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  int x = 100;

  #pragma omp parallel num_threads(10) firstprivate(x)
  {
    printf("x = %d tid = %d\n", x, omp_get_thread_num());
  }
  return 0;
}