#include <stdio.h>
#include <string.h>

int main() {
  int n, m; // Number of prefectures and features
  scanf("%d %d", &n, &m);

  char data[101][10001]; // 2D array to store the data
  for (int i = 0; i < m; i++) {
    scanf("%s", data[i]); // Read input data for each feature
  }

  int min_errors = n * m; // Initialize minimum errors to maximum possible
  int boundary_left = 0, boundary_right = 1; // Initialize boundary

  // Iterate through all possible boundaries
  for (int i = 1; i <= n; i++) {
    int errors = 0; // Count errors for the current boundary

    // Count 'W's on the eastern side of the boundary
    for (int j = 0; j < m; j++) {
      for (int k = i; k <= n; k++) {
        if (data[j][k - 1] == 'W') {
          errors++;
        }
      }
    }

    // Count 'E's on the western side of the boundary
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < i; k++) {
        if (data[j][k] == 'E') {
          errors++;
        }
      }
    }

    // Update minimum errors and boundary if necessary
    if (errors < min_errors) {
      min_errors = errors;
      boundary_left = i - 1;
      boundary_right = i;
    }
  }

  // Handle cases where all prefectures are eastern or western
  if (boundary_left == 0) {
    boundary_left = 0;
    boundary_right = 1;
  } else if (boundary_right == n) {
    boundary_left = n;
    boundary_right = n + 1;
  }

  // Output the boundary
  printf("%d %d\n", boundary_left, boundary_right);

  return 0;
}