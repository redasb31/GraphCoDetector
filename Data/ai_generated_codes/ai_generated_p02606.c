#include <stdio.h>

int main() {
  // Declare variables to store input values
  int L, R, d;

  // Read input values from the user
  scanf("%d %d %d", &L, &R, &d);

  // Calculate the number of multiples of d within the range
  int count = 0;
  for (int i = L; i <= R; i++) {
    if (i % d == 0) { // Check if i is a multiple of d
      count++;
    }
  }

  // Print the count of multiples
  printf("%d\n", count);

  return 0;
}