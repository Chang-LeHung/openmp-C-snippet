
#include <stdio.h>
#include <omp.h>

int x = 100;

#pragma omp threadprivate(x)

void test() {
  printf("In test x = %d tid = %d\n", x, omp_get_thread_num());
}

int main() {

  #pragma omp parallel num_threads(2)
  {
    printf("x = %d tid = %d\n", x, omp_get_thread_num());
    x = omp_get_thread_num();
    test();
  }
  return 0;
}