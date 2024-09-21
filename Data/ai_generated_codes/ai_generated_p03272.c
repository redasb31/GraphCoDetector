#include <stdio.h>

int main() {
  // Declare variables to store the number of cars and the position from the front.
  int N, i;

  // Read the input values for N and i.
  scanf("%d %d", &N, &i);

  // Calculate the position from the back (j).
  int j = N - i + 1;

  // Print the calculated position from the back.
  printf("%d\n", j);

  return 0;
}