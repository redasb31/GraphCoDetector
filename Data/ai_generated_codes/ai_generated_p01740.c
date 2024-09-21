#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 2000

// Structure to represent a checker arrangement
typedef struct {
    char board[2][MAX_WIDTH];
} Arrangement;

// Function to initialize an arrangement from input
Arrangement* initArrangement(int W) {
    Arrangement* arr = (Arrangement*)malloc(sizeof(Arrangement));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }

    // Read initial arrangement
    for (int i = 0; i < 2; i++) {
        scanf("%s", arr->board[i]);
    }

    return arr;
}

// Function to initialize a target arrangement from input
Arrangement* initTargetArrangement(int W) {
    Arrangement* arr = (Arrangement*)malloc(sizeof(Arrangement));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }

    // Read target arrangement
    for (int i = 0; i < 2; i++) {
        scanf("%s", arr->board[i]);
    }

    return arr;
}

// Function to perform a square rotation
void rotateSquare(Arrangement* arr, int row, int col, int direction) {
    // Rotate checkers in the 2x2 square clockwise or counterclockwise
    char temp;

    if (direction == 1) {  // Clockwise
        temp = arr->board[row][col];
        arr->board[row][col] = arr->board[row + 1][col];
        arr->board[row + 1][col] = arr->board[row + 1][col + 1];
        arr->board[row + 1][col + 1] = arr->board[row][col + 1];
        arr->board[row][col + 1] = temp;
    } else {  // Counterclockwise
        temp = arr->board[row][col];
        arr->board[row][col] = arr->board[row][col + 1];
        arr->board[row][col + 1] = arr->board[row + 1][col + 1];
        arr->board[row + 1][col + 1] = arr->board[row + 1][col];
        arr->board[row + 1][col] = temp;
    }
}

// Function to perform a triangular rotation
void rotateTriangle(Arrangement* arr, int row, int col, int direction) {
    // Rotate checkers in the triangle clockwise or counterclockwise
    char temp;

    if (direction == 1) {  // Clockwise
        // Case 1: Removing the top-left cell
        if (row == 0 && col == 0) {
            temp = arr->board[row][col + 1];
            arr->board[row][col + 1] = arr->board[row + 1][col + 1];
            arr->board[row + 1][col + 1] = arr->board[row + 1][col];
            arr->board[row + 1][col] = temp;
        }
        // Case 2: Removing the top-right cell
        else if (row == 0 && col == 1) {
            temp = arr->board[row][col];
            arr->board[row][col] = arr->board[row + 1][col];
            arr->board[row + 1][col] = arr->board[row + 1][col - 1];
            arr->board[row + 1][col - 1] = temp;
        }
        // Case 3: Removing the bottom-left cell
        else if (row == 1 && col == 0) {
            temp = arr->board[row][col + 1];
            arr->board[row][col + 1] = arr->board[row - 1][col + 1];
            arr->board[row - 1][col + 1] = arr->board[row - 1][col];
            arr->board[row - 1][col] = temp;
        }
        // Case 4: Removing the bottom-right cell
        else if (row == 1 && col == 1) {
            temp = arr->board[row][col];
            arr->board[row][col] = arr->board[row - 1][col];
            arr->board[row - 1][col] = arr->board[row - 1][col - 1];
            arr->board[row - 1][col - 1] = temp;
        }
    } else {  // Counterclockwise
        // Case 1: Removing the top-left cell
        if (row == 0 && col == 0) {
            temp = arr->board[row + 1][col];
            arr->board[row + 1][col] = arr->board[row + 1][col + 1];
            arr->board[row + 1][col + 1] = arr->board[row][col + 1];
            arr->board[row][col + 1] = temp;
        }
        // Case 2: Removing the top-right cell
        else if (row == 0 && col == 1) {
            temp = arr->board[row + 1][col - 1];
            arr->board[row + 1][col - 1] = arr->board[row + 1][col];
            arr->board[row + 1][col] = arr->board[row][col];
            arr->board[row][col] = temp;
        }
        // Case 3: Removing the bottom-left cell
        else if (row == 1 && col == 0) {
            temp = arr->board[row - 1][col];
            arr->board[row - 1][col] = arr->board[row - 1][col + 1];
            arr->board[row - 1][col + 1] = arr->board[row][col + 1];
            arr->board[row][col + 1] = temp;
        }
        // Case 4: Removing the bottom-right cell
        else if (row == 1 && col == 1) {
            temp = arr->board[row - 1][col - 1];
            arr->board[row - 1][col - 1] = arr->board[row - 1][col];
            arr->board[row - 1][col] = arr->board[row][col];
            arr->board[row][col] = temp;
        }
    }
}

// Function to check if two arrangements are identical
int compareArrangements(Arrangement* arr1, Arrangement* arr2, int W) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < W; j++) {
            if (arr1->board[i][j] != arr2->board[i][j]) {
                return 0; // Not identical
            }
        }
    }
    return 1; // Identical
}

// Function to solve the checker arrangement problem
int solve(Arrangement* start, Arrangement* target, int W) {
    int operations = 0;

    // Iterate through the board, checking for differences and applying rotations
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < W - 1; j++) {
            // Check if the current 2x2 square needs rotation
            if (start->board[i][j] != target->board[i][j] ||
                start->board[i][j + 1] != target->board[i][j + 1] ||
                start->board[i + 1][j] != target->board[i + 1][j] ||
                start->board[i + 1][j + 1] != target->board[i + 1][j + 1]) {
                // Try both clockwise and counterclockwise rotations
                rotateSquare(start, i, j, 1);
                if (compareArrangements(start, target, W)) {
                    operations++;
                    break;
                }
                rotateSquare(start, i, j, -1); // Undo the clockwise rotation
                rotateSquare(start, i, j, -1); // Counterclockwise rotation
                if (compareArrangements(start, target, W)) {
                    operations++;
                    break;
                }
                rotateSquare(start, i, j, 1); // Undo the counterclockwise rotation
            }

            // Check if the current triangle needs rotation
            if (j < W - 2) {
                if (start->board[i][j] != target->board[i][j] ||
                    start->board[i][j + 1] != target->board[i][j + 1] ||
                    start->board[i + 1][j + 1] != target->board[i + 1][j + 1]) {
                    // Try both clockwise and counterclockwise rotations
                    rotateTriangle(start, i, j, 1);
                    if (compareArrangements(start, target, W)) {
                        operations++;
                        break;
                    }
                    rotateTriangle(start, i, j, -1); // Undo the clockwise rotation
                    rotateTriangle(start, i, j, -1); // Counterclockwise rotation
                    if (compareArrangements(start, target, W)) {
                        operations++;
                        break;
                    }
                    rotateTriangle(start, i, j, 1); // Undo the counterclockwise rotation
                }
            }
        }
    }

    return operations;
}

int main() {
    int W;
    scanf("%d", &W);

    Arrangement* start = initArrangement(W);
    Arrangement* target = initTargetArrangement(W);

    int operations = solve(start, target, W);
    printf("%d\n", operations);

    free(start);
    free(target);

    return 0;
}