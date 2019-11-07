#include <stdio.h>
#include <stdlib.h>

int main() {
  int number;
  while (scanf("%d", &number) != 1) {
    printf("Error: Invlid input \n");
    fflush(stdin);
  }
  printf("%d\n", number);
  return 0;
}
