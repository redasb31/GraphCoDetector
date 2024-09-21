#include <stdio.h>

// Function to find the largest rectangle in the given grid
int findLargestRectangle(int grid[5][5]) {
    int maxRectangleSize = 0;

    // Iterate over all possible rectangles
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = i; k < 5; k++) {
                for (int l = j; l < 5; l++) {
                    // Check if the current rectangle is valid (contains only 1's)
                    int isValid = 1;
                    for (int m = i; m <= k; m++) {
                        for (int n = j; n <= l; n++) {
                            if (grid[m][n] == 0) {
                                isValid = 0;
                                break;
                            }
                        }
                        if (!isValid) {
                            break;
                        }
                    }

                    // Update the maximum rectangle size if a larger valid rectangle is found
                    if (isValid) {
                        int currentRectangleSize = (k - i + 1) * (l - j + 1);
                        if (currentRectangleSize > maxRectangleSize) {
                            maxRectangleSize = currentRectangleSize;
                        }
                    }
                }
            }
        }
    }

    return maxRectangleSize;
}

int main() {
    int m; // Number of input maps
    scanf("%d", &m);

    // Process each input map
    for (int i = 0; i < m; i++) {
        int grid[5][5]; // Grid to store the map

        // Read the map from input
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                char c;
                scanf(" %c", &c);
                grid[j][k] = (c == '1') ? 1 : 0;
            }
        }

        // Find the largest rectangle in the current map
        int largestRectangleSize = findLargestRectangle(grid);

        // Print the size of the largest rectangle
        printf("%d\n", largestRectangleSize);

        // Skip the empty line between maps
        if (i < m - 1) {
            getchar(); // Read the newline character
            getchar(); // Read the empty line
        }
    }

    return 0;
}