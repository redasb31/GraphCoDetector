#include <stdio.h>
#include <stdlib.h>

// Structure to represent a target
typedef struct {
    int row;
    int col;
} Target;

// Function to compare targets based on row and then column
int compareTargets(const void *a, const void *b) {
    Target *targetA = (Target *)a;
    Target *targetB = (Target *)b;
    if (targetA->row != targetB->row) {
        return targetA->row - targetB->row;
    } else {
        return targetA->col - targetB->col;
    }
}

int main() {
    int H, W, M;
    // Read grid dimensions and number of targets
    scanf("%d %d %d", &H, &W, &M);

    // Allocate memory for targets
    Target *targets = (Target *)malloc(M * sizeof(Target));
    if (targets == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    // Read target positions
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &targets[i].row, &targets[i].col);
    }

    // Sort targets by row and then column
    qsort(targets, M, sizeof(Target), compareTargets);

    // Variables to track the maximum number of targets destroyed
    int maxDestroyed = 0;
    int currentDestroyed = 0;
    int currentRow = 0;
    int currentCol = 0;

    // Iterate over sorted targets
    for (int i = 0; i < M; i++) {
        // If current target is in a new row
        if (targets[i].row > currentRow) {
            // Update current row and reset destroyed count
            currentRow = targets[i].row;
            currentDestroyed = 0;
        }
        // If current target is in a new column
        if (targets[i].col > currentCol) {
            // Update current column and increment destroyed count
            currentCol = targets[i].col;
            currentDestroyed++;
        } else {
            // If current target is in the same row or column as the previous one
            currentDestroyed++;
        }

        // Update maximum destroyed count if necessary
        maxDestroyed = (maxDestroyed > currentDestroyed) ? maxDestroyed : currentDestroyed;
    }

    // Print the maximum number of targets that can be destroyed
    printf("%d\n", maxDestroyed);

    // Free allocated memory
    free(targets);

    return 0;
}