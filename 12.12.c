#include <stdio.h>
#include <time.h>

// 線性同餘法
// Linear congruential generator

unsigned int SEED = 1;

void srand(unsigned int seed) { SEED = seed; }

unsigned int rand(void) {
  static unsigned int N = 0;
  unsigned int x = ((N + SEED) * 1103515245 + 12345) % 4294967296;
  N++;
  return x;
}

int main() {
  srand(time(0));
  for (int i = 1; i < 10; i++) {
    printf("%u\n", rand());
  }
  return 0;
}