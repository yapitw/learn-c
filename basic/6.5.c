#include <stdio.h>

int main() {
  int a, b, c, t;
  printf("Please enter 3 numbers: ");
  scanf("%d%d%d", &a, &b, &c);
  printf("Before: %d %d %d\n", a, b, c);
  if (b < a) {
    t = b;
    b = a;
    a = t;
  }

  if (c < a) {
    t = c;
    c = a;
    a = t;
  }

  if (c < b) {
    t = c;
    c = b;
    b = t;
  }

  printf("After: %d %d %d\n", a, b, c);
  return 0;
}
