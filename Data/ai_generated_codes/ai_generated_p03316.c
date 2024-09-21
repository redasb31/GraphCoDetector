#include <stdio.h>

// Function to calculate the sum of digits of a number
int sumOfDigits(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int main() {
  int N;
  scanf("%d", &N); // Read the input number

  // Calculate the sum of digits of N
  int sum = sumOfDigits(N);

  // Check if the sum of digits divides N
  if (N % sum == 0) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}