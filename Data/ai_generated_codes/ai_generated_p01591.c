#include <stdio.h>
#include <math.h>

// Structure to store a point
typedef struct {
  double x;
  double y;
} Point;

// Function to calculate the sum of squared distances between points and the circle
double calculateError(Point points[], int n, double a, double b, double c) {
  double error = 0;
  for (int i = 0; i < n; i++) {
    // Calculate the distance from the point to the circle
    double distance = sqrt(pow(points[i].x, 2) + pow(points[i].y, 2) + a * points[i].x + b * points[i].y + c);
    // Square the distance and add it to the total error
    error += pow(distance, 2);
  }
  return error;
}

// Function to find the coefficients of the circle using gradient descent
void findCircle(Point points[], int n, double *a, double *b, double *c) {
  // Initialize the coefficients with random values
  *a = 0;
  *b = 0;
  *c = 0;

  // Learning rate for gradient descent
  double learningRate = 0.0001;

  // Number of iterations for gradient descent
  int iterations = 1000;

  // Perform gradient descent to minimize the error
  for (int i = 0; i < iterations; i++) {
    // Calculate the partial derivatives of the error function with respect to a, b, and c
    double da = 0;
    double db = 0;
    double dc = 0;
    for (int j = 0; j < n; j++) {
      double distance = sqrt(pow(points[j].x, 2) + pow(points[j].y, 2) + *a * points[j].x + *b * points[j].y + *c);
      da += (points[j].x * distance);
      db += (points[j].y * distance);
      dc += distance;
    }

    // Update the coefficients using the gradient descent formula
    *a -= learningRate * da;
    *b -= learningRate * db;
    *c -= learningRate * dc;
  }
}

int main() {
  int n;
  scanf("%d", &n);

  Point points[n];

  // Read the coordinates of the points
  for (int i = 0; i < n; i++) {
    scanf("%lf %lf", &points[i].x, &points[i].y);
  }

  // Find the coefficients of the circle using gradient descent
  double a, b, c;
  findCircle(points, n, &a, &b, &c);

  // Print the coefficients of the circle
  printf("%.3lf %.3lf %.3lf\n", a, b, c);

  return 0;
}