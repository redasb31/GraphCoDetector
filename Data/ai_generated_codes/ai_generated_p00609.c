#include <stdio.h>
#include <math.h>

// Structure to store coordinates
typedef struct {
  int x;
  int y;
} Coordinate;

// Function to calculate the distance between two points
double distance(Coordinate a, Coordinate b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
  int AN, BN, R;
  Coordinate plane[100000];
  Coordinate bullet[100000];

  while (1) {
    // Read the input
    scanf("%d %d %d", &AN, &BN, &R);

    // Exit condition
    if (AN == 0 && BN == 0) {
      break;
    }

    // Read coordinates of combat planes
    for (int i = 0; i < AN; i++) {
      scanf("%d %d", &plane[i].x, &plane[i].y);
    }

    // Read coordinates of energy bullets
    for (int i = 0; i < BN; i++) {
      scanf("%d %d", &bullet[i].x, &bullet[i].y);
    }

    // Calculate total fighting power
    int totalFightingPower = 0;
    for (int i = 0; i < AN; i++) {
      for (int j = 0; j < BN; j++) {
        // Check if the distance between plane and bullet is less than or equal to 2R
        if (distance(plane[i], bullet[j]) <= 2 * R) {
          totalFightingPower++;
        }
      }
    }

    // Print the total fighting power
    printf("%d\n", totalFightingPower);
  }

  return 0;
}