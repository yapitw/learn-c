#include <stdio.h>

int main() {
  int a, b, t;
  printf("Please enter 2 numbers: ");
  scanf("%d%d", &a, &b);

  if (a > b) {
    t = a;
    a = b;
    b = t;
  }

  printf("After: %d %d\n", a, b);
  return 0;
}
