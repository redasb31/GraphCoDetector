#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

// Function to check if a square is within the bounds of the map
int is_valid(int w, int h, int i, int j) {
    return (i >= 0 && i < h && j >= 0 && j < w);
}

// Function to perform a Depth-First Search (DFS) to mark connected land areas as visited
void dfs(int w, int h, int map[MAX_SIZE][MAX_SIZE], int i, int j, int visited[MAX_SIZE][MAX_SIZE]) {
    // Check if the square is valid and not visited
    if (is_valid(w, h, i, j) && map[i][j] == 1 && !visited[i][j]) {
        visited[i][j] = 1; // Mark the square as visited

        // Recursively explore adjacent squares
        dfs(w, h, map, i + 1, j, visited); // Down
        dfs(w, h, map, i - 1, j, visited); // Up
        dfs(w, h, map, i, j + 1, visited); // Right
        dfs(w, h, map, i, j - 1, visited); // Left
        dfs(w, h, map, i + 1, j + 1, visited); // Down-Right
        dfs(w, h, map, i + 1, j - 1, visited); // Down-Left
        dfs(w, h, map, i - 1, j + 1, visited); // Up-Right
        dfs(w, h, map, i - 1, j - 1, visited); // Up-Left
    }
}

// Function to count the number of islands in the map
int count_islands(int w, int h, int map[MAX_SIZE][MAX_SIZE]) {
    int islands = 0;
    int visited[MAX_SIZE][MAX_SIZE] = {0}; // Initialize visited array to 0

    // Iterate through each square on the map
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            // If a land area is not visited, start a DFS to mark the connected island
            if (map[i][j] == 1 && !visited[i][j]) {
                dfs(w, h, map, i, j, visited);
                islands++; // Increment island count
            }
        }
    }

    return islands;
}

int main() {
    int w, h;
    int map[MAX_SIZE][MAX_SIZE];

    // Read input until two zeros are encountered
    while (scanf("%d %d", &w, &h) != EOF && (w != 0 || h != 0)) {
        // Read map data
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                scanf("%d", &map[i][j]);
            }
        }

        // Count and print the number of islands
        printf("%d\n", count_islands(w, h, map));
    }

    return 0;
}