#include <stdio.h>

// Function to calculate the minimum steps to reach a target trigon
int minSteps(int x, int y, int n) {
    // Initialize variables
    int steps = 0;
    int currentX = 0;
    int currentY = 0;
    int currentFace = 0;

    // Main loop to move the rover to the target trigon
    while (currentX != x || currentY != y || currentFace != n) {
        // Calculate the difference between the current and target coordinates
        int xDiff = x - currentX;
        int yDiff = y - currentY;

        // Determine the next move based on the current position and target
        if (xDiff > 0) {
            // Move east
            currentX++;
            currentFace = (currentFace + 1) % 20;
        } else if (xDiff < 0) {
            // Move west
            currentX--;
            currentFace = (currentFace + 19) % 20;
        } else if (yDiff > 0 && (currentX + currentY) % 2 == 0) {
            // Move north (even sum of coordinates)
            currentY++;
            currentFace = (currentFace + 5) % 20;
        } else if (yDiff < 0 && (currentX + currentY) % 2 == 1) {
            // Move south (odd sum of coordinates)
            currentY--;
            currentFace = (currentFace + 15) % 20;
        } else if (yDiff > 0 && (currentX + currentY) % 2 == 1) {
            // Move south (odd sum of coordinates)
            currentY--;
            currentFace = (currentFace + 15) % 20;
        } else if (yDiff < 0 && (currentX + currentY) % 2 == 0) {
            // Move north (even sum of coordinates)
            currentY++;
            currentFace = (currentFace + 5) % 20;
        }

        // Increment the step count
        steps++;
    }

    // Return the minimum steps
    return steps;
}

int main() {
    int x, y, n;

    // Read input until three zeros are encountered
    while (scanf("%d %d %d", &x, &y, &n) == 3 && (x != 0 || y != 0 || n != 0)) {
        // Calculate and print the minimum steps
        printf("%d\n", minSteps(x, y, n));
    }

    return 0;
}