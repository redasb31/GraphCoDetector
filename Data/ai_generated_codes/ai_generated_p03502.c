#include <stdio.h>

// Function to calculate the sum of digits of a number
int sumOfDigits(int num) {
  int sum = 0;
  while (num > 0) {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}

int main() {
  int N;
  scanf("%d", &N);

  // Calculate the sum of digits of N
  int sum = sumOfDigits(N);

  // Check if N is divisible by the sum of its digits
  if (N % sum == 0) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}