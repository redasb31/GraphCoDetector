#include <stdio.h>

int main() {
  // N: number of problems
  // A, B: score ranges for the three problems in a contest
  int N, A, B;
  scanf("%d", &N);
  scanf("%d %d", &A, &B);

  // P: array to store the scores of the problems
  int P[100];
  for (int i = 0; i < N; i++) {
    scanf("%d", &P[i]);
  }

  // count1: number of problems with score <= A
  // count2: number of problems with score between A+1 and B (inclusive)
  // count3: number of problems with score >= B+1
  int count1 = 0, count2 = 0, count3 = 0;
  for (int i = 0; i < N; i++) {
    if (P[i] <= A) {
      count1++;
    } else if (P[i] >= A + 1 && P[i] <= B) {
      count2++;
    } else if (P[i] >= B + 1) {
      count3++;
    }
  }

  // Calculate the maximum number of contests
  int max_contests = 0;
  // Find the minimum of count1, count2, and count3
  int min_count = count1;
  if (count2 < min_count) {
    min_count = count2;
  }
  if (count3 < min_count) {
    min_count = count3;
  }
  // Calculate the maximum number of contests possible
  max_contests = min_count;

  printf("%d\n", max_contests);

  return 0;
}