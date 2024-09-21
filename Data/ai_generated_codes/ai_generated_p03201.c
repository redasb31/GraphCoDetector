#include <stdio.h>
#include <math.h>

// Function to check if a number is a power of 2
int isPowerOfTwo(int x) {
  return (x != 0) && ((x & (x - 1)) == 0);
}

int main() {
  int N; // Number of balls
  scanf("%d", &N);

  int A[200005]; // Array to store the integers written on the balls
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  int count = 0; // Count of pairs
  for (int i = 0; i < N; i++) {
    // For each ball, check if it can be paired with another ball
    for (int j = i + 1; j < N; j++) {
      // Check if the sum of the integers on the two balls is a power of 2
      if (isPowerOfTwo(A[i] + A[j])) {
        // If it is, increment the count of pairs and mark the balls as paired
        count++;
        A[i] = -1; // Mark the first ball as paired
        A[j] = -1; // Mark the second ball as paired
        break; // Move to the next ball
      }
    }
  }

  printf("%d\n", count); // Print the maximum number of pairs
  return 0;
}