#include <stdio.h>

int main() {
  int v[3] = {1, 2, 3};
  int(*q)[3] = &v;

  int i;
  for (i = 0; i < 3; i++) {
    (*q)[i] = 0;
  }
}