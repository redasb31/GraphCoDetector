#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if all enemies are defeated
int allDefeated(int **grid, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to cast the "myon" spell on a rectangle
void castMyon(int **grid, int n, int startRow, int startCol, int endRow, int endCol) {
    for (int i = startRow; i <= endRow; i++) {
        for (int j = startCol; j <= endCol; j++) {
            grid[i][j] = 1 - grid[i][j]; // Toggle the state of the enemy
        }
    }
}

// Function to find the shortest spell
char *shortestSpell(int **grid, int n) {
    char *spell = (char *)malloc(100 * sizeof(char));
    int spellLength = 0;

    // Iterate through all possible rectangles
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = i; k < n; k++) {
                for (int l = j; l < n; l++) {
                    // Cast "myon" and check if all enemies are defeated
                    castMyon(grid, n, i, j, k, l);
                    if (allDefeated(grid, n)) {
                        spell[spellLength++] = 'm';
                        spell[spellLength++] = 'y';
                        spell[spellLength++] = 'o';
                        spell[spellLength++] = 'n';
                        spell[spellLength] = '\0';
                        return spell;
                    }
                    // Revert the changes made by the spell
                    castMyon(grid, n, i, j, k, l);
                }
            }
        }
    }
    return spell;
}

int main() {
    int n;

    while (1) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }

        // Allocate memory for the grid
        int **grid = (int **)malloc(n * sizeof(int *));
        for (int i = 0; i < n; i++) {
            grid[i] = (int *)malloc(n * sizeof(int));
        }

        // Read the grid information
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &grid[i][j]);
            }
        }

        // Find the shortest spell and print it
        char *spell = shortestSpell(grid, n);
        printf("%s\n", spell);

        // Free the allocated memory
        for (int i = 0; i < n; i++) {
            free(grid[i]);
        }
        free(grid);
        free(spell);
    }

    return 0;
}