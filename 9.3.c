#include <stdio.h>

int main() {
  int count;
  for (count = 1; count <= 20; count++) {
    if (count % 2 == 0 && count % 3 != 0) {
      printf("%d\n", count);
    }
  }
}
