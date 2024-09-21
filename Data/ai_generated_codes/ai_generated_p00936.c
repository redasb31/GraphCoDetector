#include <stdio.h>
#include <math.h>

int main() {
  int N;
  int radii[500];

  // Read the number of cylinders
  scanf("%d", &N);

  // Read the radii of the cylinders
  for (int i = 0; i < N; i++) {
    scanf("%d", &radii[i]);
  }

  // Calculate the minimum distance between the walls
  double distance = 0;
  for (int i = 0; i < N; i++) {
    distance += 2 * radii[i];
  }

  // Calculate the distance between the walls when the cylinders are squeezed
  double squeezedDistance = distance;
  for (int i = 0; i < N - 1; i++) {
    double currentDistance = distance;
    for (int j = i + 1; j < N; j++) {
      // Calculate the distance between the centers of the cylinders
      double centerDistance = 2 * (radii[i] + radii[j]);

      // Calculate the distance between the walls if the cylinders are squeezed
      double squeezedDistanceBetweenCylinders = centerDistance - sqrt(2 * radii[i] * radii[j]);

      // Update the minimum distance between the walls
      currentDistance = currentDistance - 2 * (radii[i] + radii[j]) + squeezedDistanceBetweenCylinders;

      // If the distance is less than the current minimum distance, update the minimum distance
      if (currentDistance < squeezedDistance) {
        squeezedDistance = currentDistance;
      }
    }
  }

  // Print the minimum distance between the walls
  printf("%.8lf\n", squeezedDistance);

  return 0;
}