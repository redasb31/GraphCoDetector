#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

// Structure to represent a cell on the map
typedef struct {
    char type;
    int row;
    int col;
    bool visited;
} Cell;

// Function to check if a cell is valid (within bounds and not an obstacle)
bool is_valid_cell(int row, int col, Cell map[MAX_SIZE][MAX_SIZE]) {
    return (row >= 0 && row < MAX_SIZE && col >= 0 && col < MAX_SIZE && map[row][col].type != '#');
}

// Function to find the minimum cost of constructing water ways from a source
int find_min_cost(Cell map[MAX_SIZE][MAX_SIZE], int row, int col) {
    // Base case: If the current cell is not valid, return 0 cost
    if (!is_valid_cell(row, col, map)) {
        return 0;
    }

    // If the current cell is already visited, return 0 cost
    if (map[row][col].visited) {
        return 0;
    }

    // Mark the current cell as visited
    map[row][col].visited = true;

    // Define the directions to explore (up, down, left, right)
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    // Initialize the minimum cost to 1 (for the current cell)
    int min_cost = 1;

    // Explore adjacent cells
    for (int i = 0; i < 4; i++) {
        int new_row = row + dr[i];
        int new_col = col + dc[i];

        // If the adjacent cell is valid and not a source
        if (is_valid_cell(new_row, new_col, map) && map[new_row][new_col].type != 'P') {
            // Recursively calculate the minimum cost from the adjacent cell
            min_cost += find_min_cost(map, new_row, new_col);
        }
    }

    return min_cost;
}

int main() {
    int H, W;
    Cell map[MAX_SIZE][MAX_SIZE];

    while (true) {
        scanf("%d %d", &H, &W);

        // End of input
        if (H == 0 && W == 0) {
            break;
        }

        // Read the map
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                scanf(" %c", &map[i][j].type);
                map[i][j].row = i;
                map[i][j].col = j;
                map[i][j].visited = false;
            }
        }

        // Initialize the minimum cost to 0
        int min_cost = 0;

        // Iterate through the map to find sources
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                // If the cell is a source
                if (map[i][j].type == 'P') {
                    // Find the minimum cost from this source
                    min_cost += find_min_cost(map, i, j);
                }
            }
        }

        // Print the minimum cost
        printf("%d\n", min_cost);
    }

    return 0;
}