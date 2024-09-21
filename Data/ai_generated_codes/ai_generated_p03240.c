#include <stdio.h>
#include <stdlib.h>

// Structure to store information about each point
typedef struct {
    int x;
    int y;
    int h;
} Point;

// Function to calculate the altitude of a point given the pyramid's center and height
int calculate_altitude(int x, int y, int cx, int cy, int h) {
    return (h - abs(x - cx) - abs(y - cy) > 0) ? (h - abs(x - cx) - abs(y - cy)) : 0;
}

// Function to find the center coordinates and height of the pyramid
void find_pyramid(Point points[], int n, int *cx, int *cy, int *h) {
    // Initialize the center coordinates and height to an invalid value
    *cx = -1;
    *cy = -1;
    *h = -1;

    // Iterate over all possible center coordinates (0-100)
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            // Iterate over all possible heights (1-10^9)
            for (int k = 1; k <= 1000000000; k++) {
                // Flag to indicate if all altitudes match for this center and height
                int match = 1;
                // Check if the calculated altitude matches the given altitude for each point
                for (int l = 0; l < n; l++) {
                    if (calculate_altitude(points[l].x, points[l].y, i, j, k) != points[l].h) {
                        match = 0;
                        break;
                    }
                }
                // If all altitudes match, we've found the center coordinates and height
                if (match) {
                    *cx = i;
                    *cy = j;
                    *h = k;
                    return;
                }
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    // Array to store the information about each point
    Point points[n];

    // Read the information about each point
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &points[i].x, &points[i].y, &points[i].h);
    }

    // Variables to store the center coordinates and height
    int cx, cy, h;

    // Find the center coordinates and height
    find_pyramid(points, n, &cx, &cy, &h);

    // Print the results
    printf("%d %d %d\n", cx, cy, h);

    return 0;
}