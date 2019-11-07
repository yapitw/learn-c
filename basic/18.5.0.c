#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0));
  int v[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  int i, j, k = 0;

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      int r = rand() % (9 - k) + k;
      int m = r / 3;
      int n = r % 3;
      int t = v[i][j];
      v[i][j] = v[m][n];
      v[m][n] = t;
      k++;
    }
  }

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%d ", v[i][j]);
    }
    printf("\n");
  }

  return 0;
}