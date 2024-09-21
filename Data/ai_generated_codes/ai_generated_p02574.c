#include <stdio.h>

// Function to calculate the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  int N, i, j;
  int pairwise_coprime = 1; // Flag to track if the set is pairwise coprime
  int setwise_coprime = 1; // Flag to track if the set is setwise coprime
  int A[1000000]; // Array to store the input numbers

  // Input the number of integers (N)
  scanf("%d", &N);

  // Input the N integers
  for (i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Check for pairwise coprimality
  for (i = 0; i < N - 1; i++) {
    for (j = i + 1; j < N; j++) {
      if (gcd(A[i], A[j]) != 1) {
        pairwise_coprime = 0; // Set flag to 0 if any pair has GCD != 1
      }
    }
  }

  // Check for setwise coprimality
  for (i = 1; i < N; i++) {
    setwise_coprime = gcd(setwise_coprime, A[i]); // Find GCD of all numbers
  }

  // Print the result based on the flags
  if (pairwise_coprime) {
    printf("pairwise coprime\n");
  } else if (setwise_coprime == 1) {
    printf("setwise coprime\n");
  } else {
    printf("not coprime\n");
  }

  return 0;
}