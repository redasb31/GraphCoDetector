#include <stdio.h>
#include <stdlib.h>

#define MAX_N 200000
#define MAX_K 100000

// Structure to store jewel information
typedef struct {
    int color;
    int value;
} Jewel;

// Function to compare jewels based on their value
int compare_jewels(const void *a, const void *b) {
    Jewel *j1 = (Jewel *)a;
    Jewel *j2 = (Jewel *)b;
    return j2->value - j1->value; // Descending order of value
}

int main() {
    int N, K;
    Jewel jewels[MAX_N];

    // Input the number of jewels and colors
    scanf("%d %d", &N, &K);

    // Input jewel information
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &jewels[i].color, &jewels[i].value);
    }

    // Sort jewels based on value in descending order
    qsort(jewels, N, sizeof(Jewel), compare_jewels);

    // Initialize a boolean array to track chosen jewels
    int chosen[MAX_N] = {0};

    // Iterate through possible number of jewels to choose (1 to N)
    for (int i = 1; i <= N; i++) {
        int count = 0; // Number of chosen jewels
        int sum = 0; // Sum of values of chosen jewels
        int colors_seen[MAX_K + 1] = {0}; // Array to track colors

        // Select jewels greedily based on value and color constraint
        for (int j = 0; j < N; j++) {
            if (count == i) {
                break;
            }

            // Check if the jewel's color has already been seen
            if (colors_seen[jewels[j].color] == 1) {
                continue;
            }

            // Choose the jewel
            chosen[j] = 1;
            count++;
            sum += jewels[j].value;
            colors_seen[jewels[j].color] = 1;

            // Check if we have selected two jewels of the same color
            if (colors_seen[jewels[j].color] == 2) {
                // If we have selected two jewels of the same color, move on to the next jewel
                break;
            }
        }

        // If we haven't selected enough jewels, print -1
        if (count < i) {
            printf("-1\n");
        } else {
            // Print the maximum sum of values for the chosen jewels
            printf("%d\n", sum);
        }

        // Reset the chosen array for the next iteration
        for (int j = 0; j < N; j++) {
            chosen[j] = 0;
        }
    }

    return 0;
}