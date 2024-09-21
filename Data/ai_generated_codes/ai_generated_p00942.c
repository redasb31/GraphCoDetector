#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent a point
typedef struct {
    int x;
    int y;
} Point;

// Structure to represent a polygon
typedef struct {
    int n;  // Number of vertices
    Point *vertices;
} Polygon;

// Function to calculate the dot product of two vectors
int dotProduct(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}

// Function to calculate the cross product of two vectors
int crossProduct(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

// Function to check if a point lies inside a polygon
int pointInPolygon(Point p, Polygon poly) {
    int i, j, crossings = 0;
    for (i = 0, j = poly.n - 1; i < poly.n; j = i++) {
        // Check if the horizontal ray from the point intersects an edge of the polygon
        if (((poly.vertices[i].y <= p.y && poly.vertices[j].y > p.y) ||
            (poly.vertices[i].y > p.y && poly.vertices[j].y <= p.y)) &&
            (p.x < (poly.vertices[j].x - poly.vertices[i].x) * (p.y - poly.vertices[i].y) /
             (poly.vertices[j].y - poly.vertices[i].y) + poly.vertices[i].x)) {
            crossings++;
        }
    }
    // Odd number of crossings means the point is inside the polygon
    return crossings % 2 == 1;
}

// Function to rotate a point around the origin by a given angle (in radians)
Point rotatePoint(Point p, double angle) {
    Point rotated;
    rotated.x = (int)(p.x * cos(angle) - p.y * sin(angle));
    rotated.y = (int)(p.x * sin(angle) + p.y * cos(angle));
    return rotated;
}

// Function to calculate the intersection point of two line segments
Point lineSegmentIntersection(Point p1, Point p2, Point q1, Point q2) {
    Point intersection;
    int denominator = (p2.x - p1.x) * (q2.y - q1.y) - (p2.y - p1.y) * (q2.x - q1.x);
    if (denominator == 0) {
        // Lines are parallel, no intersection
        intersection.x = -1;
        intersection.y = -1;
    } else {
        // Calculate the intersection point
        intersection.x = ((p2.x * p1.y - p1.x * p2.y) * (q2.x - q1.x) -
                     (p2.y - p1.y) * (q2.x * q1.y - q1.x * q2.y)) /
                    denominator;
        intersection.y = ((p2.x * p1.y - p1.x * p2.y) * (q2.y - q1.y) -
                     (p2.y - p1.y) * (q2.y * q1.x - q1.y * q2.x)) /
                    denominator;
    }
    return intersection;
}

// Function to check if a line segment intersects with a polygon
int lineSegmentPolygonIntersection(Point p1, Point p2, Polygon poly) {
    int i, j;
    for (i = 0, j = poly.n - 1; i < poly.n; j = i++) {
        // Check if the line segment intersects an edge of the polygon
        Point intersection = lineSegmentIntersection(p1, p2, poly.vertices[i], poly.vertices[j]);
        if (intersection.x != -1 && intersection.y != -1) {
            return 1;
        }
    }
    return 0;
}

// Function to calculate the area of a polygon
double polygonArea(Polygon poly) {
    double area = 0;
    int i, j;
    for (i = 0, j = poly.n - 1; i < poly.n; j = i++) {
        area += (poly.vertices[j].x * poly.vertices[i].y - poly.vertices[i].x * poly.vertices[j].y);
    }
    return fabs(area) / 2;
}

// Function to remove a point from a polygon
Polygon removePoint(Polygon poly, int index) {
    Polygon newPoly;
    newPoly.n = poly.n - 1;
    newPoly.vertices = malloc(sizeof(Point) * newPoly.n);
    int i;
    for (i = 0; i < index; i++) {
        newPoly.vertices[i] = poly.vertices[i];
    }
    for (i = index; i < newPoly.n; i++) {
        newPoly.vertices[i] = poly.vertices[i + 1];
    }
    return newPoly;
}

// Function to remove intersecting line segments from the workpiece polygon
Polygon removeIntersections(Polygon workpiece, Polygon cutter) {
    int i, j, k;
    for (i = 0; i < workpiece.n; i++) {
        j = (i + 1) % workpiece.n;
        // Check if the current edge of the workpiece intersects the cutter
        if (lineSegmentPolygonIntersection(workpiece.vertices[i], workpiece.vertices[j], cutter)) {
            // Find the intersection point
            Point intersection;
            for (k = 0; k < cutter.n; k++) {
                intersection = lineSegmentIntersection(workpiece.vertices[i], workpiece.vertices[j], cutter.vertices[k], cutter.vertices[(k + 1) % cutter.n]);
                if (intersection.x != -1 && intersection.y != -1) {
                    break;
                }
            }
            // Add the intersection point to the workpiece polygon
            workpiece.n++;
            workpiece.vertices = realloc(workpiece.vertices, sizeof(Point) * workpiece.n);
            workpiece.vertices[workpiece.n - 1] = intersection;
            // Remove the original edge of the workpiece
            workpiece = removePoint(workpiece, j);
            // Sort the vertices in counter-clockwise order (optional)
        }
    }
    return workpiece;
}

int main() {
    int M, N, L;
    scanf("%d %d %d", &M, &N, &L);

    // Create workpiece polygon
    Polygon workpiece;
    workpiece.n = M;
    workpiece.vertices = malloc(sizeof(Point) * workpiece.n);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &workpiece.vertices[i].x, &workpiece.vertices[i].y);
    }

    // Create cutter polygon
    Polygon cutter;
    cutter.n = N;
    cutter.vertices = malloc(sizeof(Point) * cutter.n);
    for (int i = 0; i < N; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        cutter.vertices[i].x = L + x;
        cutter.vertices[i].y = y;
    }

    // Count POI inside the workpiece
    int poiCount = 0;
    for (int x = -10000; x <= 10000; x++) {
        for (int y = -10000; y <= 10000; y++) {
            Point p = {x, y};
            if (pointInPolygon(p, workpiece)) {
                poiCount++;
            }
        }
    }

    // Rotate the cutter around its center
    double angle = 0;
    double step = 2 * M_PI / 360; // Angle increment for each rotation step
    while (angle < 2 * M_PI) {
        // Rotate the cutter
        for (int i = 0; i < cutter.n; i++) {
            cutter.vertices[i] = rotatePoint(cutter.vertices[i], angle);
        }
        // Remove intersection points from the workpiece
        workpiece = removeIntersections(workpiece, cutter);
        angle += step;
    }

    // Count remaining POI after rotation
    int remainingPoiCount = 0;
    for (int x = -10000; x <= 10000; x++) {
        for (int y = -10000; y <= 10000; y++) {
            Point p = {x, y};
            if (pointInPolygon(p, workpiece)) {
                remainingPoiCount++;
            }
        }
    }

    printf("%d\n", remainingPoiCount);

    // Free allocated memory
    free(workpiece.vertices);
    free(cutter.vertices);

    return 0;
}