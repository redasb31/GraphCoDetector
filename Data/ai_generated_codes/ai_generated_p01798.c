#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
  int x;
  int y;
} Point;

// Function to calculate the midpoint of two points
Point midpoint(Point p1, Point p2) {
  Point mid;
  mid.x = (p1.x + p2.x) / 2;
  mid.y = (p1.y + p2.y) / 2;
  return mid;
}

// Function to compare two points
int comparePoints(const void *a, const void *b) {
  Point *p1 = (Point *)a;
  Point *p2 = (Point *)b;
  if (p1->x != p2->x) {
    return p1->x - p2->x;
  } else {
    return p1->y - p2->y;
  }
}

int main() {
  int L, M, N;
  scanf("%d %d %d", &L, &M, &N);

  // Allocate memory for points
  Point *A = (Point *)malloc(L * sizeof(Point));
  Point *B = (Point *)malloc(M * sizeof(Point));
  Point *C = (Point *)malloc(N * sizeof(Point));

  // Read points from input
  for (int i = 0; i < L; i++) {
    scanf("%d %d", &A[i].x, &A[i].y);
  }
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &B[i].x, &B[i].y);
  }
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &C[i].x, &C[i].y);
  }

  // Sort points for efficient search
  qsort(A, L, sizeof(Point), comparePoints);
  qsort(B, M, sizeof(Point), comparePoints);
  qsort(C, N, sizeof(Point), comparePoints);

  // Count the number of triplets
  int count = 0;
  int i = 0, j = 0, k = 0;
  while (i < L && j < M && k < N) {
    Point mid = midpoint(A[i], B[j]);

    // If midpoint is found in C array
    if (C[k].x == mid.x && C[k].y == mid.y) {
      count++;

      // If there are multiple points in C with the same midpoint
      // increment k until we reach a different midpoint
      while (k < N && C[k].x == mid.x && C[k].y == mid.y) {
        k++;
      }
      k--; // Go back one step to avoid skipping a midpoint
    } else if (mid.x < C[k].x || (mid.x == C[k].x && mid.y < C[k].y)) {
      // Midpoint is less than C[k]
      j++;
    } else {
      // Midpoint is greater than C[k]
      i++;
    }
  }

  printf("%d\n", count);

  // Free allocated memory
  free(A);
  free(B);
  free(C);

  return 0;
}