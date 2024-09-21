#include <stdio.h>
#include <stdint.h>
#include <limits.h>

// Function to calculate the number of integers with a '1' bit at a given position
uint64_t count_ones(uint64_t A, uint64_t B, int pos) {
    // Calculate the number of integers with a '1' bit at the given position within the range [A, B]
    uint64_t count = 0;
    uint64_t mask = (uint64_t)1 << (pos - 1);
    for (uint64_t i = A; i <= B; i++) {
        if (i & mask) {
            count++;
        }
    }
    return count;
}

// Function to find the leftmost '1' bit in a number
int find_leftmost_one(uint64_t num) {
    int pos = 64;
    while (pos > 0) {
        if ((num >> (pos - 1)) & 1) {
            return pos;
        }
        pos--;
    }
    return 0; // No '1' bits found
}

// Function to check if two numbers have the same bit pattern from a given position onwards
int same_pattern(uint64_t A, uint64_t B, int pos) {
    // Check if both numbers have the same bit pattern from the specified position to the right
    return (A >> pos) == (B >> pos);
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF && n != 0) {
        // Read the number of bits and the counts for each bit
        uint64_t k[64];
        for (int i = 0; i < n; i++) {
            scanf("%llu", &k[i]);
        }

        // Calculate the lower bound (A) and upper bound (B) for the range
        uint64_t A = 1; // Start with 1 as the minimum allowed value
        uint64_t B = ULLONG_MAX; // Start with the maximum unsigned long long value
        int pos = 1; // Starting from the least significant bit
        int unique = 1; // Flag to track if the solution is unique

        // Loop through the provided counts, adjusting the range [A, B] based on each bit
        while (pos <= n && unique) {
            // Calculate the number of '1' bits in the current range
            uint64_t current_count = count_ones(A, B, pos);

            // If the number of '1' bits doesn't match the provided count
            if (current_count != k[pos - 1]) {
                // If the current count is less than the target count
                if (current_count < k[pos - 1]) {
                    // If the leftmost '1' bit in B is at a position less than the current position
                    if (find_leftmost_one(B) < pos) {
                        // Set A to the number where the leftmost '1' bit is at the current position
                        A = (uint64_t)1 << (pos - 1);
                    } else {
                        // Set B to the number where the leftmost '1' bit is at the current position
                        B = (uint64_t)1 << (pos - 1);
                    }
                } else { // If the current count is greater than the target count
                    // Set B to the number where the leftmost '1' bit is at the current position
                    B = (uint64_t)1 << (pos - 1);
                }
            } else { // If the number of '1' bits matches the target count
                // If the leftmost '1' bit in A is at a position less than the current position
                if (find_leftmost_one(A) < pos) {
                    // Set A to the number where the leftmost '1' bit is at the current position
                    A = (uint64_t)1 << (pos - 1);
                }
                // If the leftmost '1' bit in B is at a position less than the current position
                if (find_leftmost_one(B) < pos) {
                    // Set B to the number where the leftmost '1' bit is at the current position
                    B = (uint64_t)1 << (pos - 1);
                }
            }

            // Check if the range is valid (A <= B)
            if (A > B) {
                unique = 0; // No valid solution
            } else {
                // Check for multiple possible solutions by comparing bit patterns
                if (same_pattern(A, B, pos) && (pos < n || (pos == n && A < B))) {
                    unique = 0; // Multiple solutions exist
                }
            }

            pos++; // Move to the next bit position
        }

        // Output the results based on the uniqueness of the solution
        if (!unique) {
            if (A > B) {
                printf("None\n");
            } else {
                printf("Many\n");
            }
        } else {
            printf("%llu %llu\n", A, B);
        }
    }

    return 0;
}