
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <omp.h>


int main(int argc, char* argv[]) {
  if (argc != 2)
  {
    fprintf(stderr, "argc != 2\n");
    exit(EXIT_FAILURE);
  }
  
  double pi = 0;
  double factor;
  int nproc = atoi(argv[1]);
  #pragma omp parallel for num_threads(nproc) reduction(+:pi) private(factor)
  for(int i = 0; i < 2000000000; i++) {
    if ((i & 1) == 0) // & 优先级比 == 低
      factor = 1.0;
    else
      factor = -1.0;
    pi += factor / (2 * i + 1);
    // printf("i = %d pi = %lf\n", i , pi);
  }

  printf("pi = %.10lf\n", 4 * pi);

  return 0;
}