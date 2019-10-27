#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0));
  int counter[6] = {0};
  for (int i = 1; i <= 6000; i++) {
    int dice = rand() % 6 + 1;
    counter[dice - 1]++;
  }

  for (int d = 1; d <= 6; d++) {
    printf("DICE-%d: %d\n", d, counter[d - 1]);
  }
}