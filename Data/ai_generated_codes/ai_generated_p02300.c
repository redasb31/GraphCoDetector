#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100000

// Structure to represent a point
typedef struct {
    int x;
    int y;
} Point;

// Function to calculate the cross product of two vectors
int crossProduct(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// Function to compare two points based on their x-coordinate and then y-coordinate
int comparePoints(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;

    if (p1->x == p2->x) {
        return p1->y - p2->y;
    } else {
        return p1->x - p2->x;
    }
}

// Function to find the convex hull using the Graham Scan algorithm
void convexHull(Point points[], int n) {
    // Sort the points by x-coordinate and then y-coordinate
    qsort(points, n, sizeof(Point), comparePoints);

    // Create two stacks: upperHull and lowerHull
    Point upperHull[MAX_POINTS];
    Point lowerHull[MAX_POINTS];
    int upperHullSize = 0;
    int lowerHullSize = 0;

    // Add the first three points to both stacks
    upperHull[upperHullSize++] = points[0];
    upperHull[upperHullSize++] = points[1];
    lowerHull[lowerHullSize++] = points[0];
    lowerHull[lowerHullSize++] = points[1];

    // Iterate through the remaining points
    for (int i = 2; i < n; i++) {
        // Add points to the upper hull
        while (upperHullSize >= 2 && crossProduct(upperHull[upperHullSize - 2], upperHull[upperHullSize - 1], points[i]) <= 0) {
            upperHullSize--;
        }
        upperHull[upperHullSize++] = points[i];

        // Add points to the lower hull
        while (lowerHullSize >= 2 && crossProduct(lowerHull[lowerHullSize - 2], lowerHull[lowerHullSize - 1], points[i]) >= 0) {
            lowerHullSize--;
        }
        lowerHull[lowerHullSize++] = points[i];
    }

    // Combine the upper and lower hulls (excluding the last point of both hulls)
    int hullSize = upperHullSize + lowerHullSize - 2;

    // Print the number of points in the convex hull
    printf("%d\n", hullSize);

    // Print the points of the convex hull in counter-clockwise order
    for (int i = 0; i < upperHullSize - 1; i++) {
        printf("%d %d\n", upperHull[i].x, upperHull[i].y);
    }
    for (int i = lowerHullSize - 2; i >= 1; i--) {
        printf("%d %d\n", lowerHull[i].x, lowerHull[i].y);
    }
}

int main() {
    int n;
    Point points[MAX_POINTS];

    // Read the input
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    // Find and print the convex hull
    convexHull(points, n);

    return 0;
}