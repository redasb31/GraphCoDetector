#include <stdio.h>

int main() {
  int n; // Number of test cases
  scanf("%d", &n);

  // Iterate through each test case
  for (int i = 0; i < n; i++) {
    int x_bb, y_bb; // Input values
    scanf("%d %d", &x_bb, &y_bb);

    // Output the number of vertices
    printf("4\n");

    // Output the coordinates of the vertices, forming a rectangle
    printf("%d %d\n", x_bb, y_bb); 
    printf("0 %d\n", y_bb); 
    printf("0 0\n");
    printf("%d 0\n", x_bb);
  }

  return 0;
}