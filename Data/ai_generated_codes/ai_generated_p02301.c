#include <stdio.h>
#include <math.h>

#define MAX_N 80000

typedef struct {
    double x, y;
} Point;

// Calculate the distance between two points
double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main() {
    int n;
    Point points[MAX_N];

    // Read the number of points and their coordinates
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    // Initialize the diameter to the distance between the first two points
    double diameter = distance(points[0], points[1]);

    // Iterate through all pairs of points and update the diameter if a larger distance is found
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dist = distance(points[i], points[j]);
            if (dist > diameter) {
                diameter = dist;
            }
        }
    }

    // Print the diameter
    printf("%.6lf\n", diameter);

    return 0;
}