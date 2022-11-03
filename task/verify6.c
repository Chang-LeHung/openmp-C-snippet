

#include <omp.h>
#include <stdio.h>
#include <sys/types.h>


#define COLOR_NORMAL "\033[0m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_RED "\033[1;31m"
#define COLOR_GREY "\033[1;30m"

#define STACK_DEBUG printf("tid = %d"COLOR_RED" rsp = %lx"COLOR_NORMAL \
                            COLOR_GREEN" rbp = %lx"COLOR_NORMAL"\n", \
                            omp_get_thread_num(), rsp, rbp);

#define FIND_RSP_RBP \
        asm volatile(\
          "movq %%rbp, %0;"\
          "movq %%rsp, %1;"\
          :"=m"(rbp), "=m"(rsp)::\
        );
#define HLINE printf("===========================\n");
u_int64_t rsp;
u_int64_t rbp;

u_int64_t add_data;

int main() {

  #pragma omp parallel num_threads(1)
  {
    FIND_RSP_RBP

    STACK_DEBUG
    printf("This is outside top\n");
    HLINE

    #pragma omp task
    {
      printf("Enter task 1\n");
      FIND_RSP_RBP
      int data = 100;
      add_data = (u_int64_t)&data;
      printf("&data = %p\n", &data);
      STACK_DEBUG
      printf("yield in task 1\n");
      #pragma omp taskyield
      printf("Leave task 1\n");
      HLINE
    }

    #pragma omp task
    {
      printf("Enter task 2\n");
      FIND_RSP_RBP
      int data;
      *(int*)add_data = 431;
      printf("&data = %p\n", &data);
      STACK_DEBUG
      printf("yield in task 2\n");
      #pragma omp taskyield
      printf("Leave task 2\n");
      HLINE
      printf("In task 2 data = %d\n", data);
    }

    FIND_RSP_RBP

    STACK_DEBUG
    printf("This is outside down\n");
    HLINE
  }

  return 0;
}