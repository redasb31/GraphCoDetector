#include <stdio.h>
#include <string.h>

int main() {
  char commands[1001]; // Maximum length of the command sequence

  // Get the command sequence from the user
  scanf("%s", commands);

  int direction = 0; // 0: North, 1: East, 2: South, 3: West
  int magical_power = 0; // Counter for the magical power obtained

  int has_visited_north = 0; // Flag to track if North has been visited
  int has_visited_east = 0; // Flag to track if East has been visited
  int has_visited_south = 0; // Flag to track if South has been visited
  int has_visited_west = 0; // Flag to track if West has been visited

  // Iterate through each command in the sequence
  for (int i = 0; i < strlen(commands); i++) {
    if (commands[i] == 'R') {
      direction = (direction + 1) % 4; // Rotate clockwise
    } else if (commands[i] == 'L') {
      direction = (direction + 3) % 4; // Rotate counterclockwise
    }

    // Update flags based on the current direction
    if (direction == 0) {
      has_visited_north = 1;
    } else if (direction == 1) {
      has_visited_east = 1;
    } else if (direction == 2) {
      has_visited_south = 1;
    } else {
      has_visited_west = 1;
    }

    // Check if magical power is obtained
    if (direction == 0 && has_visited_north && has_visited_east && has_visited_south && has_visited_west) {
      magical_power++;
      has_visited_north = 0; // Reset flags for next round
      has_visited_east = 0;
      has_visited_south = 0;
      has_visited_west = 0;
    }
  }

  // Print the number of times magical power was obtained
  printf("%d\n", magical_power);

  return 0;
}