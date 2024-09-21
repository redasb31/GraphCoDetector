#include <stdio.h>
#include <stdlib.h>

// Structure to represent a magical tile
typedef struct {
    int xLower1;
    int xLower2;
    int xUpper1;
    int xUpper2;
} Tile;

// Function to compare two tiles based on their xUpper1 coordinate
int compareTiles(const void *a, const void *b) {
    Tile *tileA = (Tile *)a;
    Tile *tileB = (Tile *)b;
    return tileA->xUpper1 - tileB->xUpper1;
}

// Function to calculate the minimum number of spells required
int calculateSpells(Tile *tiles, int n) {
    // Sort the tiles based on their xUpper1 coordinate
    qsort(tiles, n, sizeof(Tile), compareTiles);

    // Initialize the number of spells to 0
    int spells = 0;

    // Keep track of the last tile that was removed
    int lastXUpper2 = 0;

    // Iterate through the tiles
    for (int i = 0; i < n; i++) {
        // If the current tile overlaps with the last tile, skip it
        if (tiles[i].xLower1 <= lastXUpper2) {
            continue;
        }

        // Otherwise, increment the spell count and update lastXUpper2
        spells++;
        lastXUpper2 = tiles[i].xUpper2;
    }

    // Return the number of spells
    return spells;
}

int main() {
    // Get the number of tiles
    int n;
    scanf("%d", &n);

    // Allocate memory for the tiles
    Tile *tiles = (Tile *)malloc(n * sizeof(Tile));

    // Read the tile information
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &tiles[i].xLower1, &tiles[i].xLower2, &tiles[i].xUpper1, &tiles[i].xUpper2);
    }

    // Calculate the minimum number of spells
    int spells = calculateSpells(tiles, n);

    // Print the result
    printf("%d\n", spells);

    // Free the allocated memory
    free(tiles);

    return 0;
}