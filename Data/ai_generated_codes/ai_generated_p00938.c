#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a team member's position and facing direction
typedef struct {
    int x;  // x-coordinate of the seat
    int y;  // y-coordinate of the seat
    char f; // Facing direction (N, E, W, S)
} Member;

// Function to calculate the minimum number of clocks needed
int calculateClocks(Member *members, int n, int w, int d) {
    // Create a 2D array to represent the office room, initialized with 0s
    int **room = (int **)malloc(d * sizeof(int *));
    for (int i = 0; i < d; i++) {
        room[i] = (int *)calloc(w, sizeof(int));
    }

    // Iterate through each member
    for (int i = 0; i < n; i++) {
        // Calculate the field of view based on the facing direction
        switch (members[i].f) {
            case 'N': // North
                for (int j = members[i].x - 45; j <= members[i].x + 45; j++) {
                    if (j >= 0 && j < w) {
                        room[members[i].y][j] = 1;
                    }
                }
                break;
            case 'E': // East
                for (int j = members[i].y - 45; j <= members[i].y + 45; j++) {
                    if (j >= 0 && j < d) {
                        room[j][members[i].x] = 1;
                    }
                }
                break;
            case 'W': // West
                for (int j = members[i].y - 45; j <= members[i].y + 45; j++) {
                    if (j >= 0 && j < d) {
                        room[j][0] = 1; // West wall
                    }
                }
                break;
            case 'S': // South
                for (int j = members[i].x - 45; j <= members[i].x + 45; j++) {
                    if (j >= 0 && j < w) {
                        room[0][j] = 1; // South wall
                    }
                }
                break;
        }
    }

    // Count the number of clocks needed by checking the room array
    int clockCount = 0;
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < w; j++) {
            if (room[i][j] == 1) {
                clockCount++;
                // Mark the surrounding area to avoid counting overlapping clocks
                for (int k = i - 45; k <= i + 45; k++) {
                    for (int l = j - 45; l <= j + 45; l++) {
                        if (k >= 0 && k < d && l >= 0 && l < w) {
                            room[k][l] = 0;
                        }
                    }
                }
            }
        }
    }

    // Free the allocated memory
    for (int i = 0; i < d; i++) {
        free(room[i]);
    }
    free(room);

    return clockCount;
}

int main() {
    int n, w, d;
    scanf("%d %d %d", &n, &w, &d);

    // Allocate memory for team members
    Member *members = (Member *)malloc(n * sizeof(Member));

    // Read the information of each member
    for (int i = 0; i < n; i++) {
        scanf("%d %d %c", &members[i].x, &members[i].y, &members[i].f);
    }

    // Calculate the minimum number of clocks
    int clockCount = calculateClocks(members, n, w, d);

    printf("%d\n", clockCount);

    // Free the allocated memory
    free(members);

    return 0;
}