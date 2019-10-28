#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, q, n[10];
  for (i = 1; i <= 10; i++) {
    scanf("%d", &n[i - 1]);
  }
  while (1) {
    printf("Q: ");
    scanf("%d", &q);
    if (q == 0) {
      break;
    }
    int nearest_n = n[0], nearest_d = abs(q - n[0]);
    for (i = 1; i < 10; i++) {
      int d = abs(q - n[i]);
      if (d < nearest_d || (d == nearest_d && n[i] < nearest_n)) {
        nearest_d = d;
        nearest_n = n[i];
      }
    }
    printf("%d\n", nearest_n);
  }
  return 0;
}