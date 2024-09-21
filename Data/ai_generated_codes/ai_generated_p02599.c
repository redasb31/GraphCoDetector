#include <stdio.h>

// Function to find the number of different colors in a range of balls
int count_colors(int *colors, int l, int r) {
  // Create a boolean array to track the colors seen
  int seen[100001] = {0}; // Assuming the maximum color is 100000
  int count = 0;
  // Iterate through the range of balls
  for (int i = l; i <= r; i++) {
    // If a color is seen for the first time
    if (!seen[colors[i]]) {
      // Mark it as seen
      seen[colors[i]] = 1;
      // Increment the count of colors
      count++;
    }
  }
  // Return the count of colors
  return count;
}

int main() {
  // Read the number of balls and queries
  int N, Q;
  scanf("%d %d", &N, &Q);
  // Allocate memory for the colors array
  int *colors = (int *)malloc(N * sizeof(int));
  // Read the colors of the balls
  for (int i = 0; i < N; i++) {
    scanf("%d", &colors[i]);
  }
  // Read the queries and print the results
  for (int i = 0; i < Q; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    // Call the count_colors function and print the result
    printf("%d\n", count_colors(colors, l - 1, r - 1));
  }
  // Free the memory allocated for the colors array
  free(colors);
  return 0;
}