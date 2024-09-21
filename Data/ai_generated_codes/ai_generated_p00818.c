#include <stdio.h>
#include <math.h>

#define MAX_DISCS 100

// Structure to represent a confetti disc
typedef struct {
  double x, y, r;
} Disc;

// Function to check if two discs intersect
int intersects(Disc d1, Disc d2) {
  // Calculate the distance between the centers of the discs
  double distance = sqrt(pow(d1.x - d2.x, 2) + pow(d1.y - d2.y, 2));

  // Check if the distance is less than or equal to the sum of the radii
  return distance <= d1.r + d2.r;
}

int main() {
  int n;
  Disc discs[MAX_DISCS];

  // Read the input until a zero is encountered
  while (scanf("%d", &n) != EOF && n != 0) {
    // Read the coordinates and radius of each disc
    for (int i = 0; i < n; i++) {
      scanf("%lf %lf %lf", &discs[i].x, &discs[i].y, &discs[i].r);
    }

    // Count the number of visible discs
    int visible = 0;
    for (int i = 0; i < n; i++) {
      // Assume the current disc is visible
      int is_visible = 1;

      // Check if the current disc is hidden by any disc above it
      for (int j = i + 1; j < n; j++) {
        if (intersects(discs[i], discs[j])) {
          is_visible = 0;
          break;
        }
      }

      // If the disc is visible, increment the count
      if (is_visible) {
        visible++;
      }
    }

    // Print the number of visible discs
    printf("%d\n", visible);
  }

  return 0;
}