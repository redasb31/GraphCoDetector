#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000009

// Structure to represent a cell on the grid
typedef struct {
    int x;
    int y;
} Cell;

// Function to check if a cell is within the grid boundaries
int is_valid(int w, int h, Cell cell) {
    return cell.x >= 1 && cell.x <= w && cell.y >= 1 && cell.y <= h;
}

// Function to check if a cell is an obstruction
int is_obstruction(Cell *obstructions, int n, Cell cell) {
    for (int i = 0; i < n; i++) {
        if (obstructions[i].x == cell.x && obstructions[i].y == cell.y) {
            return 1;
        }
    }
    return 0;
}

// Function to calculate the number of ways to reach a cell
long long count_paths(int w, int h, Cell *obstructions, int n, Cell cell) {
    // Base case: Reached the destination
    if (cell.x == w && cell.y == h) {
        return 1;
    }

    // Initialize count to 0
    long long count = 0;

    // Check lower-left cell
    Cell lower_left = {cell.x - 1, cell.y - 1};
    if (is_valid(w, h, lower_left) && !is_obstruction(obstructions, n, lower_left)) {
        count = (count + count_paths(w, h, obstructions, n, lower_left)) % MOD;
    }

    // Check lower cell
    Cell lower = {cell.x, cell.y - 1};
    if (is_valid(w, h, lower) && !is_obstruction(obstructions, n, lower)) {
        count = (count + count_paths(w, h, obstructions, n, lower)) % MOD;
    }

    // Check lower-right cell
    Cell lower_right = {cell.x + 1, cell.y - 1};
    if (is_valid(w, h, lower_right) && !is_obstruction(obstructions, n, lower_right)) {
        count = (count + count_paths(w, h, obstructions, n, lower_right)) % MOD;
    }

    // Return the total count
    return count;
}

int main() {
    int w, h, n, case_num = 1;

    while (1) {
        // Read input
        scanf("%d %d %d", &w, &h, &n);

        // Check for end of input
        if (w == 0 && h == 0 && n == 0) {
            break;
        }

        // Allocate memory for obstructions
        Cell *obstructions = (Cell *)malloc(sizeof(Cell) * n);

        // Read obstruction positions
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &obstructions[i].x, &obstructions[i].y);
        }

        // Calculate the number of paths
        Cell start = {1, 1};
        long long paths = count_paths(w, h, obstructions, n, start);

        // Print output
        printf("Case %d: %lld\n", case_num++, paths);

        // Free allocated memory
        free(obstructions);
    }

    return 0;
}