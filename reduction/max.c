

#include <stdio.h>
#include <omp.h>

static int data = 1000;

int main() {

  #pragma omp parallel num_threads(2) reduction(max:data)
  {
    printf("data = %d tid = %d\n", data, omp_get_thread_num());
    if(omp_get_thread_num() == 0) {
      data = 10;
    }else if(omp_get_thread_num() == 1){
      data = 20;
    }
  }
  printf("data = %d\n", data);
  return 0;
}