#include <stdio.h>
#include <math.h>

#define MAX_N 60

double distance(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
  int N, K;
  int x[MAX_N], y[MAX_N], c[MAX_N];
  double min_time = 1e9; // Initialize with a large value

  scanf("%d %d", &N, &K);

  // Input coordinates and hardness of each meat piece
  for (int i = 0; i < N; ++i) {
    scanf("%d %d %d", &x[i], &y[i], &c[i]);
  }

  // Brute force search for the optimal heat source position
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      // Calculate time to cook K pieces of meat with heat source at (x[i], y[j])
      double time = 0.0;
      int count = 0;
      for (int k = 0; k < N; ++k) {
        time = c[k] * distance(x[i], y[j], x[k], y[k]);
        if (time <= min_time) {
          count++;
        }
        if (count >= K) {
          min_time = time;
          break;
        }
      }
    }
  }

  printf("%.6f\n", min_time);

  return 0;
}