
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <omp.h>

int x;

#pragma omp threadprivate(x)

int main() {
  int tid = omp_get_thread_num();
  omp_set_num_threads(5);
  x = 100;
  printf("before starting tid = %d x = %d\n", tid, x);
  // 这里不能使用 firstprivate 而是需要使用 copyin 
  #pragma omp parallel private(tid), copyin(x)
  {
    tid = omp_get_thread_num();
    printf("after starting tid = %d x = %d\n", tid, x);

  }
  return 0;
}