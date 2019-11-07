#include <stdio.h>
void swap(int *, int *);

int main() {
  int a = 3;
  int b = 4;
  swap(&a, &b);
  printf("a: %d\n", a);
  printf("b: %d\n", b);
  return 0;
}

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}