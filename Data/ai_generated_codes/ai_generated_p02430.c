#include <stdio.h>

// Function to print a combination in the required format
void printCombination(int n, int k, int combination) {
  // Calculate the decimal integer representation
  int d = combination;

  // Print the decimal integer
  printf("%d: ", d);

  // Iterate through all bits and print the indices of set bits
  for (int i = 0; i < n; i++) {
    if (combination & (1 << i)) {
      printf("%d ", i);
    }
  }

  // Print a newline character
  printf("\n");
}

// Function to generate and print all combinations
void generateCombinations(int n, int k) {
  // Iterate through all possible combinations
  for (int combination = (1 << k) - 1; combination < (1 << n); combination++) {
    // Check if the combination has exactly k set bits
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (combination & (1 << i)) {
        count++;
      }
    }

    // If the combination has k set bits, print it
    if (count == k) {
      printCombination(n, k, combination);
    }
  }
}

int main() {
  // Read input
  int n, k;
  scanf("%d %d", &n, &k);

  // Generate and print all combinations
  generateCombinations(n, k);

  return 0;
}