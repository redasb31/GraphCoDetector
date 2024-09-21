/*
 *  Problem Statement:
 *  We have an integer sequence A of length N, where A_1 = X, A_i+1 = A_i + D (1 ≤i < N ) holds.
 *  Takahashi will take some (possibly all or none) of the elements in this sequence, and Aoki will take all of the others.
 *  Let S and T be the sum of the numbers taken by Takahashi and Aoki, respectively. How many possible values of S - T are there?
 * 
 *  Constraints:
 *  -10^8 ≤X, D ≤10^8
 *  1 ≤N ≤2 ×10^5
 *  All values in input are integers.
 * 
 *  Input:
 *  N X D
 * 
 *  Output:
 *  Print the number of possible values of S - T.
 * 
 *  Sample Input 1:
 *  3 4 2
 * 
 *  Sample Output 1:
 *  8
 * 
 *  Sample Input 2:
 *  2 3 -3
 * 
 *  Sample Output 2:
 *  2
 * 
 *  Sample Input 3:
 *  100 14 20
 * 
 *  Sample Output 3:
 *  349805
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
  // Input
  long long int N, X, D;
  scanf("%lld %lld %lld", &N, &X, &D);

  // Calculate the sum of all elements in the sequence
  long long int sum = 0;
  for (long long int i = 0; i < N; i++) {
    sum += X + i * D;
  }

  // The number of possible values of S - T is equal to the number of ways Takahashi can choose the elements
  // This is equal to 2^N
  long long int possible_values = 1 << N;

  // Print the output
  printf("%lld\n", possible_values);

  return 0;
}