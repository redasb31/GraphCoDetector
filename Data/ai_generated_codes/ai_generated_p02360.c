#include <stdio.h>
#include <stdlib.h>

// Structure to represent a rectangle
typedef struct {
    int x1, y1;  // Top-left corner coordinates
    int x2, y2;  // Bottom-right corner coordinates
} Rectangle;

// Function to compare two rectangles based on their x1 coordinates
int compareRectangles(const void *a, const void *b) {
    Rectangle *rect1 = (Rectangle *)a;
    Rectangle *rect2 = (Rectangle *)b;
    return rect1->x1 - rect2->x1;
}

// Function to find the maximum number of overlaps
int findMaxOverlaps(Rectangle *rectangles, int n) {
    // Sort rectangles by their x1 coordinates
    qsort(rectangles, n, sizeof(Rectangle), compareRectangles);

    // Create a segment tree to store the rectangles
    // Note: The code assumes the segment tree implementation is available
    // You can use a standard segment tree library or implement one yourself
    // The segment tree should support range queries (to find the maximum value)
    // and point updates (to increase the count of overlaps at a specific x-coordinate)

    int maxOverlaps = 0;
    int currentOverlaps = 0;

    // Iterate over the rectangles
    for (int i = 0; i < n; i++) {
        // Update the segment tree with the current rectangle
        // Increment the count of overlaps in the range [x1, x2)
        updateSegmentTree(rectangles[i].x1, rectangles[i].x2, 1);

        // Query the segment tree to get the maximum number of overlaps at the current x-coordinate
        currentOverlaps = querySegmentTree(rectangles[i].x1, rectangles[i].x2);

        // Update the maximum number of overlaps if necessary
        maxOverlaps = (currentOverlaps > maxOverlaps) ? currentOverlaps : maxOverlaps;
    }

    return maxOverlaps;
}

int main() {
    int n;
    scanf("%d", &n);

    // Allocate memory for rectangles
    Rectangle *rectangles = (Rectangle *)malloc(n * sizeof(Rectangle));

    // Read rectangle coordinates from input
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &rectangles[i].x1, &rectangles[i].y1, &rectangles[i].x2, &rectangles[i].y2);
    }

    // Find the maximum number of overlaps
    int maxOverlaps = findMaxOverlaps(rectangles, n);

    // Print the result
    printf("%d\n", maxOverlaps);

    // Free allocated memory
    free(rectangles);

    return 0;
}