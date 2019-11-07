#include <stdio.h>

int main() {
  int N;
  printf("Please enter the number: ");
  scanf("%d", &N);
  int number = 0;
  while (number < N) {
    number++;
    printf("%d\n", number);
  }
  return 0;
} 