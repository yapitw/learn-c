#include <stdio.h>

void print(int **p, int height) {
  int i, j;
  for (i = 0; i < height; i++) {
    for (j = 0; j < 3; j++) {
      printf("%d ", p[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int v[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int *p[3] = {v[0], v[2], v[1]}; // p 可以改變 v 陣列的順序
  print(p, 3);
  return 0;
}