#include <stdio.h>
void countTo(int);

int main() {
  countTo(1);
  return 0;
}

void countTo(int i) {
  if (i <= 3) {
    printf("%d\n", i);
    countTo(i + 1);
    printf("%d\n", i);
  }
}