#include <stdio.h>
#include <stdlib.h>

// Structure to represent a seat in the cinema
typedef struct {
    int viewer; // The viewer sitting in the seat
    int occupied; // Flag indicating whether the seat is occupied (1) or not (0)
} Seat;

// Function to find the number of haters for a viewer exiting the cinema
int count_haters(Seat **cinema, int rows, int cols, int viewer, int exit_row, int exit_col) {
    // Initialize the number of haters to 0
    int haters = 0;
    // Initialize the current row and column of the viewer
    int row = viewer / rows;
    int col = viewer % rows;
    // Initialize the distance to the exit
    int distance = abs(row - exit_row) + abs(col - exit_col);
    // Iterate until the viewer reaches the exit
    while (distance > 0) {
        // Find the direction to move towards the exit
        int direction = (exit_row - row) * 10 + (exit_col - col);
        // Move in the chosen direction
        if (direction == 10) {
            col++;
        } else if (direction == -10) {
            col--;
        } else if (direction == 1) {
            row++;
        } else if (direction == -1) {
            row--;
        }
        // Check if the viewer is moving through an occupied seat
        if (cinema[row][col].occupied) {
            haters++;
        }
        // Update the distance to the exit
        distance--;
    }
    // Return the number of haters
    return haters;
}

int main() {
    // Read the number of rows and columns
    int rows;
    scanf("%d", &rows);
    // Allocate memory for the cinema
    Seat **cinema = (Seat **)malloc(rows * sizeof(Seat *));
    for (int i = 0; i < rows; i++) {
        cinema[i] = (Seat *)malloc(rows * sizeof(Seat));
    }
    // Read the exit order of the viewers
    int *exit_order = (int *)malloc(rows * rows * sizeof(int));
    for (int i = 0; i < rows * rows; i++) {
        scanf("%d", &exit_order[i]);
        // Assign the viewer to their seat
        cinema[(exit_order[i] - 1) / rows][(exit_order[i] - 1) % rows].viewer = exit_order[i];
        // Mark the seat as occupied
        cinema[(exit_order[i] - 1) / rows][(exit_order[i] - 1) % rows].occupied = 1;
    }
    // Initialize the number of hater pairs
    int hater_pairs = 0;
    // Iterate through the exit order
    for (int i = 0; i < rows * rows; i++) {
        // Find the exit row and column for the current viewer
        int exit_row = (exit_order[i] - 1) / rows;
        int exit_col = (exit_order[i] - 1) % rows;
        // Count the haters for the current viewer
        int haters = count_haters(cinema, rows, rows, exit_order[i], exit_row, exit_col);
        // Update the number of hater pairs
        hater_pairs += haters;
    }
    // Print the number of hater pairs
    printf("%d\n", hater_pairs);
    // Free the allocated memory
    free(exit_order);
    for (int i = 0; i < rows; i++) {
        free(cinema[i]);
    }
    free(cinema);
    return 0;
}