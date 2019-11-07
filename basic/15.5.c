
#include <stdio.h>

int main() {
  int i, j, n, b[10] = {0};
  for (i = 1; i <= 10; i++) {
    scanf("%d", &n);
    b[(n - 1) / 10]++;
  }

  for (i = 1; i <= 10; i++) {
    printf("%3d: ", i * 10);
    for (j = 1; j <= b[i - 1]; j++) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}