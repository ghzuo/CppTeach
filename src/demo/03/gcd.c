#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
  while (a != b) {
    if (a > b)
      a = a - b;
    else
      b = b - a;
  }
  return a;
}

int main(int argc, char *argv[]) {
  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  printf("The GCD of [%d] and [%d] is: %d\n", a, b, gcd(a, b));
}
