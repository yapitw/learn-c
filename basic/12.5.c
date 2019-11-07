#include <stdio.h>
int max3(int, int, int);

int main() {
  int a, b, c;
  printf("Please enter three integer: ");
  scanf("%d%d%d", &a, &b, &c);
  printf("The maximum is %d. \n", max3(a, b, c));
  return 0;
}

// int max3(int a, int b, int c) {
//   int max;
//   max = a;
//   if (max < b) {
//     max = b;
//   }
//   if (max < c) {
//     max = c;
//   }
//   return max;
// }

int max3(int a, int b, int c) { return max2(max2(a, b), c); }

int max2(int a, int b) {
  if (a >= b) {
    return a;
  } else {
    return b;
  }
}