#include <stdio.h>

int main() {
  // Declare a variable to store the input integer.
  int N;

  // Read the integer from standard input.
  scanf("%d", &N);

  // Check if the integer contains the digit 7.
  // We do this by iterating through each digit of the number and comparing it to 7.
  if (N / 100 == 7 || (N % 100) / 10 == 7 || N % 10 == 7) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}