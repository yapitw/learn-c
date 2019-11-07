#include <stdio.h>

int main() {
  int i, j;

  for (i = 1; i <= 30 / 2; ++i) {
    // for (j = 30 / 2; j <= 30; ++j) {
    //   if (i + j == 30 && i * j == 221) {
    //     printf("%d, %d\n", i, j);
    //   }
    // }

    j = 30 - i;
    if (i * j == 221) {
      printf("%d, %d\n", i, j);
    }
  }

  return 0;
}
