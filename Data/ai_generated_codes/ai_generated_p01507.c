#include <stdio.h>
#include <string.h>

#define MOD 1000000007

int H, W;
char dungeon[501][16];

// Function to check if a cell is valid (within bounds and not an obstacle)
int is_valid(int row, int col) {
    return row >= 0 && row < H && col >= 0 && col < W && dungeon[row][col] != '#';
}

// Function to perform Depth First Search (DFS) to find cycles
void dfs(int row, int col, int visited[501][16], int parent_row, int parent_col) {
    visited[row][col] = 1;

    // Explore all neighboring cells
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int new_row = row + dr[i];
        int new_col = col + dc[i];

        // If the cell is valid, not visited, and not the parent cell
        if (is_valid(new_row, new_col) && !visited[new_row][new_col] && (new_row != parent_row || new_col != parent_col)) {
            dfs(new_row, new_col, visited, row, col);
        }
    }
}

// Function to count the number of ways to build walls
int count_ways() {
    // Initialize visited array for DFS
    int visited[501][16] = {0};

    // Perform DFS from each cell to detect cycles
    int ways = 1;  // Start with 1 way (no walls built)

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (is_valid(i, j) && !visited[i][j]) {
                dfs(i, j, visited, -1, -1);

                // If a cycle is detected, there are 2 ways to build walls:
                // 1. Build a wall in the cycle.
                // 2. Don't build a wall in the cycle.
                ways = (ways * 2) % MOD;
            }
        }
    }

    return ways;
}

int main() {
    int case_num = 1;

    while (1) {
        scanf("%d %d", &H, &W);
        if (H == 0 && W == 0) {
            break;
        }

        // Read the dungeon layout
        for (int i = 0; i < H; i++) {
            scanf("%s", dungeon[i]);
        }

        // Compute the number of ways to build walls
        int ways = count_ways();

        printf("Case %d: %d\n", case_num++, ways);
    }

    return 0;
}