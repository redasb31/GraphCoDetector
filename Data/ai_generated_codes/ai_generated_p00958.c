#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent a point
typedef struct {
    int x;
    int y;
} Point;

// Function to calculate the slope of a line given two points
double calculateSlope(Point p1, Point p2) {
    if (p2.x - p1.x == 0) {
        return INFINITY; // Handle vertical lines
    } else {
        return (double)(p2.y - p1.y) / (p2.x - p1.x);
    }
}

// Function to check if two lines are parallel
int areLinesParallel(Point p1, Point p2, Point p3, Point p4) {
    double slope1 = calculateSlope(p1, p2);
    double slope2 = calculateSlope(p3, p4);
    return fabs(slope1 - slope2) < 1e-6; // Use a small tolerance for floating-point comparison
}

// Function to find the maximum number of parallel line pairs
int maxParallelPairs(Point points[], int n) {
    int maxPairs = 0;

    // Iterate through all possible pairings of points
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Count the number of parallel lines for the current pairing
            int pairs = 0;
            for (int k = 0; k < n - 1; k++) {
                for (int l = k + 1; l < n; l++) {
                    if (areLinesParallel(points[i], points[j], points[k], points[l])) {
                        pairs++;
                    }
                }
            }

            // Update the maximum number of pairs if necessary
            maxPairs = (pairs > maxPairs) ? pairs : maxPairs;
        }
    }

    return maxPairs;
}

int main() {
    int n;
    scanf("%d", &n);

    // Allocate memory for the points
    Point *points = (Point *)malloc(n * sizeof(Point));

    // Read the points from input
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    // Calculate the maximum number of parallel line pairs
    int maxPairs = maxParallelPairs(points, n);

    // Print the result
    printf("%d\n", maxPairs);

    // Free the allocated memory
    free(points);

    return 0;
}