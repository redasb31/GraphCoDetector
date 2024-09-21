#include <stdio.h>

// Function to calculate the number of combinations
long long int countCombinations(long long int a[], long long int b[], long long int c[], long long int d[], long long int n, long long int v) {
  long long int count = 0; // Initialize the count of combinations

  // Iterate through each coin in bag A
  for (long long int i = 0; i < n; i++) {
    // Iterate through each coin in bag B
    for (long long int j = 0; j < n; j++) {
      // Iterate through each coin in bag C
      for (long long int k = 0; k < n; k++) {
        // Iterate through each coin in bag D
        for (long long int l = 0; l < n; l++) {
          // Check if the sum of the selected coins equals the target value
          if (a[i] + b[j] + c[k] + d[l] == v) {
            // Increment the count if the sum matches
            count++;
          }
        }
      }
    }
  }

  // Return the total number of combinations
  return count;
}

int main() {
  long long int n, v; // Declare variables for N and V
  // Read N and V from the input
  scanf("%lld %lld", &n, &v);

  // Declare arrays to store the coin values for each bag
  long long int a[n], b[n], c[n], d[n];

  // Read the coin values for each bag from the input
  for (long long int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  for (long long int i = 0; i < n; i++) {
    scanf("%lld", &b[i]);
  }
  for (long long int i = 0; i < n; i++) {
    scanf("%lld", &c[i]);
  }
  for (long long int i = 0; i < n; i++) {
    scanf("%lld", &d[i]);
  }

  // Calculate and print the number of combinations
  printf("%lld\n", countCombinations(a, b, c, d, n, v));

  return 0;
}