#include <stdio.h>

int main() {
  int M, N;
  printf("Please enter the number M: ");
  scanf("%d", &M);
  printf("Please enter the number N: ");
  scanf("%d", &N);
  int count;
  for(count = M; count <= N; count++) {
    printf("%d\n", count);
  }
  return 0;
}