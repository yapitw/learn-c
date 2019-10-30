#include <stdio.h>
int main() {
  int count = 0;
  int *countAddress = &count;

  printf("Count: %d\n", count);
  printf("Count address: %u\n", countAddress);
  return 0;
}