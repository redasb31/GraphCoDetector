#include <stdio.h>
#include <stdlib.h>

// Structure to represent a cube in the cuboid
typedef struct {
    int x;
    int y;
    int z;
} Cube;

// Function to check if two cubes are connected
int isConnected(Cube a, Cube b) {
    // Cubes are connected if they share a face
    if (abs(a.x - b.x) == 1 && a.y == b.y && a.z == b.z) return 1;
    if (abs(a.y - b.y) == 1 && a.x == b.x && a.z == b.z) return 1;
    if (abs(a.z - b.z) == 1 && a.x == b.x && a.y == b.y) return 1;
    return 0;
}

// Function to perform Depth-First Search (DFS) from a given cube
void dfs(Cube cube, int A, int B, int C, int **visited, Cube *cubes, int N) {
    visited[cube.x][cube.y][cube.z] = 1; // Mark current cube as visited
    
    // Iterate through all other cubes and check if connected and not visited
    for (int i = 0; i < N; i++) {
        if (isConnected(cube, cubes[i]) && !visited[cubes[i].x][cubes[i].y][cubes[i].z]) {
            dfs(cubes[i], A, B, C, visited, cubes, N); // Recursively explore connected cubes
        }
    }
}

// Function to count the connected components in the cuboid
int countComponents(int A, int B, int C, int N, Cube *cubes) {
    // Allocate 3D array to track visited cubes
    int ***visited = (int ***) malloc(A * sizeof(int **));
    for (int i = 0; i < A; i++) {
        visited[i] = (int **) malloc(B * sizeof(int *));
        for (int j = 0; j < B; j++) {
            visited[i][j] = (int *) malloc(C * sizeof(int));
            for (int k = 0; k < C; k++) {
                visited[i][j][k] = 0; // Initialize all cubes as not visited
            }
        }
    }

    int count = 0; // Initialize connected component count

    // Iterate through all cubes
    for (int i = 0; i < N; i++) {
        if (!visited[cubes[i].x][cubes[i].y][cubes[i].z]) {
            count++; // Increment count for a new component
            dfs(cubes[i], A, B, C, visited, cubes, N); // Explore the connected component
        }
    }

    // Free allocated memory
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < B; j++) {
            free(visited[i][j]);
        }
        free(visited[i]);
    }
    free(visited);

    return count;
}

int main() {
    int A, B, C, N;
    scanf("%d %d %d %d", &A, &B, &C, &N); // Read input dimensions and number of removed cubes

    // Allocate memory for storing removed cubes
    Cube *cubes = (Cube *) malloc(N * sizeof(Cube));

    // Read the coordinates of the removed cubes
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &cubes[i].x, &cubes[i].y, &cubes[i].z);
    }

    // Calculate and print the number of connected components
    int componentCount = countComponents(A, B, C, N, cubes);
    printf("%d\n", componentCount);

    // Free allocated memory
    free(cubes);

    return 0;
}