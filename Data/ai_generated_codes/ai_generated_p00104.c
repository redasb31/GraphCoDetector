#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_H 101
#define MAX_W 101

// Structure to represent a tile
typedef struct {
    char direction; // '>', '<', '^', 'v', '.'
    int visited; // Flag to mark if the tile has been visited
} Tile;

// Function to check if a tile is valid
int isValidTile(int x, int y, int H, int W) {
    return x >= 0 && x < W && y >= 0 && y < H;
}

// Function to simulate the movement of the person
int simulateMovement(Tile room[][MAX_W], int H, int W, int *x, int *y) {
    // Start at the northwest corner
    *x = 0;
    *y = 0;

    // Initialize the visited flag for all tiles
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            room[i][j].visited = 0;
        }
    }

    // Loop until the person reaches a tile with no arrow
    while (room[*y][*x].direction != '.') {
        // Mark the current tile as visited
        room[*y][*x].visited = 1;

        // Move to the next tile based on the direction
        switch (room[*y][*x].direction) {
            case '>':
                (*x)++;
                break;
            case '<':
                (*x)--;
                break;
            case '^':
                (*y)--;
                break;
            case 'v':
                (*y)++;
                break;
        }

        // Check if the person went out of bounds
        if (!isValidTile(*x, *y, H, W)) {
            return -1; // Error: Out of bounds
        }

        // Check if the person visited the current tile before
        if (room[*y][*x].visited) {
            return 1; // Loop detected
        }
    }

    return 0; // No loop, reached a tile with no arrow
}

int main() {
    int H, W;
    Tile room[MAX_H][MAX_W];

    // Read input until two 0 are encountered
    while (scanf("%d %d", &H, &W) != EOF && (H != 0 || W != 0)) {
        // Read the room layout
        for (int i = 0; i < H; i++) {
            char line[MAX_W + 1];
            scanf("%s", line);
            for (int j = 0; j < W; j++) {
                room[i][j].direction = line[j];
            }
        }

        // Simulate the movement of the person
        int x, y;
        int result = simulateMovement(room, H, W, &x, &y);

        // Print the result
        if (result == 0) {
            printf("%d %d\n", x, y);
        } else if (result == 1) {
            printf("LOOP\n");
        } else {
            printf("ERROR\n"); // Should not occur in this problem
        }
    }

    return 0;
}