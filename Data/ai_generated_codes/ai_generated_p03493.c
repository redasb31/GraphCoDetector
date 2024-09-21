#include <stdio.h>

int main() {
  // Declare variables to store the numbers written in each square.
  int s1, s2, s3;

  // Read the numbers written in each square from the input.
  scanf("%d%d%d", &s1, &s2, &s3);

  // Initialize a variable to count the number of squares with a marble.
  int marbleCount = 0;

  // Check each square and increment the count if a marble is placed.
  if (s1 == 1) {
    marbleCount++;
  }
  if (s2 == 1) {
    marbleCount++;
  }
  if (s3 == 1) {
    marbleCount++;
  }

  // Print the final count of squares with marbles.
  printf("%d\n", marbleCount);

  return 0;
}