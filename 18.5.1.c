#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0));
  int v[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int i;

  for (i = 0; i < 9; i++) {
    int r = rand() % (9 - i) + i;
    int t = v[r];
    v[r] = v[i];
    v[i] = t;
  }

  for (i = 0; i < 9; i++) {
    printf("%d ", v[i]);
    if (i % 3 == 2) {
      printf("\n");
    }
  }

  return 0;
}