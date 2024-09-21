#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DISCS 100
#define MAX_COLOR 4

// Structure to represent a disc
typedef struct {
    int x, y, r, c;
} Disc;

// Function to calculate the distance between two points
double distance(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

// Function to check if two discs are externally tangent
int is_externally_tangent(Disc d1, Disc d2) {
    return distance(d1.x, d1.y, d2.x, d2.y) == d1.r + d2.r;
}

// Function to check if a disc is on top of another disc
int is_on_top(Disc d1, Disc d2) {
    return distance(d1.x, d1.y, d2.x, d2.y) < d1.r + d2.r;
}

// Function to find the maximum number of removable discs
int find_max_removable(Disc discs[], int n) {
    // Create an array to store the number of removable discs for each color
    int removable[MAX_COLOR + 1] = {0};

    // Initialize the removable array
    for (int i = 0; i < n; i++) {
        removable[discs[i].c]++;
    }

    // Iterate through the discs
    for (int i = 0; i < n; i++) {
        // Check if the current disc is removable
        if (removable[discs[i].c] >= 2) {
            // Check if there is another disc of the same color that is not on top of it
            for (int j = i + 1; j < n; j++) {
                if (discs[j].c == discs[i].c && !is_on_top(discs[i], discs[j])) {
                    // If found, decrement the removable count for the color
                    removable[discs[i].c] -= 2;
                    break;
                }
            }
        }
    }

    // Calculate the total number of removable discs
    int total_removable = 0;
    for (int i = 1; i <= MAX_COLOR; i++) {
        total_removable += removable[i] / 2;
    }

    return total_removable;
}

int main() {
    int n;
    Disc discs[MAX_DISCS];

    // Read input until a zero is encountered
    while (scanf("%d", &n) && n != 0) {
        // Read the disc information
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d %d", &discs[i].x, &discs[i].y, &discs[i].r, &discs[i].c);
        }

        // Calculate the maximum number of removable discs
        int max_removable = find_max_removable(discs, n);

        // Print the result
        printf("%d\n", max_removable);
    }

    return 0;
}