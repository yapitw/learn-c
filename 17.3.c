#include <stdio.h>

// 泡沫排序
// bubble sort

int main() {
  int i, j;
  int v[5];
  for (i = 0; i < 5; i++) {
    scanf("%d", &v[i]);
  }
  // int v[5] = {3, 2, 4, 1, 6};

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4 - i; j++) {
      if (v[j] > v[j + 1]) {
        int t = v[j];
        v[j] = v[j + 1];
        v[j + 1] = t;
      }
    }
  }

  for (i = 0; i < 5; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");

  return 0;
}