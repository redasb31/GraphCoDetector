#include <stdio.h>

int main() {
  int n, i, j, k;
  int a[200001]; // Array to store the numbers written on the balls
  int count[200001]; // Array to store the frequency of each number

  scanf("%d", &n); // Read the number of balls

  // Read the numbers written on the balls
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }

  // For each ball (k)
  for (k = 1; k <= n; k++) {
    // Initialize the frequency array
    for (i = 1; i <= n; i++) {
      count[i] = 0;
    }

    // Count the frequency of each number excluding the k-th ball
    for (i = 1; i <= n; i++) {
      if (i != k) {
        count[a[i]]++;
      }
    }

    // Calculate the number of ways to choose two distinct balls with equal numbers
    int ways = 0;
    for (i = 1; i <= n; i++) {
      // If there are more than one balls with the same number
      if (count[i] > 1) {
        // Calculate the number of ways to choose two balls with this number
        ways += count[i] * (count[i] - 1) / 2;
      }
    }

    printf("%d\n", ways); // Print the number of ways for the current ball
  }

  return 0;
}