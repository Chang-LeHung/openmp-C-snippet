
#include <stdio.h>
#include <omp.h>

int fib(int n) {
  if (n < 2) return n;
  int i, j;
  {
    #pragma omp task shared(i)
    i = fib(n - 1);
    #pragma omp task shared(j)
    j = fib(n - 2);
    #pragma omp taskwait
  }
  return i + j;
}


int main() {

  omp_set_num_threads(4);
  #pragma omp parallel
  {
    #pragma omp single
    {
      int rs = fib(38);
      printf("result = %d\n", rs);
    }
  }
  return 0;
}