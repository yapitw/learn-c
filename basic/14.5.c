#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0));
  int counter[11] = {0};
  int i;
  for (i = 1; i <= 100000; i++) {
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;
    int sum = dice1 + dice2;
    counter[sum - 2]++;
  }

  for (int j = 0; j < 11; j++) {
    printf("SUM-%d: %d\n", j + 2, counter[j]);
  }

  return 0;
}