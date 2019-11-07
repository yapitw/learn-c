#include <stdio.h>

// 用指標可以省去傳陣列大小參數，但陣列大小受限制，不同大小的陣列無法使用同一個函式。
void print(int (*q)[3]) {
  int i;
  for (i = 0; i < sizeof(*q) / sizeof((*q)[0]); i++) {
    printf("%d ", (*q)[i]);
  }

  printf("\n");
}

int main() {
  int v[] = {1, 2, 3};
  print(&v);

  return 0;
}