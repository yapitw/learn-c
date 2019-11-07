#include <stdio.h>

void print(int *v, int width, int height) {
  int i, j;
  for (i = 0; i < height; i++) {
    for (j = 0; j < 3; j++) {
      printf("%d ", v[i * width + j]);
    }
    printf("\n");
  }
}

int main() {
  int v[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  print((int *)v, 3, 3); // 強制轉型成一維陣列
  return 0;
}