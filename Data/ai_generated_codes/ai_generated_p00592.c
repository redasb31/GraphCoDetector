#include <stdio.h>
#include <stdlib.h>

// Structure to represent a commercial slot
typedef struct {
    int start;
    int end;
} CommercialSlot;

// Function to compare two commercial slots based on their start time
int compareCommercialSlots(const void *a, const void *b) {
    CommercialSlot *slotA = (CommercialSlot *)a;
    CommercialSlot *slotB = (CommercialSlot *)b;
    return slotA->start - slotB->start;
}

// Function to find the maximum time duration without commercials
int findMaxDuration(int n, int p, int q, CommercialSlot **channels) {
    int maxDuration = 0;
    int currentStart = p;
    int currentEnd = q;

    // Sort commercial slots for each channel
    for (int i = 0; i < n; i++) {
        qsort(channels[i], channels[i][0], sizeof(CommercialSlot), compareCommercialSlots);
    }

    // Iterate over the time interval
    while (currentStart < currentEnd) {
        // Find the earliest commercial slot among all channels
        int earliestStart = currentEnd;
        int earliestChannel = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < channels[i][0]; j++) {
                if (channels[i][j].start >= currentStart && channels[i][j].start < earliestStart) {
                    earliestStart = channels[i][j].start;
                    earliestChannel = i;
                    break; // No need to check further in the same channel
                }
            }
        }

        // If no commercial found, the current segment is free
        if (earliestChannel == -1) {
            maxDuration += currentEnd - currentStart;
            currentStart = currentEnd;
        } else {
            // Update current start to the end of the earliest commercial slot
            currentStart = channels[earliestChannel][0].end;
        }
    }

    return maxDuration;
}

int main() {
    int n, p, q;
    while (1) {
        scanf("%d %d %d", &n, &p, &q);

        // Terminate if input is 0 0 0
        if (n == 0 && p == 0 && q == 0) {
            break;
        }

        // Allocate memory for channels and commercial slots
        CommercialSlot **channels = (CommercialSlot **)malloc(n * sizeof(CommercialSlot *));
        for (int i = 0; i < n; i++) {
            int k;
            scanf("%d", &k);
            channels[i] = (CommercialSlot *)malloc((k + 1) * sizeof(CommercialSlot));
            channels[i][0] = k; // Store the number of commercial slots
            for (int j = 1; j <= k; j++) {
                scanf("%d %d", &channels[i][j].start, &channels[i][j].end);
            }
        }

        // Calculate and print the maximum duration
        int maxDuration = findMaxDuration(n, p, q, channels);
        printf("%d\n", maxDuration);

        // Free allocated memory
        for (int i = 0; i < n; i++) {
            free(channels[i]);
        }
        free(channels);
    }

    return 0;
}