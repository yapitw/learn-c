#include <stdio.h>

int main() {
  int n[5];
  for (int i = 1; i <= 5; i++) {
    printf("%d: ", i);
    scanf("%d", &n[i - 1]);
  }

  int id;
  while (1) {
    printf("Q: ");
    scanf("%d", &id);
    if (id == 0) {
      break;
    } else if (id - 1 >= sizeof(n) / sizeof(n[0])) {
      printf("no data\n");
      continue;
    }
    printf("%d\n", n[id - 1]);
  }

  return 0;
}