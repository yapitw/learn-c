#include <stdio.h>

int main() {
  int number = 1;
  int amount = 10;

  for (number = 1; amount > 0; number++) {
    if (number % 3 == 2 && number % 5 == 3 && number % 7 == 2) {
      printf("%d\n", number);
      amount--;
    }
  }

  return 0;
}