
#include <stdio.h>
#include <string.h>
#include <omp.h>
#include <stdlib.h>
#include <unistd.h>


int main() {

  int sum = 0;
  #pragma omp parallel num_threads(5)
  {
    printf("hello from main tid = %d\n", omp_get_thread_num());
    sleep(5);
    #pragma omp for reduction(+:sum)
    for(int i = 0; i < 10; i++) {
      sum += i;
    }
  }
  printf("sum = %d\n", sum);
  return 0;
}
