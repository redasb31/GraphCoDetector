#include <stdio.h>
#include <math.h>

// Function to calculate the distance between two points
double distance(double x1, double y1, double x2, double y2) {
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// Function to check if the circles are within the rectangle with margin of error
int check_circles(double x_a, double y_a, double r_a, double x_b, double y_b, double r_b, int u_w, int u_h) {
  return (x_a - r_a >= -0.0001 && x_a + r_a <= u_w + 0.0001 &&
          y_a - r_a >= -0.0001 && y_a + r_a <= u_h + 0.0001 &&
          x_b - r_b >= -0.0001 && x_b + r_b <= u_w + 0.0001 &&
          y_b - r_b >= -0.0001 && y_b + r_b <= u_h + 0.0001);
}

// Function to find the centers and radii of the circles
void find_circles(int u_w, int u_h, int a, int b, int intersection) {
  // Calculate the areas of the circles
  double area_a = (double)a;
  double area_b = (double)b;
  double area_intersection = (double)intersection;

  // Calculate the radii of the circles
  double r_a = sqrt(area_a / M_PI);
  double r_b = sqrt(area_b / M_PI);

  // Calculate the distance between the centers of the circles
  double d = sqrt(2 * (area_a + area_b - 2 * area_intersection) / M_PI);

  // Find the centers of the circles
  double x_a = u_w / 2.0;
  double y_a = u_h / 2.0;
  double x_b = x_a + d / 2.0;
  double y_b = y_a;

  // Check if the circles are within the rectangle with margin of error
  if (check_circles(x_a, y_a, r_a, x_b, y_b, r_b, u_w, u_h)) {
    // Check if the areas of the parts are within the error margin
    double area_a_calculated = M_PI * r_a * r_a;
    double area_b_calculated = M_PI * r_b * r_b;
    double area_intersection_calculated = M_PI * (r_a * r_a + r_b * r_b - d * d / 4);

    if (fabs(area_a_calculated - area_a) <= 0.0001 &&
        fabs(area_b_calculated - area_b) <= 0.0001 &&
        fabs(area_intersection_calculated - area_intersection) <= 0.0001) {
      // Print the centers and radii of the circles
      printf("%.6lf %.6lf %.6lf %.6lf %.6lf %.6lf\n", x_a, y_a, r_a, x_b, y_b, r_b);
    } else {
      printf("impossible\n");
    }
  } else {
    printf("impossible\n");
  }
}

int main() {
  int u_w, u_h, a, b, intersection;

  // Read input until five zeroes are encountered
  while (scanf("%d %d %d %d %d", &u_w, &u_h, &a, &b, &intersection) != EOF &&
         (u_w != 0 || u_h != 0 || a != 0 || b != 0 || intersection != 0)) {
    find_circles(u_w, u_h, a, b, intersection);
  }

  return 0;
}