#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);
  int number;
  for (number = 1; number <= N; number++) {
    if (N % number == 0) {
      printf("%d ", number);
    }
  }

  printf("\n");
  return 0;
}