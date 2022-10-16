

#include <stdio.h>
// #include <omp.h>
// #include <pthread.h>

// void process(int x) {
//   printf("x = %d tid = %d\n", x, omp_get_thread_num());
//   return;
// }

int main() {

  // #pragma omp parallel num_threads(2)
  // {
  //   for(int i = 0; i < 2; i++){
  //     #pragma omp task
  //     process(i);
  //   }
  //   process(10000);
  // }

  typedef struct
  {
    unsigned char _x[4] 
      __attribute__((__aligned__(16)));
  } omp_lock_t;

  printf("sizeof(omp_t) = %ld\n", sizeof(omp_lock_t));
  return 0;
}
 