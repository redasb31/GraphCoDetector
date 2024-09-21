#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent a ruin
typedef struct {
    int x;
    int y;
} Ruin;

// Function to calculate the area of a triangle given its vertices
double calculateTriangleArea(Ruin a, Ruin b, Ruin c) {
    return 0.5 * fabs((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)));
}

// Function to calculate the area of the polygon formed by the given ruins
double calculatePolygonArea(Ruin* ruins, int n, int start, int end) {
    double area = 0;
    for (int i = start; i < end; i++) {
        area += calculateTriangleArea(ruins[start], ruins[i], ruins[i + 1]);
    }
    return area;
}

// Function to find the minimum sum of areas for the two organizations
double findMinArea(Ruin* ruins, int n) {
    // Sort the ruins based on their x-coordinate
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ruins[i].x > ruins[j].x) {
                Ruin temp = ruins[i];
                ruins[i] = ruins[j];
                ruins[j] = temp;
            }
        }
    }

    // Find the best line to split the ruins
    double minArea = INFINITY;
    for (int i = 0; i < n; i++) {
        // Calculate the area for the current split
        double area1 = calculatePolygonArea(ruins, n, 0, i);
        double area2 = calculatePolygonArea(ruins, n, i, n);
        double currentArea = area1 + area2;

        // Update the minimum area
        if (currentArea < minArea) {
            minArea = currentArea;
        }
    }

    return minArea;
}

int main() {
    int n;
    scanf("%d", &n);

    Ruin* ruins = malloc(sizeof(Ruin) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &ruins[i].x, &ruins[i].y);
    }

    double minArea = findMinArea(ruins, n);

    printf("%.0lf\n", round(minArea));

    free(ruins);
    return 0;
}