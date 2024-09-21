/*
 *  Problem Statement:
 *  Given a string S of length N-1, each character being '<' or '>',
 *  find the minimum possible sum of a good sequence of N non-negative integers.
 *  A sequence is good if it satisfies:
 *  - a_i < a_i+1 if S_i = '<'
 *  - a_i > a_i+1 if S_i = '>'
 *
 *  Constraints:
 *  2 ≤ N ≤ 5 × 10^5
 *  S is a string of length N-1 consisting of '<' and '>'
 *
 *  Input:
 *  String S
 *
 *  Output:
 *  Minimum possible sum of elements in a good sequence
 *
 *  Sample Input 1:
 *  <>>
 *
 *  Sample Output 1:
 *  3
 *
 *  Sample Input 2:
 *  <>>><<><<<<<>>><
 *
 *  Sample Output 2:
 *  28
 */

#include <stdio.h>
#include <string.h>

int main() {
    char S[500001];
    int N;

    scanf("%s", S);
    N = strlen(S) + 1;

    // Initialize the minimum possible values for the sequence
    int minSum = 0;
    int currentVal = 0;

    // Iterate through the string S
    for (int i = 0; i < N - 1; i++) {
        // If S[i] is '<', the current value must be less than the next value
        if (S[i] == '<') {
            minSum += currentVal;
            currentVal++;
        }
        // If S[i] is '>', the current value must be greater than the next value
        else if (S[i] == '>') {
            minSum += currentVal;
            currentVal--;
        }
    }

    // Add the last value to the total sum
    minSum += currentVal;

    printf("%d\n", minSum);

    return 0;
}