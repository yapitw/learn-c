#include <stdio.h>

// 線性同餘法
// Linear congruential generator

int main() {
  unsigned int next = 1;

  for (int i = 1; i < 10; i++) {
    next = next * 1103515245 + 12345;
    int rand = (unsigned int)(next / 65536) % 32768;
    printf("%u\n", rand);
  }
  return 0;
}