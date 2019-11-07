#include <stdio.h>

int main() {
  int sum, integer;
  printf("Please enter the first integer: ");
  scanf("%d", &integer);
  sum = integer;
  printf("Please enter the second integer: ");
  scanf("%d", &integer);
  sum = sum + integer;
  printf("Please enter the third integer: ");
  scanf("%d", &integer);
  sum = sum + integer;
  printf("Sum is %d.\n", sum);
  return 0;
}
