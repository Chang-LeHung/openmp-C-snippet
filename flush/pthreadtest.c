

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <omp.h>

volatile int data = 1;
volatile int sum;

void* func1() {
  for (size_t i = 0; i < 100000000; i++)
  {
    sum++;
  }
  printf("num threads = %d\n", omp_get_num_threads());
  data = 0;
  printf("func1 finished~\n");
}

void* func2() {
  while (data)
  {
    //  __asm__ volatile ("lock; addl $0,0(%%rsp)" : : : "cc", "memory");
    // asm volatile("sfence":::"memory");
    // asm volatile("lfence":::"memory");
    // asm volatile("mfence":::"memory");
  }
  printf("func2 finished~\n");
}

int main() {
  pthread_t t1, t2;
  pthread_create(&t1, NULL, func1, NULL);
  pthread_create(&t2, NULL, func2, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  return 0;
}
