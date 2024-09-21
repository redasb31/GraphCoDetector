#include <stdio.h>
#include <math.h>

#define MAX_POINTS 300

// Structure to represent a point
struct Point {
    double x;
    double y;
};

// Function to calculate the distance between two points
double distance(struct Point p1, struct Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Function to check if a point is inside or on the circle
int isInsideCircle(struct Point center, struct Point point) {
    return distance(center, point) <= 1.0;
}

// Function to find the maximum number of points enclosed by a circle
int findMaxEnclosedPoints(struct Point points[], int n) {
    int maxEnclosed = 0;

    // Iterate over all points as potential centers
    for (int i = 0; i < n; i++) {
        int enclosedCount = 0;

        // Check if each point is inside or on the circle centered at the current point
        for (int j = 0; j < n; j++) {
            if (isInsideCircle(points[i], points[j])) {
                enclosedCount++;
            }
        }

        // Update the maximum enclosed count
        maxEnclosed = (enclosedCount > maxEnclosed) ? enclosedCount : maxEnclosed;
    }

    return maxEnclosed;
}

int main() {
    int n;
    struct Point points[MAX_POINTS];

    // Read input until '0' is encountered
    while (scanf("%d", &n) != EOF && n != 0) {
        // Read point coordinates
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &points[i].x, &points[i].y);
        }

        // Find and print the maximum number of enclosed points
        printf("%d\n", findMaxEnclosedPoints(points, n));
    }

    return 0;
}