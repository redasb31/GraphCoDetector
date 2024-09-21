#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to calculate the maximum score achievable from a given starting position
long long max_score(int *s, int N, int start, long long *dp) {
    // Base case: If we are already at the last lotus, our score is 0
    if (start == N - 1) {
        return 0;
    }
    // Check if we have already calculated the maximum score for this starting position
    if (dp[start] != LLONG_MIN) {
        return dp[start];
    }
    // Initialize the maximum score to a very low value
    long long max_score = LLONG_MIN;
    // Iterate over all possible values of A (distance to move forward)
    for (int A = 1; A <= N - start - 1; A++) {
        // Calculate the position we would reach after moving forward by A
        int next_pos = start + A;
        // Calculate the score we would get if we move forward by A
        long long score = s[next_pos];
        // Recursively calculate the maximum score from the next position
        long long next_max_score = max_score(s, N, next_pos, dp);
        // Update the maximum score if the current score is better
        max_score = (score + next_max_score) > max_score ? (score + next_max_score) : max_score;
    }
    // Iterate over all possible values of B (distance to move backward)
    for (int B = 1; B <= start; B++) {
        // Calculate the position we would reach after moving backward by B
        int next_pos = start - B;
        // Calculate the score we would get if we move backward by B
        long long score = s[next_pos];
        // Recursively calculate the maximum score from the next position
        long long next_max_score = max_score(s, N, next_pos, dp);
        // Update the maximum score if the current score is better
        max_score = (score + next_max_score) > max_score ? (score + next_max_score) : max_score;
    }
    // Store the calculated maximum score in the dp array
    dp[start] = max_score;
    // Return the calculated maximum score
    return max_score;
}

int main() {
    int N;
    scanf("%d", &N);
    int *s = malloc(N * sizeof(int));
    // Read the score values for each lotus
    for (int i = 0; i < N; i++) {
        scanf("%d", &s[i]);
    }
    // Initialize the dp array with a very low value to indicate that the maximum scores have not been calculated yet
    long long *dp = malloc(N * sizeof(long long));
    for (int i = 0; i < N; i++) {
        dp[i] = LLONG_MIN;
    }
    // Calculate the maximum score from the starting position (lotus at coordinate 0)
    long long max_score = max_score(s, N, 0, dp);
    // Print the maximum score
    printf("%lld\n", max_score);
    // Free the allocated memory
    free(s);
    free(dp);
    return 0;
}