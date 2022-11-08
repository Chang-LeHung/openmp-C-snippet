

#include <stdio.h>
#include <omp.h>
#include <unistd.h>

static int data;

static int tarr[2];

int main() {
  #pragma omp parallel num_threads(2)
  {
    int tid = omp_get_thread_num();
    for(int i = 0; i < 10000; i++) {
      tarr[tid]++;
      usleep(10);
    }
    printf("tarr[%d] = %d tid = %d\n", tid, tarr[tid], tid);
  }
  data = tarr[0] + tarr[1];
  printf("In main function data = %d\n", data);
  return 0;
}