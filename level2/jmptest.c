
#include <stdio.h>
#include <setjmp.h>

jmp_buf env;

void bb(double b) {
  b = 123.123;
  printf("b = %lf\n", b);
  longjmp(env, 100);
}

void aa(double a) {

  printf("a = %lf\n", a);
  int b;
  if(!(b = setjmp(env))) {
    bb(a);
  }else{
    printf("a = %lf b = %d\n", a, b);
  }
}

int main() {
  aa(321.321);
  return 0;
}