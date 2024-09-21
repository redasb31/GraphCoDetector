#include <stdio.h>
#include <stdlib.h>

// Function to find the minimum number of steps required for evacuation
int evacuate(int r, int s, int p, int *seats) {
    // Initialize variables
    int steps = 0;
    int aisle = 0; // Number of passengers on the aisle
    int *next_seats = (int *)malloc(sizeof(int) * (2 * s + 1)); // Array to store positions for the next step
    int *temp; // Temporary pointer for swapping arrays

    // Loop until all passengers are evacuated
    while (p > 0) {
        // Initialize the next_seats array
        for (int i = 0; i < 2 * s + 1; i++) {
            next_seats[i] = -1;
        }

        // Move passengers from seats to aisle
        for (int i = 0; i < r * 2 * s; i++) {
            if (seats[i] != -1) {
                // Check if the seat is on the aisle
                if (i % (2 * s) == s - 1) {
                    // Move to aisle
                    if (next_seats[i / (2 * s)] == -1) {
                        next_seats[i / (2 * s)] = seats[i];
                        aisle++;
                        seats[i] = -1;
                        p--;
                    }
                } else {
                    // Move to adjacent seat towards the aisle
                    if (seats[i + 1] == -1 && (i + 1) % (2 * s) != s - 1) {
                        next_seats[i + 1] = seats[i];
                        seats[i] = -1;
                    } else if (seats[i - 1] == -1 && (i - 1) % (2 * s) != s - 1) {
                        next_seats[i - 1] = seats[i];
                        seats[i] = -1;
                    }
                }
            }
        }

        // Move passengers from the aisle backward
        for (int i = r - 1; i >= 0; i--) {
            if (next_seats[i] != -1) {
                // Move backward
                if (i == r - 1) {
                    // Evacuate passenger
                    p--;
                    aisle--;
                } else {
                    // Move to the next row
                    if (next_seats[i + 1] == -1) {
                        next_seats[i + 1] = next_seats[i];
                        aisle--;
                    }
                }
            }
        }

        // Update seats array with next_seats array
        temp = seats;
        seats = next_seats;
        next_seats = temp;

        steps++;
    }

    // Free allocated memory
    free(seats);
    free(next_seats);

    return steps;
}

int main() {
    // Read input
    int r, s, p;
    scanf("%d %d %d", &r, &s, &p);
    int *seats = (int *)malloc(sizeof(int) * (r * 2 * s));
    for (int i = 0; i < p; i++) {
        int row, seat;
        scanf("%d %d", &row, &seat);
        seats[(row - 1) * 2 * s + seat - 1] = i + 1;
    }

    // Calculate and print the minimum number of steps
    int steps = evacuate(r, s, p, seats);
    printf("%d\n", steps);

    return 0;
}