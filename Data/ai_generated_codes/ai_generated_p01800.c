#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to calculate the angle between two points
double calculateAngle(double x1, double y1, double x2, double y2) {
  double angle = atan2(y2 - y1, x2 - x1);
  if (angle < 0) {
    angle += 2 * PI;
  }
  return angle;
}

// Function to find the maximum speed
double findMaxSpeed(double x, double y, double theta, double omega) {
  double angle = calculateAngle(0, 0, x, y);
  double distance = sqrt(x * x + y * y);
  double speed = distance * omega / (PI * (angle - theta));
  return speed;
}

int main() {
  double x, y, theta, omega;
  scanf("%lf %lf %lf %lf", &x, &y, &theta, &omega);
  theta = theta * PI / 180; // Convert theta to radians
  omega = omega * PI / 180; // Convert omega to radians
  double speed = findMaxSpeed(x, y, theta, omega);
  printf("%.10lf\n", speed);
  return 0;
}