/*
 *  Problem Statement:
 *  There are N strings arranged in a row.
 *  It is known that, for any two adjacent strings, the string to the left is lexicographically smaller than the string to the right.
 *  That is, S_1<S_2<...<S_N holds lexicographically, where S_i is the i-th string from the left.
 *  At least how many different characters are contained in S_1,S_2,...,S_N, if the length of S_i is known to be A_i?
 *
 *  Constraints:
 *  1 ≤N ≤2×10^5
 *  1 ≤A_i ≤10^9
 *  A_i is an integer.
 *
 *  Note:
 *  The strings do not necessarily consist of English alphabet; there can be arbitrarily many different characters (and the lexicographic order is defined for those characters).
 *
 *  Input:
 *  Input is given from Standard Input in the following format:
 *  N
 *  A_1 A_2 ... A_N
 *
 *  Output:
 *  Print the minimum possible number of different characters contained in the strings.
 *
 *  Sample Input 1:
 *  3
 *  3 2 1
 *
 *  Sample Output 1:
 *  2
 *
 *  The number of different characters contained in S_1,S_2,...,S_N would be 3 when, for example, S_1=abc, S_2=bb and S_3=c.
 *  However, if we choose the strings properly, the number of different characters can be 2.
 *
 *  Sample Input 2:
 *  5
 *  2 3 2 1 2
 *
 *  Sample Output 2:
 *  2
 */
#include <stdio.h>

int main() {
    int N; // Number of strings
    scanf("%d", &N);

    int A[200000]; // Array to store the lengths of the strings
    int i;
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // The minimum number of different characters is the number of strings that have a length greater than 1.
    int count = 0;
    for (i = 0; i < N; i++) {
        if (A[i] > 1) {
            count++;
        }
    }

    // We need at least one character for each string that has length 1.
    count += (N - count);

    printf("%d\n", count);

    return 0;
}