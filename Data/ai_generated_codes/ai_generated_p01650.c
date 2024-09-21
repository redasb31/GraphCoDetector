#include <stdio.h>
#include <string.h>

#define MAX_SIZE 50

// Structure to store the state of a cell
typedef struct {
    char type; // Type of the cell ('.', '#', lowercase, uppercase)
    int jewel; // Jewel type if the cell contains a jewel (0 if none)
    int visited; // Flag to indicate if the cell has been visited
} Cell;

// Function to check if a cell is valid
int is_valid(Cell maze[MAX_SIZE][MAX_SIZE], int row, int col, int H, int W) {
    return (row >= 1 && row <= H && col >= 1 && col <= W && maze[row][col].type != '#');
}

// Function to find the maximum number of jewels that can be placed
int find_max_jewels(Cell maze[MAX_SIZE][MAX_SIZE], int H, int W) {
    // Initialize the starting cell
    maze[1][1].visited = 1;

    // Stack to store the cells to be visited
    int stack[MAX_SIZE * MAX_SIZE][2];
    int top = 0;
    stack[top][0] = 1; // Starting row
    stack[top][1] = 1; // Starting column
    top++;

    // Jewel count and current jewel type
    int jewel_count = 0;
    int current_jewel = 0;

    // Iterate until the stack is empty
    while (top > 0) {
        // Pop a cell from the stack
        top--;
        int row = stack[top][0];
        int col = stack[top][1];

        // Check if we have reached the destination
        if (row == H && col == W) {
            return jewel_count;
        }

        // Check if the current cell contains a jewel
        if (maze[row][col].type >= 'a' && maze[row][col].type <= 'z') {
            // Update the current jewel type
            current_jewel = maze[row][col].type;
            // Pick up the jewel
            maze[row][col].jewel = current_jewel;
        }

        // Check if the current cell contains a hole
        if (maze[row][col].type >= 'A' && maze[row][col].type <= 'Z') {
            // Check if we have the corresponding jewel
            if (current_jewel == maze[row][col].type) {
                // Place the jewel
                jewel_count++;
                // Remove the jewel from the stack
                current_jewel = 0;
            }
        }

        // Explore the adjacent cells
        // Right cell
        if (is_valid(maze, row, col + 1, H, W) && !maze[row][col + 1].visited) {
            maze[row][col + 1].visited = 1;
            stack[top][0] = row;
            stack[top][1] = col + 1;
            top++;
        }

        // Lower cell
        if (is_valid(maze, row + 1, col, H, W) && !maze[row + 1][col].visited) {
            maze[row + 1][col].visited = 1;
            stack[top][0] = row + 1;
            stack[top][1] = col;
            top++;
        }
    }

    // If the destination is not reachable, return -1
    return -1;
}

int main() {
    int H, W;

    // Input loop
    while (1) {
        scanf("%d %d", &H, &W);

        // End of input
        if (H == 0 && W == 0) {
            break;
        }

        // Maze grid
        Cell maze[MAX_SIZE][MAX_SIZE];

        // Read the maze input
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                scanf(" %c", &maze[i][j].type);
                maze[i][j].jewel = 0;
                maze[i][j].visited = 0;
            }
        }

        // Find the maximum number of jewels
        int max_jewels = find_max_jewels(maze, H, W);

        // Output the result
        printf("%d\n", max_jewels);
    }

    return 0;
}