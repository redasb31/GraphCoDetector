#include <stdio.h>
#include <stdlib.h>

// Structure to represent a segment of the function
typedef struct {
  int start;
  int end;
  int slope;
  int intercept;
} Segment;

// Function to create a new segment
Segment* newSegment(int start, int end, int slope, int intercept) {
  Segment* segment = (Segment*)malloc(sizeof(Segment));
  segment->start = start;
  segment->end = end;
  segment->slope = slope;
  segment->intercept = intercept;
  return segment;
}

// Function to find the minimum value of f(x) in a given segment
int findMinInSegment(Segment* segment, int x) {
  return segment->slope * x + segment->intercept;
}

// Function to update the function f(x) with a new segment
void updateFunction(Segment** segments, int* numSegments, int a, int b) {
  // Create a new segment for the updated function
  Segment* newSegment = newSegment(a, a, 1, b);

  // Update the existing segments based on the new segment
  int i = 0;
  while (i < *numSegments) {
    if (segments[i]->end < a) {
      // New segment does not affect this segment
      i++;
    } else if (segments[i]->start > a) {
      // New segment is inserted before this segment
      Segment* temp = segments[i];
      segments[i] = newSegment;
      segments[i + 1] = temp;
      (*numSegments)++;
      i += 2;
    } else {
      // New segment overlaps with this segment
      if (segments[i]->slope == 1) {
        // Same slope, update intercept
        segments[i]->intercept += b;
      } else {
        // Different slope, split the segment
        if (segments[i]->start == a) {
          // New segment starts at the same point
          segments[i]->slope = -1;
          segments[i]->intercept = segments[i]->intercept + b - 2 * a;
        } else {
          // New segment starts before the existing segment
          segments[i]->end = a - 1;
          segments[i]->intercept = segments[i]->intercept + b - a;
          Segment* temp = segments[i];
          segments[i] = newSegment;
          segments[i + 1] = temp;
          (*numSegments)++;
          i += 2;
        }
      }
      i++;
    }
  }
}

// Function to find the minimum value of f(x) and its corresponding x
void findMin(Segment** segments, int numSegments) {
  // Initialize the minimum value and its corresponding x
  int minX = segments[0]->start;
  int minValue = findMinInSegment(segments[0], minX);

  // Iterate through all segments and update the minimum value and x
  for (int i = 1; i < numSegments; i++) {
    int tempMinX = segments[i]->start;
    int tempMinValue = findMinInSegment(segments[i], tempMinX);
    if (tempMinValue < minValue) {
      minValue = tempMinValue;
      minX = tempMinX;
    }
  }
  printf("%d %d\n", minX, minValue);
}

int main() {
  int Q;
  scanf("%d", &Q);

  // Initialize the function f(x) as a constant function f(x) = 0
  Segment* segments = (Segment**)malloc(sizeof(Segment*));
  int numSegments = 1;
  segments[0] = newSegment(-1000000000, 1000000000, 0, 0);

  // Process each query
  for (int i = 0; i < Q; i++) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int a, b;
      scanf("%d %d", &a, &b);
      updateFunction(&segments, &numSegments, a, b);
    } else if (type == 2) {
      findMin(segments, numSegments);
    }
  }

  // Free allocated memory
  for (int i = 0; i < numSegments; i++) {
    free(segments[i]);
  }
  free(segments);
  return 0;
}