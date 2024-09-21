#include <stdio.h>

int main() {
  int N, D; // N: number of trees, D: inspection range
  scanf("%d %d", &N, &D);

  // Initialize an array to track inspected trees
  int inspected[21] = {0}; 

  int inspectors = 0; // Counter for the number of inspectors

  // Iterate through each tree
  for (int i = 1; i <= N; i++) {
    // If the tree has not been inspected yet
    if (!inspected[i]) {
      // Increment the inspector count
      inspectors++; 
      // Mark trees within the inspection range as inspected
      for (int j = i - D; j <= i + D; j++) {
        if (j >= 1 && j <= N) {
          inspected[j] = 1;
        }
      }
    }
  }

  // Print the minimum number of inspectors
  printf("%d\n", inspectors);

  return 0;
}