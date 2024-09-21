#include <stdio.h>

int sum_digits(int num) {
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

  // Find the optimal split of N to minimize the digit sum.
  // For example, for N = 115, the optimal split is 2 + 13, because 2 + 4 = 6
  // is the minimal sum of digits among all splits of 115.
  int a = 1; // Start with a = 1
  int b = N - a; // b = N - a
  int min_sum = sum_digits(a) + sum_digits(b); // Initialize with current sum

  // Try different values of a until the sum of digits is minimized
  for (a = 2; a <= N / 2; a++) { // a is at most N/2 to keep b positive
    b = N - a;
    int current_sum = sum_digits(a) + sum_digits(b);
    if (current_sum < min_sum) {
      min_sum = current_sum;
    }
  }

  printf("%d\n", min_sum);

  return 0;
}