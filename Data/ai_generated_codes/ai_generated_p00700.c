#include <stdio.h>
#include <math.h>

int main() {
  int N, i, j, dx, dy, x = 0, y = 0, max_x = 0, max_y = 0, max_dist = 0;
  double distance;

  // Get the number of caves
  scanf("%d", &N);

  // Process each cave
  for (i = 0; i < N; i++) {
    // Initialize variables for each cave
    x = 0;
    y = 0;
    max_x = 0;
    max_y = 0;
    max_dist = 0;

    // Read the robot's movement data
    while (1) {
      scanf("%d %d", &dx, &dy);

      // End of cave data
      if (dx == 0 && dy == 0) {
        break;
      }

      // Update current position
      x += dx;
      y += dy;

      // Calculate distance from the entrance
      distance = sqrt(x * x + y * y);

      // Update treasure room if current distance is greater or if distance is equal and x is greater
      if (distance > max_dist || (distance == max_dist && x > max_x)) {
        max_dist = distance;
        max_x = x;
        max_y = y;
      }
    }

    // Print the position of the treasure room
    printf("%d %d\n", max_x, max_y);
  }

  return 0;
}