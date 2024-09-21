#include <stdio.h>

int main() {
  int n, i, j, treasures[25], max_treasures[25], total_treasures = 0;
  while (1) {
    scanf("%d", &n);
    // End of input
    if (n == 0) {
      break;
    }
    // Read the treasure and max_treasure information for each island
    for (i = 0; i < n; i++) {
      scanf("%d %d", &treasures[i], &max_treasures[i]);
      total_treasures += treasures[i];
    }
    // Initialize a boolean array to track visited islands
    int visited[25] = {0};
    // Start from the starting island (index 0)
    i = 0;
    // Track the current amount of treasures held
    int current_treasures = 0;
    // Flag to indicate whether the thief can collect all treasures
    int can_collect = 1;
    // Iterate until all islands are visited
    while (1) {
      // If all islands are visited, break the loop
      if (visited[i] == 1) {
        break;
      }
      // Mark the current island as visited
      visited[i] = 1;
      // Add the treasures from the current island
      current_treasures += treasures[i];
      // Find the next island to visit
      int next_island = -1;
      for (j = 0; j < n; j++) {
        // If the island is not visited and the bridge can handle the current treasures
        if (visited[j] == 0 && current_treasures <= max_treasures[j]) {
          // Update the next island
          next_island = j;
          break;
        }
      }
      // If no suitable next island is found
      if (next_island == -1) {
        // The thief cannot collect all treasures
        can_collect = 0;
        break;
      }
      // Move to the next island
      i = next_island;
    }
    // Print the result
    if (can_collect && current_treasures == total_treasures) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
    // Reset total_treasures for the next dataset
    total_treasures = 0;
  }
  return 0;
}