#include <stdio.h>
#include <time.h>

// 線性同餘法
// Linear congruential generator

static unsigned int _next = 1;

void srand(unsigned int seed) { _next = seed; }

int rand(void) {
  _next = _next * 1103515245 + 12345;
  return (unsigned int)(_next / 65536) % 32768;
}

int main() {
  srand(time(0));
  for (int i = 1; i < 5; i++) {
    printf("%u\n", rand());
  }
  return 0;
}