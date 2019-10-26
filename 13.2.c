#include <stdio.h>
int sum(int);

int main() {
  int N;
  printf("N = ");
  scanf("%d", &N);

  printf("SUM = %d\n", sum(N));
  return 0;
}

int sum(int n) {
  if (n == 1) {
    return 1;
  } else {
    return sum(n - 1) + n;
  }
}