#include <stdio.h>
#include <string.h>

int main() {
  char str[100][10];
  char input[10];
  int len = 0;
  while (1) {
    scanf("%s", input);
    if (strcmp(input, "END") == 0)
      break;
    strcpy(str[len], input);
    ++len;
  }

  printf("----------\n");
  int i;
  for (i = 0; i < len; i++) {
    printf("%s ", str[i]);
  }
  printf("\n");

  return 0;
}
