#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent a point
typedef struct {
    double x;
    double y;
} Point;

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Function to find the closest pair of points using brute force
double closestPairBruteForce(Point points[], int n) {
    // Initialize minimum distance to a large value
    double minDistance = 1e9;

    // Iterate through all pairs of points
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Calculate the distance between the current pair of points
            double dist = distance(points[i], points[j]);

            // Update the minimum distance if necessary
            if (dist < minDistance) {
                minDistance = dist;
            }
        }
    }

    return minDistance;
}

int main() {
    // Read the number of points
    int n;
    scanf("%d", &n);

    // Allocate memory for the points
    Point *points = (Point *)malloc(n * sizeof(Point));

    // Read the coordinates of the points
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    // Find the closest pair of points using brute force
    double closestDistance = closestPairBruteForce(points, n);

    // Print the closest distance
    printf("%.6lf\n", closestDistance);

    // Free the allocated memory
    free(points);

    return 0;
}