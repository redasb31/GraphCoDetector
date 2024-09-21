#include <stdio.h>

int main() {
  // Declare a variable to store the input value K.
  int K;

  // Read the value of K from the standard input.
  scanf("%d", &K);

  // Define the sequence of length 32.
  int sequence[] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};

  // Print the K-th element of the sequence.
  printf("%d\n", sequence[K - 1]);

  return 0;
}