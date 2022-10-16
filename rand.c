
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int s = rand();
  printf("s = %d\n", s);
  return 0;
}