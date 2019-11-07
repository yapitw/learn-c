#include <stdio.h>

int main() {
  int N;
  printf("N = ");
  scanf("%d", &N);
  int i, j;
  for (i = 1; i <= N; ++i) {
    for (j = 1; j <= N; ++j) {
      // printf("(%d,%d)", i, j);
      // if (i >= j && (j == 1 || j == i || i == N)) {
      if (j + i == N + 1 || i == N || j == N) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}