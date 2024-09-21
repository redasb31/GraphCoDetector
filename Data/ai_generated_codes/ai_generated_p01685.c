#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_H 5
#define MAX_W 5

// Function to calculate the expected number of cells painted to change the color at (i, j)
double expected_painted(int i, int j, int h, int w, char initial_board[MAX_H][MAX_W], char desired_board[MAX_H][MAX_W]) {
    // Calculate the number of cells that need to be painted
    int num_cells_to_paint = i * j;

    // Calculate the probability of painting the cell (i, j) with the correct color
    double prob_correct_color = (double) num_cells_to_paint / (h * w);

    // Calculate the probability of painting the cell (i, j) with the incorrect color
    double prob_incorrect_color = 1 - prob_correct_color;

    // Calculate the expected number of painted cells
    double expected_painted_cells = num_cells_to_paint * prob_incorrect_color;

    return expected_painted_cells;
}

// Function to calculate the expected number of painted cells for the entire board
double calculate_expected_painted(int h, int w, char initial_board[MAX_H][MAX_W], char desired_board[MAX_H][MAX_W]) {
    double expected_total = 0;

    // Iterate through each cell on the board
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            // If the initial color and desired color are different, calculate the expected painted cells
            if (initial_board[i - 1][j - 1] != desired_board[i - 1][j - 1]) {
                expected_total += expected_painted(i, j, h, w, initial_board, desired_board);
            }
        }
    }

    return expected_total;
}

int main() {
    int h, w;
    char initial_board[MAX_H][MAX_W], desired_board[MAX_H][MAX_W];

    // Read input until two zeros are encountered
    while (scanf("%d %d", &h, &w) == 2 && (h != 0 || w != 0)) {
        // Read the initial board configuration
        for (int i = 0; i < h; i++) {
            scanf("%s", initial_board[i]);
        }

        // Skip the blank line
        getchar();

        // Read the desired board configuration
        for (int i = 0; i < h; i++) {
            scanf("%s", desired_board[i]);
        }

        // Calculate and print the expected number of painted cells
        printf("%.9lf\n", calculate_expected_painted(h, w, initial_board, desired_board));
    }

    return 0;
}