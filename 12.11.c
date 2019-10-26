#include <limits.h>
#include <stdio.h>

int main() {
  unsigned int a = 1000;
  unsigned int b = a * a * a;
  unsigned int c = a * a * a * a;
  printf("%u\n", b);
  printf("%u\n", c); // 1000000000000 % (UINT_MAX + 1)
  printf("%u\n", UINT_MAX);

  return 0;
}