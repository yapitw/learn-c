#include <stdio.h>
void f(int[]);

int main() {
  int v[3] = {1, 2, 3};
  printf("Size of int: %zu\n", sizeof(int));
  printf("Size of v[0]: %zu\n", sizeof(v[0]));
  printf("Size of v: %zu\n", sizeof(v));
  printf("Length of v: %zu\n", sizeof(v) / sizeof(v[0]));
  f(v);
  return 0;
}

void f(int v[]) {
  printf("Size of int: %zu\n", sizeof(int));
  printf("Size of v[0]: %zu\n", sizeof(v[0]));
  printf("Size of v: %zu\n", sizeof(v));
  printf("Length of v: %zu\n", sizeof(v) / sizeof(v[0]));
}