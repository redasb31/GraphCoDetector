#include <stdio.h>

int main() {
  // Input: N - number of people
  int N;
  scanf("%d", &N);

  // Input: A - array of heights
  int A[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Initialize the total stool height
  long long totalStoolHeight = 0;

  // Initialize the maximum height seen so far
  int maxHeight = 0;

  // Iterate through the people from front to back
  for (int i = 0; i < N; i++) {
    // If the current person's height is less than the maximum height seen so far
    if (A[i] < maxHeight) {
      // Add the difference to the total stool height
      totalStoolHeight += maxHeight - A[i];
    } else {
      // Update the maximum height
      maxHeight = A[i];
    }
  }

  // Print the minimum total stool height
  printf("%lld\n", totalStoolHeight);

  return 0;
}