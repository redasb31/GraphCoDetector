#include <stdio.h>

int main() {
  // Declare variables to store the input integers
  int a, b, c;

  // Read the three integers from the user
  scanf("%d %d %d", &a, &b, &c);

  // Check if the condition a < b < c holds true
  if (a < b && b < c) {
    // If true, print "Yes"
    printf("Yes\n");
  } else {
    // Otherwise, print "No"
    printf("No\n");
  }

  return 0;
}