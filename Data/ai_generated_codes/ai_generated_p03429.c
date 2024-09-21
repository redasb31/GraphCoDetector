#include <stdio.h>

#define MAX_N 1000
#define MAX_M 1000

// Function to check if it's possible to place a tile at the given position
int can_place(int grid[][MAX_M], int N, int M, int i, int j, int tile_type) {
    if (i < 0 || i >= N || j < 0 || j >= M) {
        return 0; // Out of bounds
    }
    if (grid[i][j] != '.') {
        return 0; // Already occupied
    }

    if (tile_type == 1) { // 1x2 tile (horizontal)
        if (j + 1 < M && grid[i][j + 1] == '.') {
            return 1; // Can place
        }
    } else if (tile_type == 2) { // 2x1 tile (vertical)
        if (i + 1 < N && grid[i + 1][j] == '.') {
            return 1; // Can place
        }
    }
    return 0; // Cannot place
}

// Function to place a tile on the grid
void place_tile(int grid[][MAX_M], int N, int M, int i, int j, int tile_type) {
    if (tile_type == 1) { // 1x2 tile (horizontal)
        grid[i][j] = '<';
        grid[i][j + 1] = '>';
    } else if (tile_type == 2) { // 2x1 tile (vertical)
        grid[i][j] = '^';
        grid[i + 1][j] = 'v';
    }
}

// Function to solve the tile placement problem
void solve(int N, int M, int A, int B) {
    int grid[MAX_N][MAX_M];
    int i, j, tile_type, placed_tiles = 0;

    // Initialize the grid with empty spaces
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            grid[i][j] = '.';
        }
    }

    // Place 1x2 tiles (horizontal)
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (can_place(grid, N, M, i, j, 1) && placed_tiles < A) {
                place_tile(grid, N, M, i, j, 1);
                placed_tiles++;
                j++; // Move to the next column since we placed a horizontal tile
            }
        }
    }

    // Place 2x1 tiles (vertical)
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (can_place(grid, N, M, i, j, 2) && placed_tiles < A + B) {
                place_tile(grid, N, M, i, j, 2);
                placed_tiles++;
            }
        }
    }

    // Check if all tiles were placed
    if (placed_tiles == A + B) {
        printf("YES\n");
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) {
                printf("%c", grid[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("NO\n");
    }
}

int main() {
    int N, M, A, B;

    scanf("%d %d %d %d", &N, &M, &A, &B);

    solve(N, M, A, B);

    return 0;
}