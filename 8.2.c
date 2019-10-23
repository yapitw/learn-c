#include <stdio.h>

int main() {
  int answer = 4;
  int guess;
  int count = 0;

  while (count == 0 || guess != answer) {
    printf("Please enter your guess: ");
    scanf("%d", &guess);
    if(guess > answer) {
      printf("Too large!\n");
    } else if(guess < answer){
      printf("Too small!\n");
    } 
  }

  printf("Correct!\n");

  return 0;
}