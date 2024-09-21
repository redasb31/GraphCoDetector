#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 100
#define MAX_K 10
#define EPS 0.000001

// Structure to store the spotlight information
typedef struct {
  int r; // Radius
  int K; // Number of vertices in the orbital path
  int x[MAX_K]; // X-coordinates of vertices
  int y[MAX_K]; // Y-coordinates of vertices
} Spotlight;

// Function to calculate the distance between two points
double distance(int x1, int y1, int x2, int y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

// Function to check if a point is inside the circle
int is_inside_circle(Spotlight spotlight, int x, int y) {
  int i;
  for (i = 0; i < spotlight.K; i++) {
    if (distance(x, y, spotlight.x[i], spotlight.y[i]) <= spotlight.r + EPS) {
      return 1;
    }
  }
  return 0;
}

// Function to check if the path is valid
int is_path_valid(Spotlight spotlights[], int N, int sx, int sy, int ex, int ey) {
  int i, j;
  // Check if the starting point is within the illuminated area
  if (!is_inside_circle(spotlights[0], sx, sy)) {
    return 0;
  }

  // Check if the ending point is within the illuminated area
  if (!is_inside_circle(spotlights[0], ex, ey)) {
    return 0;
  }

  // Check if the spotlight coverage overlaps
  for (i = 0; i < N; i++) {
    for (j = i + 1; j < N; j++) {
      if (distance(spotlights[i].x[0], spotlights[i].y[0], spotlights[j].x[0], spotlights[j].y[0]) < spotlights[i].r + spotlights[j].r - EPS) {
        return 0;
      }
    }
  }

  return 1;
}

int main() {
  int N, sx, sy, ex, ey;
  Spotlight spotlights[MAX_N];
  int i, j;

  // Read the input
  scanf("%d %d %d %d %d", &N, &sx, &sy, &ex, &ey);
  for (i = 0; i < N; i++) {
    scanf("%d %d", &spotlights[i].r, &spotlights[i].K);
    for (j = 0; j < spotlights[i].K; j++) {
      scanf("%d %d", &spotlights[i].x[j], &spotlights[i].y[j]);
    }
  }

  // Check if the path is valid
  if (is_path_valid(spotlights, N, sx, sy, ex, ey)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}