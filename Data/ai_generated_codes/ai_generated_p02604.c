#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 15
#define MAX_COORD 10000

typedef struct {
  int x, y, p;
} Area;

Area areas[MAX_N];
int n;

// Calculate the Manhattan distance between two points
int manhattan_distance(int x1, int y1, int x2, int y2) {
  return abs(x1 - x2) + abs(y1 - y2);
}

// Calculate the minimum sum of walking distances for a given number of railroads
long long calculate_min_distance(int k) {
  long long min_distance = LONG_MAX;
  // Try all possible combinations of k railroads
  for (int i = 0; i < (1 << n); i++) {
    if (__builtin_popcount(i) != k) continue; // Skip if not k railroads
    long long total_distance = 0;
    // Calculate the total walking distance for each area
    for (int j = 0; j < n; j++) {
      int min_dist = MAX_COORD; // Initialize minimum distance to maximum
      // Check distance to each railroad
      for (int l = 0; l < n; l++) {
        if ((i >> l) & 1) { // If the l-th bit is set (railroad exists)
          min_dist = min(min_dist, manhattan_distance(areas[j].x, areas[j].y, areas[l].x, areas[l].y));
        }
      }
      total_distance += min_dist * areas[j].p;
    }
    min_distance = min(min_distance, total_distance); // Update minimum distance
  }
  return min_distance;
}

int main() {
  scanf("%d", &n);
  // Read in the area information
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &areas[i].x, &areas[i].y, &areas[i].p);
  }

  // Calculate the minimum distance for each number of railroads
  for (int k = 0; k <= n; k++) {
    printf("%lld\n", calculate_min_distance(k));
  }

  return 0;
}