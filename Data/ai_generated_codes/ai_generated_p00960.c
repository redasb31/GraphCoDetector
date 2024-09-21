#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100000
#define EPS 1e-9

typedef struct {
    double x;
    double y;
} Point;

// Function to calculate the distance between two points
double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// Function to calculate the cross product of two vectors
double crossProduct(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// Function to determine if a point is inside the convex hull
int insideHull(Point p, Point *hull, int n) {
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        if (crossProduct(hull[i], hull[j], p) > EPS) {
            return 0;
        }
    }
    return 1;
}

// Function to find the convex hull using Graham's scan algorithm
int convexHull(Point *points, int n, Point *hull) {
    // Sort points by x-coordinate, then y-coordinate
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (points[i].x > points[j].x ||
                (points[i].x == points[j].x && points[i].y > points[j].y)) {
                Point temp = points[i];
                points[i] = points[j];
                points[j] = temp;
            }
        }
    }

    // Find the lowest point
    int bottom = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < points[bottom].y ||
            (points[i].y == points[bottom].y && points[i].x < points[bottom].x)) {
            bottom = i;
        }
    }

    // Swap the lowest point to the first position
    Point temp = points[0];
    points[0] = points[bottom];
    points[bottom] = temp;

    // Sort remaining points by polar angle relative to the lowest point
    for (int i = 1; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double angle1 = atan2(points[i].y - points[0].y, points[i].x - points[0].x);
            double angle2 = atan2(points[j].y - points[0].y, points[j].x - points[0].x);
            if (angle1 > angle2 ||
                (angle1 == angle2 && distance(points[0], points[i]) > distance(points[0], points[j]))) {
                Point temp = points[i];
                points[i] = points[j];
                points[j] = temp;
            }
        }
    }

    // Build the convex hull
    int hullSize = 0;
    hull[hullSize++] = points[0];
    hull[hullSize++] = points[1];
    for (int i = 2; i < n; i++) {
        while (hullSize >= 2 && crossProduct(hull[hullSize - 2], hull[hullSize - 1], points[i]) <= EPS) {
            hullSize--;
        }
        hull[hullSize++] = points[i];
    }

    return hullSize;
}

// Function to calculate the perimeter of a convex hull
double calculatePerimeter(Point *hull, int hullSize) {
    double perimeter = 0;
    for (int i = 0; i < hullSize; i++) {
        int j = (i + 1) % hullSize;
        perimeter += distance(hull[i], hull[j]);
    }
    return perimeter;
}

int main() {
    int n;
    Point points[MAX_POINTS];
    Point hull[MAX_POINTS];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    // Find the original convex hull
    int hullSize = convexHull(points, n, hull);

    // Calculate the perimeter of the original convex hull
    double originalPerimeter = calculatePerimeter(hull, hullSize);

    // Find the shortest perimeter of the convex hull after excluding two points
    double shortestPerimeter = originalPerimeter;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Exclude points i and j
            Point newPoints[MAX_POINTS];
            int newN = 0;
            for (int k = 0; k < n; k++) {
                if (k != i && k != j) {
                    newPoints[newN++] = points[k];
                }
            }

            // Find the convex hull of the new set
            int newHullSize = convexHull(newPoints, newN, hull);

            // Calculate the perimeter of the new convex hull
            double newPerimeter = calculatePerimeter(hull, newHullSize);

            // Update the shortest perimeter if necessary
            if (newPerimeter < shortestPerimeter) {
                shortestPerimeter = newPerimeter;
            }
        }
    }

    // Calculate the difference in perimeter
    double difference = originalPerimeter - shortestPerimeter;
    printf("%.10lf\n", difference);

    return 0;
}