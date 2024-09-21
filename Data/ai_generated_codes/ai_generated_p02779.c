#include <stdio.h>
#include <stdbool.h>

int main() {
  // Get the number of elements in the sequence.
  int n;
  scanf("%d", &n);

  // Create an array to store the elements of the sequence.
  int a[n];

  // Read the elements of the sequence from the input.
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // Create a boolean array to track whether an element has been seen before.
  bool seen[1000000001] = {false};

  // Iterate through the elements of the sequence.
  for (int i = 0; i < n; i++) {
    // If the current element has been seen before, then the elements are not pairwise distinct.
    if (seen[a[i]]) {
      printf("NO\n");
      return 0;
    }

    // Mark the current element as seen.
    seen[a[i]] = true;
  }

  // If all elements are distinct, then print YES.
  printf("YES\n");
  return 0;
}