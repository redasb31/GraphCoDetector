#include <stdio.h>

int main() {
  int N; // The size of the permutation
  scanf("%d", &N);

  int P[200000]; // The permutation array
  for (int i = 0; i < N; ++i) {
    scanf("%d", &P[i]);
  }

  int operations = 0; // The number of operations needed

  // Iterate through the permutation, starting from the second element
  for (int i = 1; i < N; ++i) {
    // If the current element is less than the previous element, it means we need to move it to the beginning
    if (P[i] < P[i - 1]) {
      // We need to move the current element to the beginning, so we increment the operations count by the distance between the current element and the beginning
      operations += i;
    }
  }

  // Print the minimum number of operations
  printf("%d\n", operations);

  return 0;
}