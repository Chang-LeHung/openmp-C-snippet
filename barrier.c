
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <unistd.h>


int main() {

  #pragma omp parallel num_threads(5)
  {
    int s = rand() % 10;
    sleep(s);
    #pragma omp barrier
    printf("tid = %d free\n", omp_get_thread_num());
  }

  return 0;
}