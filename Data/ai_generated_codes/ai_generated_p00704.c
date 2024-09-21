#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

// Structure to represent a circle
typedef struct {
    double x;  // x-coordinate of the center
    double y;  // y-coordinate of the center
    double r;  // radius
} Circle;

// Function to calculate the distance between two points
double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// Function to check if two circles intersect
int intersects(Circle c1, Circle c2) {
    double dist = distance(c1.x, c1.y, c2.x, c2.y);
    return (dist < c1.r + c2.r);
}

// Function to calculate the minimum rope length
double minRopeLength(Circle circles[], int n) {
    double ropeLength = 0.0;
    int i, j;
    // Find the outermost circle
    int outermost = 0;
    for (i = 1; i < n; i++) {
        if (circles[i].r > circles[outermost].r) {
            outermost = i;
        }
    }

    // Calculate the length of the rope along the outer circle
    ropeLength = 2 * PI * circles[outermost].r;

    // Check for overlapping circles
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (intersects(circles[i], circles[j])) {
                // Calculate the distance between the centers of the overlapping circles
                double dist = distance(circles[i].x, circles[i].y, circles[j].x, circles[j].y);
                // Subtract the overlapping length from the rope length
                ropeLength -= 2 * acos((circles[i].r * circles[i].r + circles[j].r * circles[j].r - dist * dist) / (2 * circles[i].r * circles[j].r)) * circles[i].r;
            }
        }
    }

    return ropeLength;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF && n != 0) {
        Circle circles[100];
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf %lf", &circles[i].x, &circles[i].y, &circles[i].r);
        }
        double ropeLength = minRopeLength(circles, n);
        printf("%.5lf\n", ropeLength);
    }
    return 0;
}