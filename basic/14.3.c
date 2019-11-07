#include <stdio.h>
// #include <stdlib.h>

int main() {
  int v[] = {3, 5, 0, 10, 3, 8, 12, 1};
  int i;
  int max = v[0];
  int length = sizeof(v) / sizeof(v[0]);
  for (i = 1; i <= length - 1; i++) {
    if (v[i] > max) {
      max = v[i];
    }
  }
  printf("MAX = %d\n", max);
  return 0;
}