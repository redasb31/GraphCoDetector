#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to check if the current arrangement is valid
int isValid(int *pile, int n, int m) {
    int left = 0, right = n - 1;
    int count_left = 0, count_right = 0;

    // Check if both piles can be built with maximum m documents
    while (left <= right) {
        if (pile[left] > pile[right]) {
            count_left++;
            left++;
        } else {
            count_right++;
            right--;
        }

        // If any pile exceeds the limit, return 0
        if (count_left > m || count_right > m) {
            return 0;
        }
    }

    // If both piles are valid, return 1
    return 1;
}

// Function to calculate the number of valid arrangements
int countArrangements(int *pile, int n, int m) {
    int count = 0;
    int *left_pile = (int *)malloc(sizeof(int) * n);
    int *right_pile = (int *)malloc(sizeof(int) * n);

    // Iterate through all possible arrangements (2^n)
    for (int i = 0; i < (1 << n); i++) {
        int left_index = 0, right_index = 0;

        // Assign each document to left or right pile based on current arrangement
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                left_pile[left_index++] = pile[j];
            } else {
                right_pile[right_index++] = pile[j];
            }
        }

        // Check if the current arrangement is valid
        if (isValid(left_pile, left_index, m) && isValid(right_pile, right_index, m)) {
            count = (count + 1) % MOD;
        }
    }

    free(left_pile);
    free(right_pile);

    return count;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int *pile = (int *)malloc(sizeof(int) * n);

    // Read the serial numbers of the documents
    for (int i = 0; i < n; i++) {
        scanf("%d", &pile[i]);
    }

    // Calculate the number of valid arrangements
    int arrangements = countArrangements(pile, n, m);

    // Print the result
    printf("%d\n", arrangements);

    free(pile);

    return 0;
}