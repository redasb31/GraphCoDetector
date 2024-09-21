#include <stdio.h>
#include <stdlib.h>

// Structure to represent an action
typedef struct Action {
    char direction; // 'L' for left, 'R' for right, '?' for unknown
    int lowerBound; // Lower bound of the run length
    int upperBound; // Upper bound of the run length
} Action;

// Function to calculate the possible distances the cleaner can move in each direction
void calculatePossibleDistances(int x, int y, int n, Action actions[], int *possibleDistances[4]) {
    int i, j;
    // Initialize possible distances to 0
    for (i = 0; i < 4; i++) {
        possibleDistances[i] = (int *)calloc(n + 1, sizeof(int));
    }
    // Iterate over actions
    for (i = 0; i < n; i++) {
        // If the direction is known
        if (actions[i].direction != '?') {
            // Calculate the direction index (0: right, 1: up, 2: left, 3: down)
            int dirIndex = (actions[i].direction == 'R' ? 0 : 2) + (i % 2);
            // Iterate over possible run lengths
            for (j = actions[i].lowerBound; j <= actions[i].upperBound; j++) {
                // Update the possible distances
                possibleDistances[dirIndex][i + 1] += j;
            }
        } else {
            // If the direction is unknown, update all possible directions
            for (j = 0; j < 4; j++) {
                // Iterate over possible run lengths
                for (int k = actions[i].lowerBound; k <= actions[i].upperBound; k++) {
                    possibleDistances[j][i + 1] += k;
                }
            }
        }
    }
}

// Function to check if a combination of run lengths is valid
int isValidCombination(int x, int y, int n, Action actions[], int *possibleDistances[4]) {
    int i, j;
    // Iterate over possible combinations of run lengths
    for (i = 0; i <= possibleDistances[0][n]; i++) {
        for (j = 0; j <= possibleDistances[1][n]; j++) {
            if (i + possibleDistances[2][n] == x && j + possibleDistances[3][n] == y) {
                return 1; // Valid combination found
            }
        }
    }
    return 0; // No valid combination found
}

// Function to recover the log of actions
int recoverLog(int x, int y, int n, Action actions[]) {
    int *possibleDistances[4];
    int i, j, valid = 0;
    // Calculate the possible distances
    calculatePossibleDistances(x, y, n, actions, possibleDistances);
    // Check for valid combinations
    if (isValidCombination(x, y, n, actions, possibleDistances)) {
        valid = 1; // At least one valid combination found
    }
    // Free the memory allocated for possibleDistances
    for (i = 0; i < 4; i++) {
        free(possibleDistances[i]);
    }
    return valid;
}

int main() {
    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);
    Action actions[n];
    int i;
    // Read the incomplete log
    for (i = 0; i < n; i++) {
        scanf(" %c %d %d", &actions[i].direction, &actions[i].lowerBound, &actions[i].upperBound);
    }
    // Recover the complete log
    if (recoverLog(x, y, n, actions)) {
        // Print the number of actions
        printf("%d\n", n);
        // Print the recovered log
        for (i = 0; i < n; i++) {
            if (actions[i].direction != '?') {
                printf("%c %d\n", actions[i].direction, actions[i].lowerBound);
            } else {
                // Choose any valid run length if the direction is unknown
                printf("%c %d\n", (i % 2) == 0 ? 'R' : 'L', actions[i].lowerBound);
            }
        }
    } else {
        // Print -1 if no valid log can be recovered
        printf("-1\n");
    }
    return 0;
}