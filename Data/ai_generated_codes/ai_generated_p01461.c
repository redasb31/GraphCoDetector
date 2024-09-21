#include <stdio.h>
#include <stdlib.h>

// Structure to represent a branching point
typedef struct BranchingPoint {
    int yes;
    int no;
} BranchingPoint;

// Function to calculate the shortest time to complete all endings
int shortestTime(BranchingPoint *branchingPoints, int n) {
    // Create an array to store the shortest time to reach each ending
    int *shortestTimeArray = malloc(sizeof(int) * (n + 1));

    // Initialize the shortest time to reach the first branching point to 0
    shortestTimeArray[1] = 0;

    // Iterate over all branching points
    for (int i = 1; i < n; i++) {
        // Calculate the shortest time to reach the current branching point
        shortestTimeArray[i + 1] = shortestTimeArray[i] + 1;

        // If the current branching point leads to an ending, update the shortest time
        if (branchingPoints[i].yes == n) {
            shortestTimeArray[n] = shortestTimeArray[i + 1];
        }

        // If the current branching point leads to another branching point, update the shortest time
        if (branchingPoints[i].no == n) {
            shortestTimeArray[n] = shortestTimeArray[i + 1];
        }
    }

    // Find the maximum shortest time to reach any ending
    int shortestTime = 0;
    for (int i = 1; i <= n; i++) {
        if (shortestTimeArray[i] > shortestTime) {
            shortestTime = shortestTimeArray[i];
        }
    }

    // Free the dynamically allocated memory
    free(shortestTimeArray);

    // Return the shortest time
    return shortestTime;
}

int main() {
    // Read the number of endings
    int n;
    scanf("%d", &n);

    // Allocate memory for the branching points
    BranchingPoint *branchingPoints = malloc(sizeof(BranchingPoint) * (n - 1));

    // Read the branching points
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &branchingPoints[i].yes, &branchingPoints[i].no);
    }

    // Calculate the shortest time to complete all endings
    int shortestTime = shortestTime(branchingPoints, n);

    // Print the shortest time
    printf("%d\n", shortestTime);

    // Free the dynamically allocated memory
    free(branchingPoints);

    return 0;
}