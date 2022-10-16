

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

#define len 1000000000L
#define num_thread 10

char data[len];

int sum;

void find_sum() {
  int my_id = omp_get_thread_num();
  int local_sum = 0;
  int size = len / num_thread;
  int start = my_id * size;
  int end = (my_id + 1) * size;
  for(int i = start; i < end; i++) {
    local_sum += (int)data[i];
  }

  #pragma omp critical
  sum += local_sum;
}

int main() {

  memset(data, 2, sizeof(data));
  #pragma omp parallel num_threads(num_thread)
  find_sum();
  printf("sum = %d\n", sum);
  return 0;
}
