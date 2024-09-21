#include <stdio.h>
#include <stdlib.h>

// Function to find the row and column of a given number in the grid
void find_coordinates(int grid[][300], int num, int H, int W, int *row, int *col) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == num) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

int main() {
    int H, W, D, Q;
    int grid[300][300];
    int L[100000], R[100000];
    
    // Input grid size and D
    scanf("%d %d %d", &H, &W, &D);

    // Input grid elements
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // Input number of tests
    scanf("%d", &Q);

    // Input L and R for each test
    for (int i = 0; i < Q; i++) {
        scanf("%d %d", &L[i], &R[i]);
    }

    // Process each test
    for (int i = 0; i < Q; i++) {
        int magic_points = 0;
        int current_num = L[i];
        int row, col, next_row, next_col;

        // Find the coordinates of the initial position
        find_coordinates(grid, current_num, H, W, &row, &col);

        // Move the piece until reaching R[i]
        while (current_num != R[i]) {
            // Find the coordinates of the next position
            current_num += D;
            find_coordinates(grid, current_num, H, W, &next_row, &next_col);

            // Calculate and add magic points
            magic_points += abs(next_row - row) + abs(next_col - col);

            // Update current position
            row = next_row;
            col = next_col;
        }

        // Print the total magic points used for the test
        printf("%d\n", magic_points);
    }

    return 0;
}