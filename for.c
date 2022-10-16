

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <omp.h>


char data[1000];

int main() {

  int sum = 0;
  memset(data, 1, sizeof(data));

  #pragma omp parallel for num_threads(5)
  for(int i = 0; i < 42; i++) {
    printf("tid = %d i = %d\n", omp_get_thread_num(), i);
    #pragma critical
    sum += data[i];
  }

  printf("sum = %d\n", sum);
  printf("%d\n", _OPENMP);
  return 0;
}
