#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Structure to represent a cell in the grid
typedef struct {
    char value;
    long long sum;  // Stores the sum of all possible paths ending at this cell
} Cell;

// Function to calculate the sum of paths ending at a given cell
long long calculate_sum(Cell **grid, int row, int col, int H, int W, long long M) {
    // Base case: reached the bottom-right cell
    if (row == H - 1 && col == W - 1) {
        return grid[row][col].sum;
    }

    // Calculate the sum of paths ending at the current cell
    long long sum = 0;

    // Move right
    if (col < W - 1) {
        if (grid[row][col].value == '+') {
            sum = (sum + (grid[row][col].sum + grid[row][col + 1].sum)) % M;
        } else if (grid[row][col].value == '*') {
            sum = (sum + (grid[row][col].sum * grid[row][col + 1].sum)) % M;
        } else {
            sum = (sum + grid[row][col + 1].sum) % M;
        }
    }

    // Move down
    if (row < H - 1) {
        if (grid[row][col].value == '+') {
            sum = (sum + (grid[row][col].sum + grid[row + 1][col].sum)) % M;
        } else if (grid[row][col].value == '*') {
            sum = (sum + (grid[row][col].sum * grid[row + 1][col].sum)) % M;
        } else {
            sum = (sum + grid[row + 1][col].sum) % M;
        }
    }

    return sum;
}

int main() {
    int H, W, M;
    scanf("%d %d %d", &H, &W, &M);

    // Allocate memory for the grid
    Cell **grid = (Cell **)malloc(sizeof(Cell *) * H);
    for (int i = 0; i < H; i++) {
        grid[i] = (Cell *)malloc(sizeof(Cell) * W);
    }

    // Read the grid values and initialize sums
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            scanf(" %c", &grid[i][j].value);
            if (grid[i][j].value >= '1' && grid[i][j].value <= '9') {
                grid[i][j].sum = grid[i][j].value - '0';
            } else {
                grid[i][j].sum = 0; // Initialize with 0 for operators
            }
        }
    }

    // Calculate the sum of paths from bottom-right to top-left
    for (int i = H - 1; i >= 0; i--) {
        for (int j = W - 1; j >= 0; j--) {
            grid[i][j].sum = calculate_sum(grid, i, j, H, W, M);
        }
    }

    // Print the sum of all paths modulo M
    printf("%lld\n", grid[0][0].sum);

    // Free allocated memory
    for (int i = 0; i < H; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}