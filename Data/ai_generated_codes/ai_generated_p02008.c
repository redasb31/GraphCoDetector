#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent a point
typedef struct {
    double x;
    double y;
} Point;

// Structure to represent a triangle
typedef struct {
    Point p1;
    Point p2;
    Point p3;
} Triangle;

// Function to calculate the area of a triangle
double triangleArea(Triangle triangle) {
    double x1 = triangle.p1.x;
    double y1 = triangle.p1.y;
    double x2 = triangle.p2.x;
    double y2 = triangle.p2.y;
    double x3 = triangle.p3.x;
    double y3 = triangle.p3.y;
    return 0.5 * abs((x2 * y3 - x3 * y2) - (x1 * y3 - x3 * y1) + (x1 * y2 - x2 * y1));
}

// Function to check if a point is inside a triangle
int isPointInsideTriangle(Point point, Triangle triangle) {
    // Calculate the area of the triangle
    double area = triangleArea(triangle);

    // Calculate the area of the three sub-triangles formed by the point and the edges of the triangle
    double area1 = triangleArea((Triangle){point, triangle.p2, triangle.p3});
    double area2 = triangleArea((Triangle){triangle.p1, point, triangle.p3});
    double area3 = triangleArea((Triangle){triangle.p1, triangle.p2, point});

    // Check if the sum of the sub-triangle areas equals the area of the triangle
    return (area1 + area2 + area3) == area;
}

// Function to calculate the common area of multiple triangles
double commonArea(Triangle *triangles, int n) {
    // Initialize the common area to the area of the first triangle
    double commonArea = triangleArea(triangles[0]);

    // Iterate over the remaining triangles
    for (int i = 1; i < n; i++) {
        // Calculate the intersection area of the current triangle with the common area
        double intersectionArea = 0;
        for (int j = 0; j < 3; j++) {
            if (isPointInsideTriangle(triangles[i].p1, triangles[j])) {
                intersectionArea += triangleArea(triangles[j]);
            }
        }

        // Update the common area to the intersection area
        commonArea = intersectionArea;
    }

    // Return the common area
    return commonArea;
}

int main() {
    // Read the number of triangles
    int n;
    scanf("%d", &n);

    // Allocate memory for the triangles
    Triangle *triangles = malloc(n * sizeof(Triangle));

    // Read the coordinates of the triangles
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf %lf %lf %lf %lf",
              &triangles[i].p1.x, &triangles[i].p1.y,
              &triangles[i].p2.x, &triangles[i].p2.y,
              &triangles[i].p3.x, &triangles[i].p3.y);
    }

    // Calculate the common area
    double area = commonArea(triangles, n);

    // Print the common area
    printf("%.6lf\n", area);

    // Free the allocated memory
    free(triangles);

    return 0;
}