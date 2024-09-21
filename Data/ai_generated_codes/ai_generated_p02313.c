#include <stdio.h>
#include <math.h>

// Function to calculate the area of intersection between two circles
double intersectionArea(int c1x, int c1y, int c1r, int c2x, int c2y, int c2r) {
    // Calculate the distance between the centers of the circles
    double distance = sqrt(pow(c2x - c1x, 2) + pow(c2y - c1y, 2));

    // If the circles do not intersect, return 0
    if (distance >= c1r + c2r || distance <= abs(c1r - c2r)) {
        return 0.0;
    }

    // Calculate the angles of the triangles formed by the radii and the distance between centers
    double angle1 = acos((c1r * c1r + distance * distance - c2r * c2r) / (2 * c1r * distance));
    double angle2 = acos((c2r * c2r + distance * distance - c1r * c1r) / (2 * c2r * distance));

    // Calculate the areas of the sectors and triangles
    double sectorArea1 = 0.5 * c1r * c1r * angle1;
    double sectorArea2 = 0.5 * c2r * c2r * angle2;
    double triangleArea1 = 0.5 * c1r * c1r * sin(angle1);
    double triangleArea2 = 0.5 * c2r * c2r * sin(angle2);

    // Calculate the area of intersection
    double intersectionArea = sectorArea1 + sectorArea2 - triangleArea1 - triangleArea2;

    return intersectionArea;
}

int main() {
    // Input the coordinates and radii of the circles
    int c1x, c1y, c1r;
    int c2x, c2y, c2r;
    scanf("%d %d %d", &c1x, &c1y, &c1r);
    scanf("%d %d %d", &c2x, &c2y, &c2r);

    // Calculate and print the area of intersection
    printf("%.16lf\n", intersectionArea(c1x, c1y, c1r, c2x, c2y, c2r));

    return 0;
}