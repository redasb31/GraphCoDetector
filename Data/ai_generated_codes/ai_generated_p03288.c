#include <stdio.h>

int main() {
  // Declare the variable to store the rating
  int R;

  // Read the rating from the standard input
  scanf("%d", &R);

  // Determine the next rated contest based on the rating
  if (R < 1200) {
    printf("ABC\n"); // ABC is rated for contestants with ratings less than 1200
  } else if (R < 2800) {
    printf("ARC\n"); // ARC is rated for contestants with ratings less than 2800
  } else {
    printf("AGC\n"); // AGC is rated for all contestants
  }

  return 0;
}