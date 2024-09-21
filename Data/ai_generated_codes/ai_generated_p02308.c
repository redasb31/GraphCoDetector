#include <stdio.h>
#include <math.h>

// Structure to represent a point
typedef struct {
    double x;
    double y;
} Point;

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// Function to calculate the intersection points of a circle and a line
void findIntersectionPoints(Point center, double radius, Point p1, Point p2, Point *intersectionPoints) {
    // Calculate the line parameters
    double a = p2.y - p1.y;
    double b = p1.x - p2.x;
    double c = a * p1.x + b * p1.y;

    // Calculate the discriminant
    double discriminant = (a * center.x + b * center.y - c) * (a * center.x + b * center.y - c) - (a * a + b * b) * (center.x * center.x + center.y * center.y - radius * radius);

    // Check for intersection
    if (discriminant >= 0) {
        // Calculate the intersection points
        double x1 = (-a * (a * center.x + b * center.y - c) + b * sqrt(discriminant)) / (a * a + b * b);
        double y1 = (b * (a * center.x + b * center.y - c) - a * sqrt(discriminant)) / (a * a + b * b);
        double x2 = (-a * (a * center.x + b * center.y - c) - b * sqrt(discriminant)) / (a * a + b * b);
        double y2 = (b * (a * center.x + b * center.y - c) + a * sqrt(discriminant)) / (a * a + b * b);

        // Assign the intersection points to the output structure
        intersectionPoints[0].x = x1;
        intersectionPoints[0].y = y1;
        intersectionPoints[1].x = x2;
        intersectionPoints[1].y = y2;
    }
}

int main() {
    // Input circle parameters
    int cx, cy, r;
    scanf("%d %d %d", &cx, &cy, &r);

    // Input number of queries
    int q;
    scanf("%d", &q);

    // Loop through each query
    for (int i = 0; i < q; i++) {
        // Input line points
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        // Create point structures
        Point center = {cx, cy};
        Point p1 = {x1, y1};
        Point p2 = {x2, y2};

        // Calculate intersection points
        Point intersectionPoints[2];
        findIntersectionPoints(center, r, p1, p2, intersectionPoints);

        // Print the intersection points
        if (intersectionPoints[0].x == intersectionPoints[1].x && intersectionPoints[0].y == intersectionPoints[1].y) {
            printf("%.8lf %.8lf\n", intersectionPoints[0].x, intersectionPoints[0].y);
        } else {
            if (intersectionPoints[0].x < intersectionPoints[1].x || (intersectionPoints[0].x == intersectionPoints[1].x && intersectionPoints[0].y < intersectionPoints[1].y)) {
                printf("%.8lf %.8lf %.8lf %.8lf\n", intersectionPoints[0].x, intersectionPoints[0].y, intersectionPoints[1].x, intersectionPoints[1].y);
            } else {
                printf("%.8lf %.8lf %.8lf %.8lf\n", intersectionPoints[1].x, intersectionPoints[1].y, intersectionPoints[0].x, intersectionPoints[0].y);
            }
        }
    }

    return 0;
}