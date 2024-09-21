#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_H 40
#define MAX_W 40

// Structure to represent a cell
typedef struct {
    int row;
    int col;
    char type;
} Cell;

// Function to check if a cell is valid
int isValidCell(int row, int col, int H, int W) {
    return (row >= 0 && row < H && col >= 0 && col < W);
}

// Function to find the start cell
Cell findStartCell(char map[MAX_H][MAX_W], int H, int W) {
    Cell startCell;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (map[i][j] == '@') {
                startCell.row = i;
                startCell.col = j;
                startCell.type = '@';
                return startCell;
            }
        }
    }
    return startCell;
}

// Function to find all city cells
Cell* findCityCells(char map[MAX_H][MAX_W], int H, int W, int* numCityCells) {
    Cell* cityCells = malloc(sizeof(Cell) * (H * W)); // Allocate memory for city cells
    *numCityCells = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (map[i][j] == '*') {
                cityCells[*numCityCells].row = i;
                cityCells[*numCityCells].col = j;
                cityCells[*numCityCells].type = '*';
                (*numCityCells)++;
            }
        }
    }
    return cityCells;
}

// Function to find the neighboring cells of a given cell
Cell* findNeighbors(char map[MAX_H][MAX_W], int H, int W, Cell cell, int* numNeighbors) {
    Cell* neighbors = malloc(sizeof(Cell) * 4); // Allocate memory for neighbors
    *numNeighbors = 0;
    int row = cell.row;
    int col = cell.col;
    // Check for neighbors in all four directions
    if (isValidCell(row - 1, col, H, W) && map[row - 1][col] != '.') {
        neighbors[*numNeighbors].row = row - 1;
        neighbors[*numNeighbors].col = col;
        neighbors[*numNeighbors].type = map[row - 1][col];
        (*numNeighbors)++;
    }
    if (isValidCell(row + 1, col, H, W) && map[row + 1][col] != '.') {
        neighbors[*numNeighbors].row = row + 1;
        neighbors[*numNeighbors].col = col;
        neighbors[*numNeighbors].type = map[row + 1][col];
        (*numNeighbors)++;
    }
    if (isValidCell(row, col - 1, H, W) && map[row][col - 1] != '.') {
        neighbors[*numNeighbors].row = row;
        neighbors[*numNeighbors].col = col - 1;
        neighbors[*numNeighbors].type = map[row][col - 1];
        (*numNeighbors)++;
    }
    if (isValidCell(row, col + 1, H, W) && map[row][col + 1] != '.') {
        neighbors[*numNeighbors].row = row;
        neighbors[*numNeighbors].col = col + 1;
        neighbors[*numNeighbors].type = map[row][col + 1];
        (*numNeighbors)++;
    }
    return neighbors;
}

// Function to find the journey path
void findJourneyPath(char map[MAX_H][MAX_W], int H, int W, Cell startCell, Cell* cityCells, int numCityCells) {
    // Initialize the visited array to keep track of visited cells
    int visited[MAX_H][MAX_W] = {0};
    // Create a stack to store the path
    Cell* pathStack = malloc(sizeof(Cell) * (H * W));
    int pathStackSize = 0;

    // Push the start cell onto the stack
    pathStack[pathStackSize++] = startCell;
    visited[startCell.row][startCell.col] = 1;

    // Iterate through the cells in the path stack
    while (pathStackSize > 0) {
        // Get the current cell from the stack
        Cell currentCell = pathStack[pathStackSize - 1];
        // Check if the current cell is a city cell
        if (currentCell.type == '*') {
            // Pop the current cell from the stack
            pathStack[pathStackSize--] = currentCell;
            // Add road cells to the path and mark them as visited
            Cell* neighbors;
            int numNeighbors;
            neighbors = findNeighbors(map, H, W, currentCell, &numNeighbors);
            for (int i = 0; i < numNeighbors; i++) {
                if (neighbors[i].type == '.' && !visited[neighbors[i].row][neighbors[i].col]) {
                    map[neighbors[i].row][neighbors[i].col] = '#';
                    visited[neighbors[i].row][neighbors[i].col] = 1;
                    pathStack[pathStackSize++] = neighbors[i];
                }
            }
            free(neighbors);
        } else {
            // Find the neighbors of the current cell
            Cell* neighbors;
            int numNeighbors;
            neighbors = findNeighbors(map, H, W, currentCell, &numNeighbors);
            // Iterate through the neighbors
            for (int i = 0; i < numNeighbors; i++) {
                // Check if the neighbor is unvisited
                if (!visited[neighbors[i].row][neighbors[i].col]) {
                    // Check if the neighbor is a city cell
                    if (neighbors[i].type == '*') {
                        // Pop the current cell from the stack
                        pathStack[pathStackSize--] = currentCell;
                        // Push the neighbor onto the stack
                        pathStack[pathStackSize++] = neighbors[i];
                        // Mark the neighbor as visited
                        visited[neighbors[i].row][neighbors[i].col] = 1;
                        // Add road cells to the path and mark them as visited
                        Cell* newNeighbors;
                        int newNumNeighbors;
                        newNeighbors = findNeighbors(map, H, W, neighbors[i], &newNumNeighbors);
                        for (int j = 0; j < newNumNeighbors; j++) {
                            if (newNeighbors[j].type == '.' && !visited[newNeighbors[j].row][newNeighbors[j].col]) {
                                map[newNeighbors[j].row][newNeighbors[j].col] = '#';
                                visited[newNeighbors[j].row][newNeighbors[j].col] = 1;
                                pathStack[pathStackSize++] = newNeighbors[j];
                            }
                        }
                        free(newNeighbors);
                    } else if (neighbors[i].type == '#') {
                        // Push the neighbor onto the stack
                        pathStack[pathStackSize++] = neighbors[i];
                        // Mark the neighbor as visited
                        visited[neighbors[i].row][neighbors[i].col] = 1;
                    }
                }
            }
            free(neighbors);
        }
    }

    // Free the memory allocated for the path stack
    free(pathStack);
}

int main() {
    int H, W;
    char map[MAX_H][MAX_W];

    // Read the input
    scanf("%d %d", &H, &W);
    for (int i = 0; i < H; i++) {
        scanf("%s", map[i]);
    }

    // Find the start cell
    Cell startCell = findStartCell(map, H, W);
    // Find all city cells
    int numCityCells;
    Cell* cityCells = findCityCells(map, H, W, &numCityCells);

    // Find the journey path
    findJourneyPath(map, H, W, startCell, cityCells, numCityCells);

    // Print the output
    for (int i = 0; i < H; i++) {
        printf("%s\n", map[i]);
    }

    // Free the memory allocated for the city cells
    free(cityCells);

    return 0;
}