#include <stdio.h>

// Function to calculate the maximum bitwise AND of the beauties of K subsequences.
int max_bitwise_and(int n, int k, int a[]) {
  // Calculate the sum of all elements in the array.
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
  }

  // Create a 2D array to store the prefix sums.
  int prefix_sum[n + 1][n + 1];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      prefix_sum[i][j] = 0;
    }
  }

  // Calculate the prefix sums.
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      prefix_sum[i][j] = prefix_sum[i][j - 1] + a[j - 1];
    }
  }

  // Initialize the maximum bitwise AND to 0.
  int max_and = 0;

  // Iterate through all possible combinations of K subsequences.
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      // Calculate the beauty of the current subsequence.
      int beauty = prefix_sum[i][j];

      // Iterate through the remaining subsequences.
      for (int l = i; l <= n; l++) {
        for (int r = l; r <= n; r++) {
          // Calculate the beauty of the second subsequence.
          int second_beauty = prefix_sum[l][r];

          // Calculate the bitwise AND of the two beauties.
          int current_and = beauty & second_beauty;

          // Update the maximum bitwise AND if necessary.
          max_and = (current_and > max_and) ? current_and : max_and;
        }
      }
    }
  }

  // Return the maximum bitwise AND.
  return max_and;
}

int main() {
  // Read input.
  int n, k;
  scanf("%d %d", &n, &k);

  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // Calculate and print the maximum bitwise AND.
  printf("%d\n", max_bitwise_and(n, k, a));

  return 0;
}