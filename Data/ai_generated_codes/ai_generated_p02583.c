#include <stdio.h>

int main() {
  // N: the number of sticks
  int N;
  // L: an array to store the lengths of the sticks
  int L[100];
  // count: the number of ways to choose three sticks that can form a triangle
  int count = 0;

  // Read the input
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &L[i]);
  }

  // Iterate over all possible triples of sticks
  for (int i = 0; i < N - 2; i++) {
    for (int j = i + 1; j < N - 1; j++) {
      for (int k = j + 1; k < N; k++) {
        // Check if the three sticks have different lengths
        if (L[i] != L[j] && L[i] != L[k] && L[j] != L[k]) {
          // Check if the three sticks can form a triangle
          if (L[i] + L[j] > L[k] && L[i] + L[k] > L[j] && L[j] + L[k] > L[i]) {
            // Increment the count
            count++;
          }
        }
      }
    }
  }

  // Print the result
  printf("%d\n", count);

  return 0;
}