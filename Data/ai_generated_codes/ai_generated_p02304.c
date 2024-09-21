#include <stdio.h>
#include <stdlib.h>

// Structure to represent a segment
typedef struct {
  int x1, y1, x2, y2;
} Segment;

// Function to compare two segments based on their y-coordinates
int compare_segments(const void *a, const void *b) {
  Segment *seg1 = (Segment *)a;
  Segment *seg2 = (Segment *)b;

  // Sort by y-coordinate of the first endpoint
  return seg1->y1 - seg2->y1;
}

// Function to check if two segments intersect
int intersect(Segment seg1, Segment seg2) {
  // Check if both segments are parallel to the X-axis
  if (seg1.y1 == seg1.y2 && seg2.y1 == seg2.y2) {
    // Check if the x-coordinates overlap
    return (seg1.x1 < seg2.x2 && seg1.x2 > seg2.x1) ||
           (seg2.x1 < seg1.x2 && seg2.x2 > seg1.x1);
  }
  // Check if both segments are parallel to the Y-axis
  else if (seg1.x1 == seg1.x2 && seg2.x1 == seg2.x2) {
    // Check if the y-coordinates overlap
    return (seg1.y1 < seg2.y2 && seg1.y2 > seg2.y1) ||
           (seg2.y1 < seg1.y2 && seg2.y2 > seg1.y1);
  }
  // Segments are not parallel, no intersection
  return 0;
}

int main() {
  int n, i, j, intersections = 0;

  // Read the number of segments
  scanf("%d", &n);

  // Create an array to store the segments
  Segment *segments = (Segment *)malloc(n * sizeof(Segment));

  // Read the segments from input
  for (i = 0; i < n; i++) {
    scanf("%d %d %d %d", &segments[i].x1, &segments[i].y1, &segments[i].x2, &segments[i].y2);
  }

  // Sort the segments by y-coordinate
  qsort(segments, n, sizeof(Segment), compare_segments);

  // Iterate over the segments and check for intersections
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      // Check if the segments are parallel and intersect
      if (intersect(segments[i], segments[j])) {
        intersections++;
        // After finding an intersection, skip the next segment since it will be parallel
        j++;
      } else {
        // If no intersection, break the inner loop since segments are sorted by y-coordinate
        break;
      }
    }
  }

  // Print the number of intersections
  printf("%d\n", intersections);

  // Free the memory allocated for segments
  free(segments);

  return 0;
}