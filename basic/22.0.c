#include <stdio.h>
void addone(int *n) {
  *n = *n + 1;
}

int main() {
  int a = 3;
  addone(&a);
  printf("%d\n", a);
  return 0;
}
