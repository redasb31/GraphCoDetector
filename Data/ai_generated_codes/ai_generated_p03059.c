#include <stdio.h>

int main() {
  // Declare variables to store input values
  int A, B, T;

  // Read input values from the user
  scanf("%d %d %d", &A, &B, &T);

  // Calculate the number of biscuits produced within T + 0.5 seconds
  int biscuitsProduced = 0;
  int time = A; // Initialize time to the first production time
  while (time <= T + 0.5) {
    biscuitsProduced += B; // Add the number of biscuits produced at this time
    time += A; // Increment the time to the next production time
  }

  // Print the total number of biscuits produced
  printf("%d\n", biscuitsProduced);

  return 0;
}