#include <stdio.h>

// Define the size of the grid
#define GRID_SIZE 4

// Define the maximum state of a bubble before it explodes
#define MAX_STATE 5

// Structure to represent a bubble
typedef struct {
    int state;
    int row;
    int col;
} Bubble;

// Function to check if a bubble is within the grid boundaries
int is_valid_bubble(Bubble bubble) {
    return bubble.row >= 0 && bubble.row < GRID_SIZE && bubble.col >= 0 && bubble.col < GRID_SIZE;
}

// Function to check if a bubble has exploded
int is_bubble_exploded(Bubble bubble) {
    return bubble.state >= MAX_STATE;
}

// Function to handle a bubble explosion
void handle_explosion(Bubble bubble, int grid[GRID_SIZE][GRID_SIZE], int* clicks) {
    // Increment the number of clicks
    *clicks += 1;

    // Update the grid with waterdrops
    grid[bubble.row][bubble.col] = -1; // -1 indicates a waterdrop
    
    // Increase the state of adjacent bubbles by 1
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            Bubble adj_bubble = {grid[bubble.row + i][bubble.col + j], bubble.row + i, bubble.col + j};
            if (is_valid_bubble(adj_bubble) && grid[bubble.row + i][bubble.col + j] > 0) {
                grid[bubble.row + i][bubble.col + j] += 1;
            }
        }
    }
}

// Function to simulate the movement of waterdrops
void move_waterdrops(int grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == -1) {
                // Move the waterdrop to the next square
                for (int k = 0; k < 4; k++) {
                    int row_offset = 0, col_offset = 0;
                    switch (k) {
                        case 0: row_offset = -1; break;
                        case 1: row_offset = 1; break;
                        case 2: col_offset = -1; break;
                        case 3: col_offset = 1; break;
                    }
                    int next_row = i + row_offset;
                    int next_col = j + col_offset;
                    if (is_valid_bubble((Bubble){next_row, next_col}) && grid[next_row][next_col] >= 0) {
                        grid[next_row][next_col] += 1;
                    }
                }
                grid[i][j] = 0; // Remove the waterdrop
            }
        }
    }
}

// Function to solve the bubble puzzle
int solve_puzzle(int grid[GRID_SIZE][GRID_SIZE]) {
    int clicks = 0;
    int exploded = 0;
    
    // Loop until all bubbles are exploded
    while (exploded < GRID_SIZE * GRID_SIZE) {
        // Loop through the grid
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                // If the square contains a bubble
                if (grid[i][j] > 0) {
                    // Check if the bubble has exploded
                    if (grid[i][j] >= MAX_STATE) {
                        // Handle the explosion
                        handle_explosion((Bubble){grid[i][j], i, j}, grid, &clicks);
                        exploded++;
                    }
                }
            }
        }
        // Move waterdrops
        move_waterdrops(grid);
        // If the number of clicks exceeds 5, return -1
        if (clicks > 5) {
            return -1;
        }
    }
    return clicks;
}

int main() {
    int grid[GRID_SIZE][GRID_SIZE];
    
    // Read the initial state of the grid
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    
    // Solve the puzzle
    int clicks = solve_puzzle(grid);
    
    // Print the minimum number of clicks
    printf("%d\n", clicks);
    
    return 0;
}