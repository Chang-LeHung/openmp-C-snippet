
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <unistd.h>
long sum = 0;

void add() {
  for(int i = 0; i < 100000; i++) {
    sum++;
  }
}

int main() {

  #pragma omp parallel for num_threads(32)
  for(long i = 0;  i < 1000000000; i++) {
      #pragma omp atomic
      sum++;
  }
  printf("sum = %ld\n", sum);
  return 0;
}
