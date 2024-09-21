#include <stdio.h>

// Function to calculate the minimum number of carpets required
int min_carpets(int w, int h, int floor[10][10]) {
  int i, j, k, l, min_carpets = 0;
  // Iterate over each panel
  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      // If panel is scratched
      if (floor[i][j] == 1) {
        // Find the largest square of scratched panels starting from the current panel
        for (k = i; k < h; k++) {
          for (l = j; l < w; l++) {
            // If all panels in the square are scratched
            if (floor[k][l] == 1) {
              // Increase the number of carpets
              min_carpets++;
              // Mark all panels in the square as covered
              for (int x = i; x <= k; x++) {
                for (int y = j; y <= l; y++) {
                  floor[x][y] = 0;
                }
              }
              // Break out of the inner loops
              break;
            } else {
              // Break out of the inner loop if a non-scratched panel is found
              break;
            }
          }
          // Break out of the outer loop if a non-scratched panel is found
          if (floor[k][l] == 0) {
            break;
          }
        }
      }
    }
  }
  return min_carpets;
}

int main() {
  int w, h, floor[10][10];
  // Read the input until end of input
  while (scanf("%d %d", &w, &h) != EOF && (w != 0 || h != 0)) {
    // Read the floor state
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        scanf("%d", &floor[i][j]);
      }
    }
    // Calculate the minimum number of carpets
    int min_carpets_needed = min_carpets(w, h, floor);
    // Print the result
    printf("%d\n", min_carpets_needed);
  }
  return 0;
}