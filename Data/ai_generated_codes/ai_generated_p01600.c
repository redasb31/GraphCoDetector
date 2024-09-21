#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent a point
typedef struct Point {
    int x;
    int y;
} Point;

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Function to find the shortest total length of edges in the tree
double shortestTreeLength(Point points[], int n) {
    double totalLength = 0;
    // Iterate through the points starting from the second point
    for (int i = 1; i < n; i++) {
        // Find the closest point with a smaller x-coordinate
        int closestIndex = i - 1;
        for (int j = i - 2; j >= 0; j--) {
            if (distance(points[i], points[j]) < distance(points[i], points[closestIndex])) {
                closestIndex = j;
            }
        }
        // Add the distance between the current point and the closest point to the total length
        totalLength += distance(points[i], points[closestIndex]);
    }
    return totalLength;
}

int main() {
    int n;
    scanf("%d", &n);
    // Allocate memory for the points array
    Point *points = (Point *)malloc(n * sizeof(Point));
    // Read the points from the input
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }
    // Calculate and print the shortest total length of edges
    printf("%.0lf\n", shortestTreeLength(points, n));
    // Free the allocated memory
    free(points);
    return 0;
}