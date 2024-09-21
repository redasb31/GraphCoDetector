#include <stdio.h>
#include <math.h>

// Structure to represent a point
typedef struct {
    double x;
    double y;
} Point;

// Function to calculate the dot product of two vectors
double dotProduct(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}

// Function to calculate the cross product of two vectors
double crossProduct(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

// Function to calculate the distance between two points
double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Function to calculate the area of a triangle
double triangleArea(Point a, Point b, Point c) {
    return 0.5 * abs(crossProduct(b, a) + crossProduct(c, b) + crossProduct(a, c));
}

// Function to check if a point is inside a polygon
int isInsidePolygon(Point p, Point polygon[], int n) {
    int crossings = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        if ((polygon[i].y <= p.y && polygon[j].y > p.y) || (polygon[j].y <= p.y && polygon[i].y > p.y)) {
            double xIntersection = polygon[i].x + (p.y - polygon[i].y) * (polygon[j].x - polygon[i].x) / (polygon[j].y - polygon[i].y);
            if (xIntersection > p.x) {
                crossings++;
            }
        }
    }
    return (crossings % 2 == 1);
}

// Function to find the maximum intersection area of a polygon and a disk
double maxIntersectionArea(Point polygon[], int n, double radius) {
    double maxArea = 0;
    // Iterate over all edges of the polygon
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        // Find the center of the edge
        Point edgeCenter = { (polygon[i].x + polygon[j].x) / 2, (polygon[i].y + polygon[j].y) / 2 };
        // Calculate the distance from the center of the edge to the disk center
        double distToEdge = distance(edgeCenter, polygon[i]);
        // Calculate the radius of the disk that can be placed at the center of the edge
        double diskRadius = sqrt(pow(radius, 2) - pow(distToEdge, 2));
        // Calculate the area of the disk segment
        double diskSegmentArea = (M_PI * pow(diskRadius, 2) / 2) - (diskRadius * diskRadius * sin(2 * acos(distToEdge / radius)) / 2);
        // Calculate the area of the triangle formed by the edge and the two points on the disk boundary
        double triangleArea = triangleArea(polygon[i], polygon[j], {edgeCenter.x + diskRadius * (polygon[j].y - polygon[i].y) / distance(polygon[i], polygon[j]), edgeCenter.y + diskRadius * (polygon[i].x - polygon[j].x) / distance(polygon[i], polygon[j])});
        // Calculate the area of the intersection
        double intersectionArea = diskSegmentArea + triangleArea;
        // Update the maximum area
        if (intersectionArea > maxArea) {
            maxArea = intersectionArea;
        }
    }
    // Iterate over all vertices of the polygon
    for (int i = 0; i < n; i++) {
        // Check if the disk can be placed at the vertex
        if (isInsidePolygon({polygon[i].x + radius, polygon[i].y}, polygon, n) || isInsidePolygon({polygon[i].x - radius, polygon[i].y}, polygon, n) || isInsidePolygon({polygon[i].x, polygon[i].y + radius}, polygon, n) || isInsidePolygon({polygon[i].x, polygon[i].y - radius}, polygon, n)) {
            // Calculate the area of the disk that can be placed at the vertex
            double diskArea = M_PI * pow(radius, 2);
            // Update the maximum area
            if (diskArea > maxArea) {
                maxArea = diskArea;
            }
        }
    }
    return maxArea;
}

int main() {
    int n, r;
    scanf("%d %d", &n, &r);

    Point polygon[10];
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &polygon[i].x, &polygon[i].y);
    }

    double maxArea = maxIntersectionArea(polygon, n, r);

    printf("%.4lf\n", maxArea);

    return 0;
}