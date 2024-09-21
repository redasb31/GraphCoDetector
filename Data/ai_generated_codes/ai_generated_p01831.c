#include <stdio.h>
#include <string.h>

int main() {
  int n; // Number of panels
  char s[100001]; // Array to store the directions of the panels

  // Input the number of panels
  scanf("%d", &n);

  // Input the directions of the panels
  scanf("%s", s);

  // Initialize the maximum number of removed panels to 0
  int max_removed = 0;

  // Iterate through each panel as the starting point
  for (int i = 0; i < n; i++) {
    // Initialize the number of removed panels to 0 for the current starting point
    int removed = 0;
    // Initialize the current position to the starting point
    int current = i;
    // Initialize the current direction to the direction of the starting panel
    char direction = s[i];

    // Keep moving until the player reaches the end of the gimmick
    while (current >= 0 && current < n) {
      // Remove the current panel
      removed++;
      // Move to the next panel based on the direction
      if (direction == '>') {
        current++;
      } else {
        current--;
      }

      // If the player reaches a panel, update the direction
      if (current >= 0 && current < n) {
        direction = s[current];
      }
    }

    // Update the maximum number of removed panels if the current number is greater
    if (removed > max_removed) {
      max_removed = removed;
    }
  }

  // Output the maximum number of removed panels
  printf("%d\n", max_removed);

  return 0;
}