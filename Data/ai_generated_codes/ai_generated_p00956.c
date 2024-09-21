#include <stdio.h>
#include <string.h>

#define MAX_PILES 40
#define MAX_BOXES 40

// Function to check if a configuration is fair
int is_fair(char piles[][MAX_BOXES], int num_piles) {
    // Check if Alice can win by removing all black boxes
    int black_boxes = 0;
    for (int i = 0; i < num_piles; i++) {
        for (int j = 0; piles[i][j] != '\0'; j++) {
            if (piles[i][j] == 'B') {
                black_boxes++;
            }
        }
    }
    // If Alice can win, the configuration is not fair
    if (black_boxes % 2 == 0) {
        return 0;
    }

    // Check if Bob can win by removing all white boxes
    int white_boxes = 0;
    for (int i = 0; i < num_piles; i++) {
        for (int j = 0; piles[i][j] != '\0'; j++) {
            if (piles[i][j] == 'W') {
                white_boxes++;
            }
        }
    }
    // If Bob can win, the configuration is not fair
    if (white_boxes % 2 == 0) {
        return 0;
    }

    // If neither Alice nor Bob can win, the configuration is fair
    return 1;
}

// Function to calculate the total number of boxes in a configuration
int count_boxes(char piles[][MAX_BOXES], int num_piles) {
    int total_boxes = 0;
    for (int i = 0; i < num_piles; i++) {
        for (int j = 0; piles[i][j] != '\0'; j++) {
            total_boxes++;
        }
    }
    return total_boxes;
}

// Function to find the maximum number of boxes in a fair configuration
int max_fair_boxes(char piles[][MAX_BOXES], int num_piles) {
    int max_boxes = 0;
    // Iterate over all possible configurations
    for (int i = 0; i < (1 << num_piles); i++) {
        // Create a temporary configuration
        char temp_piles[MAX_PILES][MAX_BOXES];
        int temp_num_piles = 0;
        for (int j = 0; j < num_piles; j++) {
            // Include pile j in the temporary configuration if the j-th bit is set in i
            if (i & (1 << j)) {
                strcpy(temp_piles[temp_num_piles], piles[j]);
                temp_num_piles++;
            }
        }

        // Check if the temporary configuration is fair
        if (is_fair(temp_piles, temp_num_piles)) {
            // Update the maximum number of boxes if the current configuration has more boxes
            int current_boxes = count_boxes(temp_piles, temp_num_piles);
            if (current_boxes > max_boxes) {
                max_boxes = current_boxes;
            }
        }
    }
    return max_boxes;
}

int main() {
    int num_piles;
    char piles[MAX_PILES][MAX_BOXES];

    scanf("%d", &num_piles);

    for (int i = 0; i < num_piles; i++) {
        scanf("%s", piles[i]);
    }

    // Find the maximum number of boxes in a fair configuration
    int max_boxes = max_fair_boxes(piles, num_piles);

    printf("%d\n", max_boxes);

    return 0;
}