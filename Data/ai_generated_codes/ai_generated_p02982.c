#include <stdio.h>
#include <math.h>

// Function to calculate the distance between two points
double distance(int* point1, int* point2, int D) {
  double sum = 0;
  for (int i = 0; i < D; i++) {
    sum += pow(point1[i] - point2[i], 2);
  }
  return sqrt(sum);
}

int main() {
  int N, D; // Number of points and dimensions
  scanf("%d %d", &N, &D);

  // Array to store the coordinates of each point
  int points[N][D];

  // Input the coordinates of each point
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < D; j++) {
      scanf("%d", &points[i][j]);
    }
  }

  // Variable to store the count of pairs with integer distance
  int count = 0;

  // Iterate through all pairs of points
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      // Calculate the distance between the two points
      double dist = distance(points[i], points[j], D);
      // Check if the distance is an integer
      if (floor(dist) == dist) {
        count++;
      }
    }
  }

  // Print the count of pairs with integer distance
  printf("%d\n", count);

  return 0;
}