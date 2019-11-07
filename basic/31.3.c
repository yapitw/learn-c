#include <stdio.h>
#include <string.h>

int main() {
  char raw[5000];
  char *str[100];
  char input[50];
  int size = 0;
  int len = 0;
  while (1) {
    scanf("%s", input);
    if (strcmp(input, "END") == 0)
      break;
    str[len] = &raw[size];
    strcpy(&raw[size], input);
    size += strlen(input) + 1;
    ++len;
  }

  printf("----------\n");
  int i;
  for (i = 0; i < len; i++) {
    printf("%s ", str[i]);
  }
  printf("\n(%d, %d)\n", len, size);

  return 0;
}
