#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <unistd.h>


int main() {
  int sum = 0;
  omp_lock_t lock;
  omp_init_lock(&lock);
  #pragma omp parallel for num_threads(32)
  for(int i = 0; i < 10000000; i++) {
    omp_set_lock(&lock);
    sum++;
    omp_unset_lock(&lock);
    // #pragma omp atomic
    // sum++;
  }

  omp_destroy_lock(&lock);
  printf("sum = %d\n", sum);
  return 0;
}
