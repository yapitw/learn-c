#include <stdio.h>
#include <stdlib.h>

int main() {
  int *numbers = 0; // 0 表示空指標 (NULL)
  int length = 0;   // 目前已經輸入的數字個數
  while (1) {
    int input;
    scanf("%d", &input); // 從鍵盤輸入數字
    if (input == 0)      // 如果輸入數字為 0 結束
      break;
    numbers = realloc(numbers, sizeof(int) * (length + 1)); // 重新配置新陣列
    numbers[length] = input; // 將輸入數字加在最後面
    length++;                // 將已輸入的數字個數加 1
  }
  printf("Numbers: ");
  for (int i = 0; i < length; i++) { // 數每個輸入的數字
    printf("%d ", numbers[i]);
  }
  printf("\n");
  return 0;
}