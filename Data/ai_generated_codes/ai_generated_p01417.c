#include <stdio.h>
#include <math.h>

// Structure to represent a color in Lab color space
typedef struct {
  double L;
  double a;
  double b;
} Color;

// Function to calculate the distance between two colors
double distance(Color c1, Color c2) {
  double L_diff = c1.L - c2.L;
  double a_diff = c1.a - c2.a;
  double b_diff = c1.b - c2.b;
  return sqrt(L_diff * L_diff + a_diff * a_diff + b_diff * b_diff);
}

// Function to calculate the maximum sum of distances between color pairs in a subset
double maxDistanceSum(Color colors[], int N, int M) {
  double maxSum = 0.0;

  // Iterate through all possible subsets of colors
  for (int i = 0; i < (1 << N); i++) {
    // Check if the subset has M colors
    int count = 0;
    for (int j = 0; j < N; j++) {
      if (i & (1 << j)) {
        count++;
      }
    }
    if (count == M) {
      double sum = 0.0;
      // Calculate the sum of distances between all color pairs in the subset
      for (int j = 0; j < N; j++) {
        if (i & (1 << j)) {
          for (int k = j + 1; k < N; k++) {
            if (i & (1 << k)) {
              sum += distance(colors[j], colors[k]);
            }
          }
        }
      }
      // Update the maximum sum if the current sum is larger
      maxSum = (sum > maxSum) ? sum : maxSum;
    }
  }

  return maxSum;
}

int main() {
  int N, M;
  scanf("%d %d", &N, &M);

  Color colors[N];
  for (int i = 0; i < N; i++) {
    scanf("%lf %lf %lf", &colors[i].L, &colors[i].a, &colors[i].b);
  }

  double maxDistance = maxDistanceSum(colors, N, M);
  printf("%.15lf\n", maxDistance);

  return 0;
}