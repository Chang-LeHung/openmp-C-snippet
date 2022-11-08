
#include <stdio.h>
#include <omp.h>
#include <unistd.h>

static int data;

int main() {
  #pragma omp parallel num_threads(2) shared(data) default(none)
  {
    for(int i = 0; i < 10000; i++) {
      data++;
      usleep(10);
    }
    printf("data = %d tid = %d\n", data, omp_get_thread_num());
  }

  printf("In main function data = %d\n", data);
  return 0;
}