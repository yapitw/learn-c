#include <stdio.h>
#include <string.h>

int main() {
  const char *source = "test";
  char destination[5];

  strcpy(destination, source);

  return 0;
}
