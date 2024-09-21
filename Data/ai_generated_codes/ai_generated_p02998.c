#include <stdio.h>
#include <stdlib.h>

// Structure to represent a point in the 2D plane
typedef struct {
    int x;
    int y;
} Point;

// Function to compare two points based on their x-coordinates
int compare_x(const void *a, const void *b) {
    Point *pa = (Point *)a;
    Point *pb = (Point *)b;
    return pa->x - pb->x;
}

// Function to compare two points based on their y-coordinates
int compare_y(const void *a, const void *b) {
    Point *pa = (Point *)a;
    Point *pb = (Point *)b;
    return pa->y - pb->y;
}

// Function to find the maximum number of operations
int max_operations(Point *points, int n) {
    // Sort points based on x-coordinates
    qsort(points, n, sizeof(Point), compare_x);

    // Initialize the maximum number of operations
    int max_ops = 0;

    // Iterate over all possible pairs of x-coordinates
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Find the number of points with the same x-coordinate as points[i] and points[j]
            int count_x = 0;
            for (int k = 0; k < n; k++) {
                if (points[k].x == points[i].x || points[k].x == points[j].x) {
                    count_x++;
                }
            }

            // Find the number of points with the same y-coordinate as points[i] and points[j]
            int count_y = 0;
            for (int k = 0; k < n; k++) {
                if (points[k].y == points[i].y || points[k].y == points[j].y) {
                    count_y++;
                }
            }

            // Calculate the maximum number of operations for this pair of x-coordinates
            int ops = (count_x - 2) * (count_y - 2);

            // Update the maximum number of operations
            max_ops = (ops > max_ops) ? ops : max_ops;
        }
    }

    return max_ops;
}

int main() {
    // Read the number of points
    int n;
    scanf("%d", &n);

    // Allocate memory for the points
    Point *points = (Point *)malloc(n * sizeof(Point));

    // Read the coordinates of the points
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    // Find the maximum number of operations
    int max_ops = max_operations(points, n);

    // Print the result
    printf("%d\n", max_ops);

    // Free the allocated memory
    free(points);

    return 0;
}