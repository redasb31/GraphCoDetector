/*
 * This program determines the number of persons who have the possibility of becoming the champion in a rock-paper-scissors tournament.
 *
 * The tournament is played as follows:
 * - N participants are arranged in a row.
 * - Two consecutive persons are randomly chosen and play a match.
 * - The loser is removed from the row.
 * - This process is repeated N-1 times, with the last person remaining being the champion.
 *
 * The result of a match between any two participants is predetermined and represented by a 2D array A.
 * A[i][j] = 0 if Person j defeats Person i.
 * A[i][j] = 1 if Person i defeats Person j.
 *
 * The program uses dynamic programming to determine the number of persons with the possibility of becoming the champion.
 *
 * Input:
 * - The number of participants (N).
 * - A 2D array A representing the results of the matches between each pair of participants.
 *
 * Output:
 * - The number of persons with the possibility of becoming the champion.
 *
 * Example:
 *
 * Input:
 * 3
 * 0
 * 1 0
 *
 * Output:
 * 2
 *
 * Explanation:
 * - Person 1 defeats Person 2.
 * - Person 2 defeats Person 3.
 * - Person 3 defeats Person 1.
 * - If Person 1 and Person 2 play the first match, Person 3 will become the champion.
 * - If Person 2 and Person 3 play the first match, Person 1 will become the champion.
 * - Therefore, there are 2 persons with the possibility of becoming the champion.
 */
#include <stdio.h>

int main() {
    int N; // Number of participants
    int A[2000][2000]; // Array representing the results of the matches between each pair of participants
    int dp[2000]; // Array to store the number of persons with the possibility of becoming the champion for each sub-tournament
    int i, j; // Loop counters

    // Read the input
    scanf("%d", &N);
    for (i = 2; i <= N; i++) {
        for (j = 1; j < i; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Initialize the dp array
    for (i = 1; i <= N; i++) {
        dp[i] = 1;
    }

    // Use dynamic programming to determine the number of persons with the possibility of becoming the champion
    for (i = N - 1; i >= 1; i--) {
        for (j = i + 1; j <= N; j++) {
            if (A[j][i] == 1) {
                dp[i] += dp[j];
            }
        }
    }

    // Print the output
    printf("%d\n", dp[1]);

    return 0;
}