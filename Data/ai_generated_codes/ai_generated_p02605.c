#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  int x, y;
  char direction;
} Airplane;

// Function to calculate the time of collision between two airplanes
double calculateCollisionTime(Airplane a1, Airplane a2) {
  // Calculate the relative speed in x and y directions
  int dx = 0, dy = 0;
  if (a1.direction == 'R' && a2.direction == 'L') {
    dx = 0.2;
  } else if (a1.direction == 'L' && a2.direction == 'R') {
    dx = -0.2;
  } else if (a1.direction == 'U' && a2.direction == 'D') {
    dy = 0.2;
  } else if (a1.direction == 'D' && a2.direction == 'U') {
    dy = -0.2;
  }

  // If relative speed is 0, there will be no collision
  if (dx == 0 && dy == 0) {
    return -1;
  }

  // Calculate the time of collision using the distance and relative speed
  double time = -1;
  if (dx != 0) {
    time = (double)(a1.x - a2.x) / dx;
  } else if (dy != 0) {
    time = (double)(a1.y - a2.y) / dy;
  }

  // If the collision time is negative, it means the airplanes are moving away from each other
  if (time < 0) {
    return -1;
  }

  return time;
}

int main() {
  int N;
  scanf("%d", &N);

  Airplane *airplanes = malloc(N * sizeof(Airplane));

  // Read the airplane data
  for (int i = 0; i < N; i++) {
    scanf("%d %d %c", &airplanes[i].x, &airplanes[i].y, &airplanes[i].direction);
  }

  // Initialize the minimum collision time to a very large value
  double minCollisionTime = 1e9;

  // Calculate the collision time for every pair of airplanes
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      double collisionTime = calculateCollisionTime(airplanes[i], airplanes[j]);
      // Update the minimum collision time if a collision is detected
      if (collisionTime > 0 && collisionTime < minCollisionTime) {
        minCollisionTime = collisionTime;
      }
    }
  }

  // Print the output based on the minimum collision time
  if (minCollisionTime == 1e9) {
    printf("SAFE\n");
  } else {
    printf("%.0lf\n", minCollisionTime * 10);
  }

  free(airplanes);
  return 0;
}