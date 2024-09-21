#include <stdio.h>
#include <math.h>

// Structure to represent a point
typedef struct {
    int x;
    int y;
} Point;

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// Function to check if three points are collinear
int collinear(Point p1, Point p2, Point p3) {
    return (p2.y - p1.y) * (p3.x - p2.x) == (p3.y - p2.y) * (p2.x - p1.x);
}

// Function to check if two triangles overlap
int overlap(Point p1, Point p2, Point p3, Point q1, Point q2, Point q3) {
    // Check if any of the vertices of the first triangle lie inside the second triangle
    if (point_in_triangle(p1, q1, q2, q3) ||
        point_in_triangle(p2, q1, q2, q3) ||
        point_in_triangle(p3, q1, q2, q3)) {
        return 1;
    }

    // Check if any of the vertices of the second triangle lie inside the first triangle
    if (point_in_triangle(q1, p1, p2, p3) ||
        point_in_triangle(q2, p1, p2, p3) ||
        point_in_triangle(q3, p1, p2, p3)) {
        return 1;
    }

    // Check if any of the edges of the first triangle intersect the edges of the second triangle
    if (edge_intersect(p1, p2, q1, q2) ||
        edge_intersect(p1, p2, q2, q3) ||
        edge_intersect(p1, p2, q3, q1) ||
        edge_intersect(p2, p3, q1, q2) ||
        edge_intersect(p2, p3, q2, q3) ||
        edge_intersect(p2, p3, q3, q1) ||
        edge_intersect(p3, p1, q1, q2) ||
        edge_intersect(p3, p1, q2, q3) ||
        edge_intersect(p3, p1, q3, q1)) {
        return 1;
    }

    return 0;
}

// Function to check if a point lies inside a triangle
int point_in_triangle(Point p, Point q1, Point q2, Point q3) {
    double area1 = triangle_area(p, q1, q2);
    double area2 = triangle_area(p, q2, q3);
    double area3 = triangle_area(p, q3, q1);
    double area_total = triangle_area(q1, q2, q3);

    return fabs(area1 + area2 + area3 - area_total) < 1e-6;
}

// Function to calculate the area of a triangle
double triangle_area(Point p1, Point p2, Point p3) {
    return 0.5 * fabs((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y));
}

// Function to check if two line segments intersect
int edge_intersect(Point p1, Point p2, Point q1, Point q2) {
    // Check if the line segments are collinear
    if (collinear(p1, p2, q1) || collinear(p1, p2, q2) ||
        collinear(q1, q2, p1) || collinear(q1, q2, p2)) {
        return 0;
    }

    // Calculate the slopes of the line segments
    double m1 = (p2.y - p1.y) / (p2.x - p1.x);
    double m2 = (q2.y - q1.y) / (q2.x - q1.x);

    // Check if the slopes are equal (parallel lines)
    if (m1 == m2) {
        return 0;
    }

    // Calculate the intersection point
    double x = ((q1.y - p1.y) + m1 * p1.x - m2 * q1.x) / (m1 - m2);
    double y = m1 * (x - p1.x) + p1.y;

    // Check if the intersection point lies on both line segments
    if (x >= min(p1.x, p2.x) && x <= max(p1.x, p2.x) &&
        x >= min(q1.x, q2.x) && x <= max(q1.x, q2.x) &&
        y >= min(p1.y, p2.y) && y <= max(p1.y, p2.y) &&
        y >= min(q1.y, q2.y) && y <= max(q1.y, q2.y)) {
        return 1;
    }

    return 0;
}

// Function to calculate the height of the pyramid
double pyramid_height(Point p1, Point p2, Point p3, Point p4, Point p5, Point p6) {
    // Calculate the areas of the triangles
    double area1 = triangle_area(p1, p2, p3);
    double area2 = triangle_area(p2, p3, p4);
    double area3 = triangle_area(p3, p1, p5);
    double area4 = triangle_area(p1, p2, p6);

    // Calculate the volume of the pyramid
    double volume = (1.0 / 3.0) * area1 * distance(p1, p4);

    // Calculate the height of the pyramid
    return 3.0 * volume / (area1 + area2 + area3 + area4);
}

// Function to find the lowest pyramid
double lowest_pyramid(Point p1, Point p2, Point p3) {
    double min_height = INFINITY;

    // Iterate through all possible coordinates for the other three vertices
    for (int xa = -100; xa <= 100; xa++) {
        for (int ya = -100; ya <= 100; ya++) {
            for (int xb = -100; xb <= 100; xb++) {
                for (int yb = -100; yb <= 100; yb++) {
                    for (int xc = -100; xc <= 100; xc++) {
                        for (int yc = -100; yc <= 100; yc++) {
                            Point p4 = {xa, ya};
                            Point p5 = {xb, yb};
                            Point p6 = {xc, yc};

                            // Check if the triangles overlap
                            if (overlap(p1, p2, p3, p1, p2, p4) ||
                                overlap(p1, p2, p3, p2, p3, p5) ||
                                overlap(p1, p2, p3, p3, p1, p6)) {
                                continue;
                            }

                            // Check if the pyramid has a positive height
                            double height = pyramid_height(p1, p2, p3, p4, p5, p6);
                            if (height > 0) {
                                min_height = min(min_height, height);
                            }
                        }
                    }
                }
            }
        }
    }

    // Return the minimum height or -1 if no valid pyramid can be formed
    if (min_height == INFINITY) {
        return -1;
    } else {
        return min_height;
    }
}

int main() {
    Point p1, p2, p3;

    while (1) {
        // Read the coordinates of the base vertices
        scanf("%d %d %d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y);

        // Check if the input is the end of the file
        if (p1.x == 0 && p1.y == 0 && p2.x == 0 && p2.y == 0 && p3.x == 0 && p3.y == 0) {
            break;
        }

        // Calculate the lowest pyramid height
        double height = lowest_pyramid(p1, p2, p3);

        // Print the height
        printf("%.4lf\n", height);
    }

    return 0;
}