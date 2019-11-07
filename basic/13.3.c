/**
 * 費氏數列(費波納西數列)
 * https://zh-yue.wikipedia.org/wiki/費氏數列
 **/

#include <stdio.h>
int S(int);

int main() {
  int N;
  printf("N = ");
  scanf("%d", &N);
  printf("%d \n", S(N));
  return 0;
}

int S(int N) {
  if (N <= 2) {
    return N;
  }
  return S(N - 1) + S(N - 2);
}