#include <stdio.h>
#include <stdlib.h>

#define MAX_H 50
#define MAX_W 50

// Function to check if a path from (1, 1) to (H, W) exists
int hasPath(char grid[MAX_H][MAX_W], int H, int W) {
    // Create a visited array to keep track of visited cells
    int visited[MAX_H][MAX_W] = {0};

    // Initialize the starting cell as visited
    visited[0][0] = 1;

    // Perform a depth-first search (DFS)
    int stack[MAX_H * MAX_W][2];
    int top = 0;
    stack[top][0] = 0;
    stack[top][1] = 0;
    while (top >= 0) {
        int row = stack[top][0];
        int col = stack[top][1];
        top--;

        // Check if the destination cell is reached
        if (row == H - 1 && col == W - 1) {
            return 1; // Path found
        }

        // Explore adjacent cells
        if (row + 1 < H && grid[row + 1][col] == '.' && !visited[row + 1][col]) {
            visited[row + 1][col] = 1;
            top++;
            stack[top][0] = row + 1;
            stack[top][1] = col;
        }
        if (col + 1 < W && grid[row][col + 1] == '.' && !visited[row][col + 1]) {
            visited[row][col + 1] = 1;
            top++;
            stack[top][0] = row;
            stack[top][1] = col + 1;
        }
        if (row - 1 >= 0 && grid[row - 1][col] == '.' && !visited[row - 1][col]) {
            visited[row - 1][col] = 1;
            top++;
            stack[top][0] = row - 1;
            stack[top][1] = col;
        }
        if (col - 1 >= 0 && grid[row][col - 1] == '.' && !visited[row][col - 1]) {
            visited[row][col - 1] = 1;
            top++;
            stack[top][0] = row;
            stack[top][1] = col - 1;
        }
    }

    // No path found
    return 0;
}

// Function to find the maximum possible score
int maxScore(char grid[MAX_H][MAX_W], int H, int W) {
    // Check if a path exists without changing any colors
    if (hasPath(grid, H, W)) {
        return 0; // No need to change any colors
    }

    // Iterate over all cells and change their colors to find the maximum score
    int maxScore = -1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            // Skip the starting and ending cells
            if ((i == 0 && j == 0) || (i == H - 1 && j == W - 1)) {
                continue;
            }

            // Change the color of the current cell
            if (grid[i][j] == '.') {
                grid[i][j] = '#';
                // Check if a path exists after changing the color
                if (hasPath(grid, H, W)) {
                    maxScore = (maxScore > 1) ? maxScore : 1; // Update the maximum score
                }
                // Restore the original color
                grid[i][j] = '.';
            }
        }
    }

    return maxScore;
}

int main() {
    int H, W;
    scanf("%d %d", &H, &W);

    char grid[MAX_H][MAX_W];

    // Input the grid
    for (int i = 0; i < H; i++) {
        scanf("%s", grid[i]);
    }

    // Find the maximum possible score
    int score = maxScore(grid, H, W);

    // Print the result
    printf("%d\n", score);

    return 0;
}