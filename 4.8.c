#include <stdio.h>

int main() {
  int side1, side2, side3;
  printf("Please input the lengths: ");
  scanf("%d%d%d", &side1, &side2, &side3);

  // Sort 3 sides by value

  if (side1 == side3) {
    printf("Regular triangle\n");
  }
  if (side1 == side2 || side2 == side3) {
    printf("Isosceles triangle\n");
  }
  if (side1 * side1 + side2 * side2 == side3 * side3) {
    printf("Rectangular triangle\n");
  }
  return 0;
}
