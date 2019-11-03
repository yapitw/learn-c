#include <stdio.h>

int main() {
  int v[5];
  int *p;
  // for (p = v; p != &v[5]; p++) {
  //   *p = 0;
  // }

  p = v;
  while (p != v + 5) {
    *p++ = 0;
  }

  return 0;
}