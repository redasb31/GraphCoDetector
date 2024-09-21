#include <stdio.h>
#include <math.h>

// Function to check if a number is an integer
int isInteger(double num) {
  return (floor(num) == num);
}

int main() {
  int N;
  scanf("%d", &N);

  // Array to store the input values
  double A[N];

  // Input the values
  for (int i = 0; i < N; i++) {
    scanf("%lf", &A[i]);
  }

  // Counter for integer product pairs
  int count = 0;

  // Iterate over all pairs of indices
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      // Check if the product is an integer
      if (isInteger(A[i] * A[j])) {
        count++;
      }
    }
  }

  // Output the count
  printf("%d\n", count);

  return 0;
}