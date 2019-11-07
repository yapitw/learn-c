#include <stdio.h>

int main() {
  int v[5] = {1, 2, 3, 4, 5};
  int *n;
  for (n = v; n != &v[5]; n++) {
    printf("%d\n", *n);
  }
  return 0;
}