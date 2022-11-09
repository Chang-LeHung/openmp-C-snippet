

#include <stdio.h>
#include <omp.h>

static int data = 2;

int main() {

  #pragma omp parallel num_threads(2) reduction(*:data)
  {
    printf("初始值 : data = %d tid = %d\n", data, omp_get_thread_num());
    if(omp_get_thread_num() == 0) {
      data = 10;
    }else if(omp_get_thread_num() == 1){
      data = 20;
    }
    printf("变化后的值 : data = %d tid = %d\n", data, omp_get_thread_num());
  }
  printf("规约之后的值 : data = %d\n", data);
  return 0;
}