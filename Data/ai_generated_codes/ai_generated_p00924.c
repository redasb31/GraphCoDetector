#include <stdio.h>
#include <stdlib.h>

// Function to calculate the minimum swaps required to reorder a bit string
int minSwaps(int *bits, int n, int *runLengths, int m) {
    // Initialize the number of swaps to 0
    int swaps = 0;

    // Iterate over the run lengths
    int i = 0;
    int j = 0;
    while (i < m) {
        // Calculate the length of the current run
        int runLength = runLengths[i];

        // Iterate over the bits and swap adjacent pairs
        int k = 0;
        while (k < runLength) {
            // If the current bit is not in the correct position, swap it with the next bit
            if (bits[j] != (k % 2)) {
                // Swap the bits
                int temp = bits[j];
                bits[j] = bits[j + 1];
                bits[j + 1] = temp;

                // Increment the number of swaps
                swaps++;
            }

            // Increment the bit index and the run length counter
            j++;
            k++;
        }

        // Move to the next run length
        i++;
    }

    // Return the number of swaps
    return swaps;
}

int main() {
    // Read the input
    int n, m;
    scanf("%d %d", &n, &m);

    // Allocate memory for the bit string and run lengths
    int *bits = (int *)malloc(n * sizeof(int));
    int *runLengths = (int *)malloc(m * sizeof(int));

    // Read the bit string
    for (int i = 0; i < n; i++) {
        scanf("%d", &bits[i]);
    }

    // Read the run lengths
    for (int i = 0; i < m; i++) {
        scanf("%d", &runLengths[i]);
    }

    // Calculate the minimum swaps required
    int swaps = minSwaps(bits, n, runLengths, m);

    // Print the output
    printf("%d\n", swaps);

    // Free the allocated memory
    free(bits);
    free(runLengths);

    return 0;
}