#include <stdio.h>
#include <limits.h>

#define MAX_S 50
#define MAX_D 50

int main() {
  int s, d;
  int distance[MAX_S][MAX_D];
  int min_length;
  int i, j, k;

  // Read input until two 0s are encountered
  while (scanf("%d %d", &s, &d) != EOF && (s != 0 || d != 0)) {
    // Read distances between hot springs and districts
    for (i = 0; i < s; i++) {
      for (j = 0; j < d; j++) {
        scanf("%d", &distance[i][j]);
      }
    }

    // Read distances between districts
    for (i = 0; i < d - 1; i++) {
      for (j = i + 1; j < d; j++) {
        scanf("%d", &distance[s + i][j]);
        // Ensure symmetry in the distance matrix
        distance[s + j][i] = distance[s + i][j];
      }
    }

    // Initialize minimum length to a large value
    min_length = INT_MAX;

    // Iterate through all possible starting points (hot springs or districts)
    for (i = 0; i < s + d - 1; i++) {
      // Initialize a temporary array to store the minimum distances from the starting point
      int temp_distance[MAX_S + MAX_D - 1];
      for (j = 0; j < s + d - 1; j++) {
        temp_distance[j] = INT_MAX;
      }

      // Initialize the distance from the starting point to itself as 0
      temp_distance[i] = 0;

      // Perform Dijkstra's algorithm to find the shortest path from the starting point to all other points
      for (k = 0; k < s + d - 1; k++) {
        // Find the point with the minimum distance from the starting point that has not been visited yet
        int min_index = -1;
        for (j = 0; j < s + d - 1; j++) {
          if (temp_distance[j] < INT_MAX && (min_index == -1 || temp_distance[j] < temp_distance[min_index])) {
            min_index = j;
          }
        }

        // Update the distances to the neighboring points
        for (j = 0; j < s + d - 1; j++) {
          if (distance[min_index][j] != 0 && temp_distance[j] > temp_distance[min_index] + distance[min_index][j]) {
            temp_distance[j] = temp_distance[min_index] + distance[min_index][j];
          }
        }
      }

      // Calculate the total length of the pipeline for the current starting point
      int total_length = 0;
      for (j = 0; j < s + d - 1; j++) {
        total_length += temp_distance[j];
      }

      // Update the minimum length if the current total length is smaller
      if (total_length < min_length) {
        min_length = total_length;
      }
    }

    // Print the minimum length of the pipeline
    printf("%d\n", min_length);
  }

  return 0;
}