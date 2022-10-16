#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

int main() {
  int result = -3;
  char arr[10];
  memset(arr, 1, sizeof(arr));
  // 当为 * 的时候 则进行连乘
  #pragma omp parallel for num_threads(5) reduction(*:result)
  for(int i = 1; i <= 10; i++) {
    result = i ;
    printf("i = %d tid = %d result = %d\n", i, omp_get_thread_num(), result);
  }

  printf("result = %d\n", result);
  return 0;
}


  // #pragma omp parallel num_threads(10) reduction(+:result)
  // for(int i = 0; i <= 100; i++) {
  //   result += i ;
  // }
