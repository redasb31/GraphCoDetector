#include <stdio.h>
#include <math.h>

// Structure to represent a point
typedef struct {
    double x;
    double y;
} Point;

// Structure to represent a circle
typedef struct {
    Point center;
    double radius;
} Circle;

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Function to find the intersection points of two circles
void findIntersectionPoints(Circle c1, Circle c2, Point *intersectionPoints) {
    // Calculate the distance between the centers of the circles
    double d = distance(c1.center, c2.center);

    // If the circles do not intersect, return
    if (d > c1.radius + c2.radius || d < abs(c1.radius - c2.radius)) {
        return;
    }

    // Calculate the distance from the center of circle c1 to the line of intersection
    double a = (c1.radius * c1.radius - c2.radius * c2.radius + d * d) / (2 * d);

    // Calculate the coordinates of the center of the line of intersection
    double x2 = c1.center.x + a * (c2.center.x - c1.center.x) / d;
    double y2 = c1.center.y + a * (c2.center.y - c1.center.y) / d;

    // Calculate the distance from the center of the line of intersection to the intersection points
    double h = sqrt(c1.radius * c1.radius - a * a);

    // Calculate the coordinates of the intersection points
    intersectionPoints[0].x = x2 + h * (c2.center.y - c1.center.y) / d;
    intersectionPoints[0].y = y2 - h * (c2.center.x - c1.center.x) / d;
    intersectionPoints[1].x = x2 - h * (c2.center.y - c1.center.y) / d;
    intersectionPoints[1].y = y2 + h * (c2.center.x - c1.center.x) / d;
}

// Function to find the common tangent lines of two circles
void findCommonTangents(Circle c1, Circle c2) {
    // Calculate the distance between the centers of the circles
    double d = distance(c1.center, c2.center);

    // If the circles are concentric, return
    if (d == 0) {
        return;
    }

    // Calculate the distance from the center of circle c1 to the line of intersection
    double a = (c1.radius * c1.radius - c2.radius * c2.radius + d * d) / (2 * d);

    // Calculate the coordinates of the center of the line of intersection
    double x2 = c1.center.x + a * (c2.center.x - c1.center.x) / d;
    double y2 = c1.center.y + a * (c2.center.y - c1.center.y) / d;

    // Calculate the distance from the center of the line of intersection to the intersection points
    double h = sqrt(c1.radius * c1.radius - a * a);

    // Calculate the coordinates of the tangent points on circle c1
    Point tangentPoints[4];
    tangentPoints[0].x = x2 + h * (c2.center.y - c1.center.y) / d;
    tangentPoints[0].y = y2 - h * (c2.center.x - c1.center.x) / d;
    tangentPoints[1].x = x2 - h * (c2.center.y - c1.center.y) / d;
    tangentPoints[1].y = y2 + h * (c2.center.x - c1.center.x) / d;
    tangentPoints[2].x = x2 + (c1.radius / d) * (c2.center.x - c1.center.x);
    tangentPoints[2].y = y2 + (c1.radius / d) * (c2.center.y - c1.center.y);
    tangentPoints[3].x = x2 - (c1.radius / d) * (c2.center.x - c1.center.x);
    tangentPoints[3].y = y2 - (c1.radius / d) * (c2.center.y - c1.center.y);

    // Sort the tangent points in ascending order of x, then y
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (tangentPoints[i].x > tangentPoints[j].x ||
                (tangentPoints[i].x == tangentPoints[j].x && tangentPoints[i].y > tangentPoints[j].y)) {
                Point temp = tangentPoints[i];
                tangentPoints[i] = tangentPoints[j];
                tangentPoints[j] = temp;
            }
        }
    }

    // Print the coordinates of the tangent points on circle c1
    for (int i = 0; i < 4; i++) {
        printf("%.10lf %.10lf\n", tangentPoints[i].x, tangentPoints[i].y);
    }
}

int main() {
    Circle c1, c2;
    // Read the input values for the circles
    scanf("%lf %lf %lf", &c1.center.x, &c1.center.y, &c1.radius);
    scanf("%lf %lf %lf", &c2.center.x, &c2.center.y, &c2.radius);

    // Find the common tangent lines of the circles
    findCommonTangents(c1, c2);

    return 0;
}