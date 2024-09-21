#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Structure to represent a line segment
typedef struct {
    int x0, y0; // Starting point
    int x1, y1; // Ending point
} LineSegment;

// Structure to represent a point
typedef struct {
    double x, y;
} Point;

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// Function to calculate the angle between two line segments
double angle(LineSegment l1, LineSegment l2) {
    double dx1 = l1.x1 - l1.x0;
    double dy1 = l1.y1 - l1.y0;
    double dx2 = l2.x1 - l2.x0;
    double dy2 = l2.y1 - l2.y0;
    return acos((dx1 * dx2 + dy1 * dy2) / (sqrt(dx1 * dx1 + dy1 * dy1) * sqrt(dx2 * dx2 + dy2 * dy2)));
}

// Function to calculate the length of a circular arc
double arcLength(LineSegment l1, LineSegment l2) {
    double theta = angle(l1, l2);
    double radius = distance(l1.x1, l1.y1, l2.x0, l2.y0);
    return theta * radius;
}

// Function to calculate the shortest route length for a given circuit
double shortestRouteLength(LineSegment *segments, int n) {
    double totalLength = 0;

    // Iterate over all line segments and calculate the length of each
    for (int i = 0; i < n; i++) {
        totalLength += distance(segments[i].x0, segments[i].y0, segments[i].x1, segments[i].y1);
    }

    // Iterate over all pairs of consecutive line segments and calculate the length of the circular arc connecting them
    for (int i = 0; i < n; i++) {
        totalLength += arcLength(segments[i], segments[(i + 1) % n]);
    }

    // Find the shortest route length by checking all possible shortcuts
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Calculate the distance between the starting point of segment i and the ending point of segment j
            double shortcutLength = distance(segments[i].x0, segments[i].y0, segments[j].x1, segments[j].y1);

            // Calculate the length of the circuit portion between segment i and segment j
            double circuitLength = 0;
            for (int k = i + 1; k <= j; k++) {
                circuitLength += distance(segments[k].x0, segments[k].y0, segments[k].x1, segments[k].y1);
            }

            // If the shortcut length is shorter than the circuit length, update the shortest route length
            if (shortcutLength < circuitLength) {
                totalLength -= circuitLength;
                totalLength += shortcutLength;
            }
        }
    }

    return totalLength;
}

int main() {
    int n;
    scanf("%d", &n);

    LineSegment *segments = malloc(sizeof(LineSegment) * n);
    if (segments == NULL) {
        fprintf(stderr, "Memory allocation error!\n");
        exit(1);
    }

    // Read the line segments from the input
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &segments[i].x0, &segments[i].y0, &segments[i].x1, &segments[i].y1);
    }

    // Calculate and print the shortest route length
    double shortestLength = shortestRouteLength(segments, n);
    printf("%.3lf\n", shortestLength);

    free(segments);
    return 0;
}