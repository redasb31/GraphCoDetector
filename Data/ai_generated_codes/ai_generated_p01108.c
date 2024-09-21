#include <stdio.h>
#include <math.h>

// Structure to represent a point
typedef struct {
    double x;
    double y;
} Point;

// Structure to represent a triangle
typedef struct {
    Point vertices[3];
} Triangle;

// Function to calculate the area of a triangle
double triangleArea(Triangle t) {
    return 0.5 * fabs((t.vertices[0].x * (t.vertices[1].y - t.vertices[2].y) +
                      t.vertices[1].x * (t.vertices[2].y - t.vertices[0].y) +
                      t.vertices[2].x * (t.vertices[0].y - t.vertices[1].y)));
}

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Function to find the minimum number of operations required to superpose T1 on T2
int minOperations(Triangle T1, Triangle T2) {
    // Check if the triangles have the same area
    if (triangleArea(T1) != triangleArea(T2)) {
        return -1; // Triangles have different areas
    }

    // Find the vertex of T1 that is closest to a vertex of T2
    double minDistance = INFINITY;
    int closestVertex = -1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            double dist = distance(T1.vertices[i], T2.vertices[j]);
            if (dist < minDistance) {
                minDistance = dist;
                closestVertex = i;
            }
        }
    }

    // If no vertex of T1 is close to a vertex of T2, return -1
    if (closestVertex == -1) {
        return -1; // No vertex is close to any vertex of T2
    }

    // Calculate the direction vector of the opposite side of the closest vertex
    Point directionVector;
    directionVector.x = T1.vertices[(closestVertex + 1) % 3].x - T1.vertices[(closestVertex + 2) % 3].x;
    directionVector.y = T1.vertices[(closestVertex + 1) % 3].y - T1.vertices[(closestVertex + 2) % 3].y;

    // Check if the chosen vertex is on a vertex of T2
    int count = 0;
    for (int j = 0; j < 3; j++) {
        if (distance(T1.vertices[closestVertex], T2.vertices[j]) < 1e-9) {
            count++; // Increase the count if the vertex is on a vertex of T2
        }
    }

    // If the chosen vertex is not on a vertex of T2, perform one operation
    if (count == 0) {
        count++; // Increase the count for the first operation
    }

    // Find the vertex of T1 that is closest to the opposite side of T2
    minDistance = INFINITY;
    closestVertex = -1;
    for (int i = 0; i < 3; i++) {
        if (i != closestVertex) {
            double dist = fabs((T2.vertices[0].x * (T2.vertices[1].y - T2.vertices[2].y) +
                               T2.vertices[1].x * (T2.vertices[2].y - T2.vertices[0].y) +
                               T2.vertices[2].x * (T2.vertices[0].y - T2.vertices[1].y)) /
                          distance(directionVector.x, directionVector.y);
            if (dist < minDistance) {
                minDistance = dist;
                closestVertex = i;
            }
        }
    }

    // If the chosen vertex is not close to any vertex of T2, perform one operation
    if (closestVertex != -1) {
        count++; // Increase the count for the second operation
    }

    // Find the vertex of T1 that is closest to the opposite side of T2
    minDistance = INFINITY;
    closestVertex = -1;
    for (int i = 0; i < 3; i++) {
        if (i != closestVertex) {
            double dist = fabs((T2.vertices[0].x * (T2.vertices[1].y - T2.vertices[2].y) +
                               T2.vertices[1].x * (T2.vertices[2].y - T2.vertices[0].y) +
                               T2.vertices[2].x * (T2.vertices[0].y - T2.vertices[1].y)) /
                          distance(directionVector.x, directionVector.y);
            if (dist < minDistance) {
                minDistance = dist;
                closestVertex = i;
            }
        }
    }

    // If the chosen vertex is not close to any vertex of T2, perform one operation
    if (closestVertex != -1) {
        count++; // Increase the count for the third operation
    }

    // Return the number of operations required
    if (count >= 5) {
        return -1; // More than 5 operations are required
    }
    return count;
}

int main() {
    Triangle T1, T2;
    while (scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",
               &T1.vertices[0].x, &T1.vertices[0].y,
               &T1.vertices[1].x, &T1.vertices[1].y,
               &T1.vertices[2].x, &T1.vertices[2].y,
               &T2.vertices[0].x, &T2.vertices[0].y,
               &T2.vertices[1].x, &T2.vertices[1].y,
               &T2.vertices[2].x, &T2.vertices[2].y) != EOF) {
        int operations = minOperations(T1, T2);
        if (operations == -1) {
            printf("Many\n");
        } else {
            printf("%d\n", operations);
        }
    }
    return 0;
}