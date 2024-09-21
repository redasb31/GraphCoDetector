#include <stdio.h>
#include <string.h>

int main() {
  int n;
  char s[100001];

  // Input the number of colors and the string.
  scanf("%d\n", &n);
  scanf("%s", s);

  // Create an array to store the arrangement of doors.
  int doors[2 * n];

  // Initialize the array with 0s.
  memset(doors, 0, sizeof(doors));

  // Flag to indicate whether a valid arrangement is found.
  int valid = 1;

  // Variables to keep track of the positions of the doors.
  int left[n + 1];
  int right[n + 1];

  // Initialize the positions of the doors.
  for (int i = 1; i <= n; i++) {
    left[i] = 0;
    right[i] = 0;
  }

  // Iterate through the string.
  for (int i = 0; i < 2 * n - 1; i++) {
    // If the current section is traversed.
    if (s[i] == '1') {
      // Check if the left door of the corresponding color is already placed.
      if (left[i / 2 + 1] != 0) {
        // If the right door is not placed yet.
        if (right[i / 2 + 1] == 0) {
          // Place the right door.
          right[i / 2 + 1] = i + 2;
          doors[i + 1] = i / 2 + 1;
        } else {
          // Inconsistent arrangement.
          valid = 0;
          break;
        }
      } else {
        // Place the left door.
        left[i / 2 + 1] = i + 1;
        doors[i] = i / 2 + 1;
      }
    } else {
      // Check if both doors of the corresponding color are already placed.
      if (left[i / 2 + 1] != 0 && right[i / 2 + 1] != 0) {
        // Inconsistent arrangement.
        valid = 0;
        break;
      }
    }
  }

  // Check if a valid arrangement is found.
  if (valid) {
    printf("Yes\n");
    // Print the arrangement.
    for (int i = 0; i < 2 * n; i++) {
      printf("%d ", doors[i]);
    }
    printf("\n");
  } else {
    // Print "No" if no valid arrangement is found.
    printf("No\n");
  }

  return 0;
}