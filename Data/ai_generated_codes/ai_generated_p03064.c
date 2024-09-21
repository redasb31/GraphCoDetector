#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353

// Function to calculate the number of ways to paint the integers
long long int count_ways(int n, int *a) {
  // Calculate the sum of all integers
  long long int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
  }

  // Initialize the number of ways to paint the integers
  long long int count = 0;

  // Iterate through all possible combinations of red, green, and blue sums
  for (long long int r = 1; r <= sum; r++) {
    for (long long int g = 1; g <= sum; g++) {
      for (long long int b = 1; b <= sum; b++) {
        // Check if the triangle inequality holds
        if (r + g > b && r + b > g && g + b > r) {
          // Initialize the number of ways to paint the integers for the current combination
          long long int ways = 1;

          // Iterate through the integers
          for (int i = 0; i < n; i++) {
            // Calculate the number of ways to paint the current integer
            long long int current_ways = 0;
            if (a[i] <= r) {
              current_ways++;
            }
            if (a[i] <= g) {
              current_ways++;
            }
            if (a[i] <= b) {
              current_ways++;
            }

            // Update the number of ways to paint the integers
            ways = (ways * current_ways) % MOD;
          }

          // Update the total number of ways to paint the integers
          count = (count + ways) % MOD;
        }
      }
    }
  }

  // Return the number of ways to paint the integers
  return count;
}

int main() {
  // Read the number of integers
  int n;
  scanf("%d", &n);

  // Allocate memory for the integers
  int *a = (int *)malloc(sizeof(int) * n);

  // Read the integers
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // Calculate the number of ways to paint the integers
  long long int count = count_ways(n, a);

  // Print the number of ways to paint the integers
  printf("%lld\n", count);

  // Free the memory
  free(a);

  return 0;
}