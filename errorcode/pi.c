
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

int main() {

  double pi = 0;
  double factor;
  #pragma omp parallel for num_threads(32) private(factor) reduction(+:pi)
  for(int i = 0; i < 100000000; i++) {
    if ((i & 1) == 0)
      factor = 1;
    else
      factor = -1;
    pi += factor / (2 * i + 1);
  }
  printf("pi = %lf\n", pi * 4);
  return 0;
}