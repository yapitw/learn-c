#include <stdio.h>
int max2(int, int);

int main() {
  int a, b;
  printf("Please enter two integer: ");
  scanf("%d%d", &a, &b);
  printf("The maximum is %d. \n", max2(a, b));
  return 0;
}

int max2(int a, int b) {
  if (a >= b) {
    return a;
  } else {
    return b;
  }
}