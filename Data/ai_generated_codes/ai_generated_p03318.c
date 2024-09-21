#include <stdio.h>
#include <math.h>

// Function to calculate the sum of digits of a number
int sumOfDigits(long long int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

// Function to check if a number is a Snuke number
int isSnukeNumber(long long int n) {
  for (long long int m = n + 1; m <= 1000000000000000; m++) {
    if ((double) n / sumOfDigits(n) > (double) m / sumOfDigits(m)) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int K;
  scanf("%d", &K);

  // Array to store the Snuke numbers
  long long int snukeNumbers[K];
  int count = 0;

  // Find the Snuke numbers
  for (long long int i = 1; i <= 1000000000000000 && count < K; i++) {
    if (isSnukeNumber(i)) {
      snukeNumbers[count++] = i;
    }
  }

  // Print the Snuke numbers
  for (int i = 0; i < K; i++) {
    printf("%lld\n", snukeNumbers[i]);
  }

  return 0;
}