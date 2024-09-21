#include <stdio.h>
#include <math.h>

int main() {
  // Declare the variable to store the input length L
  double L;

  // Read the input length L from the user
  scanf("%lf", &L);

  // Calculate the maximum possible volume of the rectangular cuboid
  // The maximum volume is achieved when the dimensions are as close to each other as possible
  // Therefore, we divide the length L by 3 to get the side length of a cube
  // and then cube the side length to get the volume
  double volume = pow(L / 3, 3);

  // Print the maximum possible volume
  printf("%.12lf\n", volume);

  return 0;
}