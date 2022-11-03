

#include <stdio.h>
#include <omp.h>
#include <sys/types.h>

#define COLOR_NORMAL "\033[0m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_RED "\033[1;31m"
#define COLOR_GREY "\033[1;30m"
#define COLOR_BLUE "\033[1;34m"

#define STACK_DEBUG printf("tid = %d"COLOR_RED" rsp = %lx"COLOR_NORMAL \
                            COLOR_GREEN" rbp = %lx"COLOR_BLUE" stack size = %ld bytes"COLOR_NORMAL"\n", \
                            omp_get_thread_num(), rsp, rbp, rbp - rsp);


#define FIND_RSP_RBP \
        asm volatile(\
          "movq %%rbp, %0;"\
          "movq %%rsp, %1;"\
          :"=m"(rbp), "=m"(rsp)::\
        );
#define HLINE printf("===========================\n");

#define DEBUG FIND_RSP_RBP \
              STACK_DEBUG   \
              HLINE
u_int64_t rsp;
u_int64_t rbp;


int main() {

  #pragma omp parallel num_threads(1)
  {
    #pragma omp task
    {
      printf("In task 1\n");
      DEBUG
      #pragma omp task
      {
        printf("In task 2\n");
        DEBUG
        #pragma omp task
        {
          printf("In task 3\n");
          DEBUG
          #pragma omp task
          {
            int s[5000];
            for(int i = 0; i < 5000; i++)
              s[i] = 1;
            printf("In task 3\n");
            DEBUG
          }
        }
        printf("Out task 2\n");
        DEBUG
      }
      printf("Out task 1\n");
      DEBUG
    }
  }
  return 0;
}