

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <omp.h>

int main() {
  char buf[1024];
  int n = omp_get_affinity_format(buf, 1024);
  #pragma omp parallel num_threads(5)
  {
    omp_display_affinity(NULL);
  }
  return 0;
}