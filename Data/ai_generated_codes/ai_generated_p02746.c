#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to check if a given square is white or black
int is_white(int r, int c, int k) {
    // Base case: level 0 fractal has only one white square
    if (k == 0) {
        return 1;
    }

    // Calculate the size of the subgrid
    int subgrid_size = (int)pow(3, k - 1);

    // Check if the square is in the central black subgrid
    if (r >= subgrid_size && r < 2 * subgrid_size && c >= subgrid_size && c < 2 * subgrid_size) {
        return 0;
    }

    // Adjust coordinates to the corresponding subgrid
    if (r < subgrid_size) {
        r = r;
    } else if (r < 2 * subgrid_size) {
        r -= subgrid_size;
    } else {
        r -= 2 * subgrid_size;
    }

    if (c < subgrid_size) {
        c = c;
    } else if (c < 2 * subgrid_size) {
        c -= subgrid_size;
    } else {
        c -= 2 * subgrid_size;
    }

    // Recursively check if the square is white in the corresponding subgrid
    return is_white(r, c, k - 1);
}

// Function to calculate the Manhattan distance between two points
int manhattan_distance(int a, int b, int c, int d) {
    return abs(a - c) + abs(b - d);
}

// Function to calculate the minimum distance between two white squares in a fractal
int min_distance(int a, int b, int c, int d, int k) {
    // Check if both squares are white
    if (is_white(a, b, k) && is_white(c, d, k)) {
        // Calculate the Manhattan distance
        int distance = manhattan_distance(a, b, c, d);

        // If the distance is 1, then the two squares share a side, so the minimum distance is 1
        if (distance == 1) {
            return 1;
        }

        // Find the size of the subgrid
        int subgrid_size = (int)pow(3, k - 1);

        // If the two squares are in different subgrids, then the distance is at least 2 * subgrid_size
        if (a < subgrid_size && c >= subgrid_size || a >= subgrid_size && c < subgrid_size ||
            b < subgrid_size && d >= subgrid_size || b >= subgrid_size && d < subgrid_size) {
            return 2 * subgrid_size;
        }

        // Find the minimum distance recursively in the corresponding subgrid
        if (a < subgrid_size && c < subgrid_size && b < subgrid_size && d < subgrid_size) {
            return min_distance(a, b, c, d, k - 1);
        } else if (a < subgrid_size && c < subgrid_size && b >= subgrid_size && d >= subgrid_size) {
            return min_distance(a, b - subgrid_size, c, d - subgrid_size, k - 1);
        } else if (a >= subgrid_size && c >= subgrid_size && b < subgrid_size && d < subgrid_size) {
            return min_distance(a - subgrid_size, b, c - subgrid_size, d, k - 1);
        } else {
            return min_distance(a - 2 * subgrid_size, b - 2 * subgrid_size, c - 2 * subgrid_size, d - 2 * subgrid_size, k - 1);
        }
    } else {
        // If one or both squares are black, then the distance is infinite
        return -1;
    }
}

int main() {
    int Q, a, b, c, d, k = 30;

    // Read the number of queries
    scanf("%d", &Q);

    // Process each query
    for (int i = 0; i < Q; i++) {
        // Read the coordinates of the two squares
        scanf("%d %d %d %d", &a, &b, &c, &d);

        // Calculate the minimum distance between the two squares
        int distance = min_distance(a, b, c, d, k);

        // Print the distance
        printf("%d\n", distance);
    }

    return 0;
}