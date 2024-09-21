#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent a hole
typedef struct {
    int x;
    int y;
} Hole;

// Function to calculate the Euclidean distance between two points
double distance(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

// Function to find the closest hole to a given point
int findClosestHole(Hole holes[], int n, int x, int y) {
    int closestHoleIndex = 0;
    double minDistance = distance(x, y, holes[0].x, holes[0].y);

    // Iterate over all holes to find the closest one
    for (int i = 1; i < n; i++) {
        double currentDistance = distance(x, y, holes[i].x, holes[i].y);
        if (currentDistance < minDistance) {
            minDistance = currentDistance;
            closestHoleIndex = i;
        }
    }

    return closestHoleIndex;
}

int main() {
    int n;
    scanf("%d", &n);

    // Allocate memory for holes
    Hole holes[n];

    // Read hole coordinates
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &holes[i].x, &holes[i].y);
    }

    // Initialize probabilities to 0
    double probabilities[n];
    for (int i = 0; i < n; i++) {
        probabilities[i] = 0.0;
    }

    // Set a large radius (R) for the circle
    double radius = 1e10;

    // Perform a large number of simulations to estimate probabilities
    int numSimulations = 1000000;
    for (int i = 0; i < numSimulations; i++) {
        // Generate random x and y coordinates within the circle
        double x = (double)rand() / RAND_MAX * 2 * radius - radius;
        double y = (double)rand() / RAND_MAX * 2 * radius - radius;

        // Check if the point is inside the circle
        if (x * x + y * y <= radius * radius) {
            // Find the closest hole to the point
            int closestHoleIndex = findClosestHole(holes, n, x, y);

            // Increment the probability for the corresponding hole
            probabilities[closestHoleIndex]++;
        }
    }

    // Normalize probabilities
    for (int i = 0; i < n; i++) {
        probabilities[i] /= numSimulations;
    }

    // Print the probabilities
    for (int i = 0; i < n; i++) {
        printf("%.16lf\n", probabilities[i]);
    }

    return 0;
}