#include <stdio.h>

int main() {
  // Input variables
  int W, D, N, M, T;
  
  // Read input values
  scanf("%d %d %d %d %d", &W, &D, &N, &M, &T);

  // Calculate the total distance between the rightmost hand and the leftmost package
  int total_distance = (N - 1) * M + W;

  // Calculate the number of packages that can be covered by the hands in T seconds
  int covered_packages = (total_distance + T - 1) / (W + D);

  // Calculate the number of packages with no tampopos
  int uncovered_packages = N - covered_packages;

  // Calculate the ratio of packages with no tampopos
  double ratio = (double) uncovered_packages / N;

  // Print the ratio
  printf("%.12lf\n", ratio);

  return 0;
}