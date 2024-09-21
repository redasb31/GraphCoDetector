/*
 *  This C code solves the problem of distributing N AtCoder Crackers among K users as evenly as possible.
 *  The program calculates the minimum difference between the maximum and minimum crackers received by any user.
 *
 *  Constraints:
 *      1 <= N, K <= 100
 *
 *  Input:
 *      Two integers N and K representing the number of crackers and the number of users respectively.
 *
 *  Output:
 *      The minimum possible difference between the maximum and minimum number of crackers received by a user.
 */

#include <stdio.h>

int main() {
    int N, K; // Number of crackers and number of users
    int max_diff = 0; // Maximum difference between crackers received by any two users

    // Input the number of crackers and users
    scanf("%d %d", &N, &K);

    // Calculate the ideal number of crackers per user
    int ideal_crackers = N / K;

    // Calculate the remainder
    int remainder = N % K;

    // Calculate the maximum difference
    max_diff = (ideal_crackers + (remainder > 0)) - (ideal_crackers - (remainder > 0));

    // Output the maximum difference
    printf("%d\n", max_diff);

    return 0;
}