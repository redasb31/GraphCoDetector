#include <stdio.h>
#include <math.h>

int main() {
  double v; // Minimum velocity to crack the ball
  double t; // Time taken to reach the velocity
  int floor; // Floor number
  
  while (scanf("%lf", &v) != EOF) { // Read input until end of file
    t = v / 9.8; // Calculate time to reach the minimum velocity
    floor = (int)ceil((4.9 * pow(t, 2) + 5) / 5); // Calculate the floor
    printf("%d\n", floor); // Print the floor number
  }
  return 0;
}