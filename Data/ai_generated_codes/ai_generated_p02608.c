#include <stdio.h>
#include <math.h>

// Function to calculate the number of triples satisfying the given conditions
int count_triples(int n) {
  int count = 0;
  // Iterate over all possible values of x, y, and z
  for (int x = 1; x <= n; x++) {
    for (int y = 1; y <= n; y++) {
      for (int z = 1; z <= n; z++) {
        // Check if the triple satisfies the given condition
        if (x * x + y * y + z * z + x * y + y * z + z * x == n) {
          count++;
        }
      }
    }
  }
  return count;
}

int main() {
  int N;
  // Read the input value of N
  scanf("%d", &N);

  // Calculate and print the number of triples for each value of n from 1 to N
  for (int i = 1; i <= N; i++) {
    printf("%d\n", count_triples(i));
  }
  return 0;
}