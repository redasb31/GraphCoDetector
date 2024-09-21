#include <stdio.h>
#include <math.h>

int main() {
  // Input: N
  int N;
  scanf("%d", &N);

  // Initialize the number of operations
  int operations = 0;

  // Iterate through the powers of 6
  for (int i = 0; pow(6, i) <= N; i++) {
    // If N is divisible by 6^i, subtract it from N and increment the number of operations
    if (N % (int) pow(6, i) == 0) {
      N -= (int) pow(6, i);
      operations++;
    }
  }

  // Iterate through the powers of 9
  for (int i = 0; pow(9, i) <= N; i++) {
    // If N is divisible by 9^i, subtract it from N and increment the number of operations
    if (N % (int) pow(9, i) == 0) {
      N -= (int) pow(9, i);
      operations++;
    }
  }

  // Finally, add the number of 1 yen withdrawals
  operations += N;

  // Output the number of operations
  printf("%d\n", operations);

  return 0;
}