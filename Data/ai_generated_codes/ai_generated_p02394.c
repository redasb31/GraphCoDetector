#include <stdio.h>

int main() {
  // Declare variables to store input values
  int W, H, x, y, r;

  // Read input values from the user
  scanf("%d %d %d %d %d", &W, &H, &x, &y, &r);

  // Check if the circle is inside the rectangle
  if (x - r >= 0 && x + r <= W && y - r >= 0 && y + r <= H) {
    // If the circle is inside the rectangle, print "Yes"
    printf("Yes\n");
  } else {
    // If the circle is not inside the rectangle, print "No"
    printf("No\n");
  }

  return 0;
}