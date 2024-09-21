#include <stdio.h>

int main() {
  // Declare the variable to store the input number.
  int N;

  // Read the input number from the user.
  scanf("%d", &N);

  // Initialize a counter to store the number of tuples.
  long long count = 0;

  // Iterate over all possible values of A and B.
  for (int A = 1; A <= N; A++) {
    for (int B = 1; B <= N; B++) {
      // Calculate the value of C.
      int C = N - (A * B);

      // If C is positive, increment the counter.
      if (C > 0) {
        count++;
      }
    }
  }

  // Print the number of tuples.
  printf("%lld\n", count);

  return 0;
}