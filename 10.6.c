#include <stdio.h>

int main() {
  int N;
  printf("N = ");
  scanf("%d", &N);

  int isPrime = 1;
  int number;
  for (number = 2; number < N && isPrime; ++number) {
    if (N % number == 0) {
      isPrime = 0;
    }
  }

  printf(isPrime ? "Yes \n" : "No \n");

  return 0;
}
