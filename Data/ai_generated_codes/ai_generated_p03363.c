// This program finds the number of non-empty contiguous subsequences of an integer array whose sum is 0.
// Input: The length of the array N and the array elements A_1 to A_N.
// Output: The number of non-empty contiguous subsequences whose sum is 0.

#include <stdio.h>

int main() {
    // Input the length of the array N.
    int N;
    scanf("%d", &N);

    // Input the array elements.
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Create a hash table to store the cumulative sums and their frequencies.
    int sum_counts[2000000001] = {0}; // Assuming the range of sum is -10^9 to 10^9

    // Initialize the cumulative sum to 0.
    int sum = 0;

    // Count the number of contiguous subsequences with sum 0.
    int count = 0;

    // Iterate over the array elements.
    for (int i = 0; i < N; i++) {
        // Update the cumulative sum.
        sum += A[i];

        // If the cumulative sum is 0, it is a valid subsequence.
        if (sum == 0) {
            count++;
        }

        // Check if the cumulative sum has been encountered before.
        if (sum_counts[sum + 1000000000] > 0) {
            // If it has, there are (sum_counts[sum + 1000000000]) contiguous subsequences ending at the current index.
            count += sum_counts[sum + 1000000000];
        }

        // Increment the frequency of the current cumulative sum.
        sum_counts[sum + 1000000000]++;
    }

    // Print the number of contiguous subsequences with sum 0.
    printf("%d\n", count);

    return 0;
}