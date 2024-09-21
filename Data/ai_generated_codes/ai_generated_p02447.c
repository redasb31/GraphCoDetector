#include <stdio.h>
#include <stdlib.h>

// Structure to represent a point
typedef struct {
    int x;
    int y;
} Point;

// Function to compare two points based on x-coordinate and then y-coordinate
int compare_points(const void *a, const void *b) {
    Point *pa = (Point *)a;
    Point *pb = (Point *)b;

    // Compare x-coordinates
    if (pa->x != pb->x) {
        return pa->x - pb->x;
    } else {
        // If x-coordinates are equal, compare y-coordinates
        return pa->y - pb->y;
    }
}

int main() {
    int n;

    // Read the number of points
    scanf("%d", &n);

    // Allocate memory for points
    Point *points = (Point *)malloc(n * sizeof(Point));

    // Read the coordinates of each point
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    // Sort the points using qsort with the custom comparison function
    qsort(points, n, sizeof(Point), compare_points);

    // Print the sorted points
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", points[i].x, points[i].y);
    }

    // Free allocated memory
    free(points);

    return 0;
}