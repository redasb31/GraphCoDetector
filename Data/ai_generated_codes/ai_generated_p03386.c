#include <stdio.h>

int main() {
  // Input values
  int A, B, K;
  scanf("%d %d %d", &A, &B, &K);

  // Determine the smallest and largest K integers
  int smallest_k = A;  // Initialize with the smallest possible value
  int largest_k = B; // Initialize with the largest possible value

  // Iterate through the numbers and find the smallest and largest K integers
  for (int i = A; i <= B; i++) {
    // If the current number is smaller than the current smallest_k, update smallest_k
    if (i < smallest_k) {
      smallest_k = i;
    }

    // If the current number is larger than the current largest_k, update largest_k
    if (i > largest_k) {
      largest_k = i;
    }
  }

  // Print all the integers that are within the K smallest or K largest
  for (int i = A; i <= B; i++) {
    // Check if the current number is within the K smallest integers
    if (i <= smallest_k + K - 1) {
      printf("%d\n", i);
    } else if (i >= largest_k - K + 1) {
      // Check if the current number is within the K largest integers
      printf("%d\n", i);
    }
  }

  return 0;
}