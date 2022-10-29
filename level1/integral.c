

#include <stdio.h>
#include <omp.h>
#include <math.h>

double x_square_partial_integral(double start, double end, double delta) {

  double s = 0;
  for(double i = start; i < end; i += delta) {
    s += pow(i, 2) * delta;
  }
  return s;
}

int main() {

  int s = 0;
  int e = 100;
  double sum = 0;
  #pragma omp parallel num_threads(4) reduction(+:sum)
  {
    double start = (double)(e - s) / 4 * omp_get_thread_num();
    double end   = (double)(e - s) / 4 * (omp_get_thread_num() + 1);
    sum = x_square_partial_integral(start, end, 0.0000001);
  }
  printf("sum = %lf\n", sum);
  return 0;
}