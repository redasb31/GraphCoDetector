#include <stdio.h>
#include <stdlib.h>

// Structure to represent a rectangle
typedef struct {
  int x1, y1, x2, y2;
} Rectangle;

// Function to compare two rectangles based on their x1 coordinate
int compare_rectangles(const void *a, const void *b) {
  Rectangle *rect1 = (Rectangle *)a;
  Rectangle *rect2 = (Rectangle *)b;
  return rect1->x1 - rect2->x1;
}

// Function to calculate the area of the union of rectangles
int calculate_union_area(Rectangle *rectangles, int n) {
  // Sort the rectangles based on their x1 coordinate
  qsort(rectangles, n, sizeof(Rectangle), compare_rectangles);

  // Initialize the area of the union
  int area = 0;

  // Iterate through the rectangles
  for (int i = 0; i < n; i++) {
    // Get the current rectangle
    Rectangle current_rect = rectangles[i];

    // Initialize the current y-coordinate
    int current_y = current_rect.y1;

    // Iterate through the remaining rectangles
    for (int j = i + 1; j < n; j++) {
      // Get the next rectangle
      Rectangle next_rect = rectangles[j];

      // Check if the next rectangle overlaps with the current rectangle
      if (next_rect.x1 <= current_rect.x2) {
        // Update the current y-coordinate to the maximum of the current and next rectangle's y1 coordinates
        current_y = (current_y > next_rect.y1) ? current_y : next_rect.y1;

        // If the next rectangle's y2 coordinate is greater than the current rectangle's y2 coordinate, update the current rectangle's y2 coordinate
        if (next_rect.y2 > current_rect.y2) {
          current_rect.y2 = next_rect.y2;
        }
      } else {
        // If the next rectangle does not overlap with the current rectangle, break the loop
        break;
      }
    }

    // Add the area of the current rectangle to the total area
    area += (current_rect.x2 - current_rect.x1) * (current_rect.y2 - current_y);
  }

  // Return the total area of the union
  return area;
}

int main() {
  // Read the number of rectangles
  int n;
  scanf("%d", &n);

  // Allocate memory for the rectangles
  Rectangle *rectangles = (Rectangle *)malloc(n * sizeof(Rectangle));

  // Read the coordinates of the rectangles
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d %d", &rectangles[i].x1, &rectangles[i].y1, &rectangles[i].x2, &rectangles[i].y2);
  }

  // Calculate the area of the union of rectangles
  int area = calculate_union_area(rectangles, n);

  // Print the area
  printf("%d\n", area);

  // Free the allocated memory
  free(rectangles);

  return 0;
}