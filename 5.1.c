#include <stdio.h>

int main() {
  int a, b, c, max;
  printf("Please enter three integer: ");
  scanf("%d%d%d", &a, &b, &c);

  max = a;
  if (max < b) {
    max = b;
  }
  if (max < c) {
    max = c;
  }

  printf("The maximum is %d. \n", max);
  return 0;
}