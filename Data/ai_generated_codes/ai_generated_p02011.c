#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 200
#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
} Point;

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Function to find the maximum radius of a circle centered at a given point
// without overlapping other circles
double maxRadius(Point point, Point points[], int n, double radii[]) {
    double maxRadius = 100; // Initialize with maximum possible radius
    for (int i = 0; i < n; i++) {
        if (i != point) {
            double dist = distance(point, points[i]);
            if (dist - radii[i] < maxRadius) {
                maxRadius = dist - radii[i];
            }
        }
    }
    return maxRadius;
}

int main() {
    int n;
    scanf("%d", &n);

    Point points[MAX_POINTS];
    double radii[MAX_POINTS] = {0}; // Initialize radii to 0

    // Input points
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    // Calculate maximum radii for each circle
    for (int i = 0; i < n; i++) {
        radii[i] = maxRadius(points[i], points, n, radii);
    }

    // Calculate the sum of perimeters
    double sumPerimeter = 0;
    for (int i = 0; i < n; i++) {
        sumPerimeter += 2 * PI * radii[i];
    }

    // Output the result
    printf("%.12lf\n", sumPerimeter);

    return 0;
}