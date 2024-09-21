#include <stdio.h>
#include <stdlib.h>

// Function to calculate the number of contestants advancing to the next round
int advance_contestants(int x) {
    // Special case for single-digit numbers
    if (x < 10) {
        return x;
    }
    int max_advance = 0;
    int i;
    // Iterate over pairs of consecutive digits
    for (i = 1; i < 10; i++) {
        int new_x = x;
        int digit1 = (x / (i * 10)) % 10;
        int digit2 = (x / i) % 10;
        // Replace digits with their sum
        new_x -= digit1 * (i * 10) + digit2 * i;
        new_x += (digit1 + digit2) * i;
        // Update max_advance
        if (new_x > max_advance) {
            max_advance = new_x;
        }
    }
    return max_advance;
}

// Function to calculate the maximum number of rounds
int max_rounds(int M, int* d, int* c) {
    int rounds = 0;
    int num_contestants = 0;
    int i, j;
    // Construct the initial number of contestants
    for (i = 0; i < M; i++) {
        for (j = 0; j < c[i]; j++) {
            num_contestants = num_contestants * 10 + d[i];
        }
    }
    // Simulate the rounds until fewer than 9 contestants remain
    while (num_contestants > 9) {
        num_contestants = advance_contestants(num_contestants);
        rounds++;
    }
    return rounds;
}

int main() {
    int M;
    scanf("%d", &M);
    // Allocate memory for d and c arrays
    int* d = (int*)malloc(sizeof(int) * M);
    int* c = (int*)malloc(sizeof(int) * M);
    // Read input data
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &d[i], &c[i]);
    }
    // Calculate and print the maximum number of rounds
    printf("%d\n", max_rounds(M, d, c));
    // Free allocated memory
    free(d);
    free(c);
    return 0;
}