
#include <stdio.h>
#include <omp.h>
#include <string.h>
#include <stdlib.h>

int main() {
  int s = 1;
  #pragma omp parallel num_threads(5)
  for(int i = 0; i < 100; i++) {
    s++;
  }
  printf("s = %d\n", s);
  return 0;
}
