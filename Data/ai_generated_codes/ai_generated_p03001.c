#include <stdio.h>
#include <math.h>

int main() {
  // Read input
  long long W, H, x, y;
  scanf("%lld %lld %lld %lld", &W, &H, &x, &y);

  // Calculate areas of the four possible quadrilaterals formed by cutting the rectangle
  long long area1 = x * y;
  long long area2 = (W - x) * y;
  long long area3 = x * (H - y);
  long long area4 = (W - x) * (H - y);

  // Find the minimum area among the four
  long long min_area = area1;
  if (area2 < min_area) {
    min_area = area2;
  }
  if (area3 < min_area) {
    min_area = area3;
  }
  if (area4 < min_area) {
    min_area = area4;
  }

  // Calculate the maximum area of the smaller part
  long long max_area = (W * H) / 2 - min_area;

  // Determine if there are multiple ways to achieve the maximum area
  int multiple_ways = 0;
  if (area1 == min_area && area4 == min_area) {
    multiple_ways = 1;
  } else if (area2 == min_area && area3 == min_area) {
    multiple_ways = 1;
  }

  // Print the output
  printf("%.6lf %d\n", (double)max_area, multiple_ways);

  return 0;
}