#include <stdio.h>
#include <stdlib.h>

// Structure to represent a committee member's convenient dates
typedef struct {
    int count; // Number of convenient dates
    int dates[100]; // Array to store convenient dates
} Member;

// Function to find the best date
int findBestDate(Member members[], int N, int Q) {
    // Initialize an array to count the frequency of each date
    int frequency[100] = {0};
    int maxCount = 0;
    int bestDate = 0;

    // Iterate through each member
    for (int i = 0; i < N; i++) {
        // Iterate through each convenient date of the member
        for (int j = 0; j < members[i].count; j++) {
            // Increment the frequency of the date
            frequency[members[i].dates[j]]++;
        }
    }

    // Find the date with the maximum frequency
    for (int i = 1; i < 100; i++) {
        if (frequency[i] >= maxCount) {
            maxCount = frequency[i];
            bestDate = i;
        }
    }

    // Return the best date if it meets the quorum requirement, otherwise return 0
    if (maxCount >= Q) {
        return bestDate;
    } else {
        return 0;
    }
}

int main() {
    int N, Q; // Number of committee members and quorum

    // Loop through each data set
    while (1) {
        // Read input for the number of committee members and quorum
        scanf("%d %d", &N, &Q);

        // End of input
        if (N == 0 && Q == 0) {
            break;
        }

        // Declare an array of Member structures
        Member members[N];

        // Read input for each committee member's convenient dates
        for (int i = 0; i < N; i++) {
            scanf("%d", &members[i].count);

            // Read the convenient dates for the member
            for (int j = 0; j < members[i].count; j++) {
                scanf("%d", &members[i].dates[j]);
            }
        }

        // Find the best date and print it
        int bestDate = findBestDate(members, N, Q);
        printf("%d\n", bestDate);
    }

    return 0;
}