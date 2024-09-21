#include <stdio.h>
#include <stdlib.h>

// Function to check if a domino placement is valid
int isValidPlacement(char grid[][1000], int N) {
    // Calculate the quality of each row and column
    int rowQuality[1000] = {0};
    int colQuality[1000] = {0};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] != '.') {
                rowQuality[i]++;
                colQuality[j]++;
            }
        }
    }

    // Check if all rows have the same quality as all columns
    for (int i = 1; i < N; i++) {
        if (rowQuality[i] != rowQuality[0] || colQuality[i] != colQuality[0]) {
            return 0;
        }
    }

    return 1;
}

// Function to find a valid domino placement
void findPlacement(int N) {
    char grid[1000][1000];
    // Initialize the grid with dots
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = '.';
        }
    }

    // Place dominoes in a zig-zag pattern
    int letter = 'a';
    for (int i = 0; i < N; i++) {
        for (int j = i % 2; j < N; j += 2) {
            if (grid[i][j] == '.') {
                grid[i][j] = letter;
                if (i + 1 < N) {
                    grid[i + 1][j] = letter;
                } else if (j + 1 < N) {
                    grid[i][j + 1] = letter;
                }
                letter++;
            }
        }
    }

    // Check if the placement is valid
    if (isValidPlacement(grid, N)) {
        // Print the grid
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%c", grid[i][j]);
            }
            printf("\n");
        }
    } else {
        // No valid placement exists
        printf("-1\n");
    }
}

int main() {
    int N;
    scanf("%d", &N);

    // Check if the input is valid
    if (N < 2 || N > 1000) {
        printf("-1\n");
        return 0;
    }

    // Find a domino placement
    findPlacement(N);

    return 0;
}