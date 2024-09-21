#include <stdio.h>
#include <string.h>

int main() {
  // N: Number of problems
  // M: Number of submissions
  int N, M;
  scanf("%d %d", &N, &M);

  // Array to store the number of WAs before the first AC for each problem
  int WA_before_AC[N + 1] = {0};

  // Loop through each submission
  for (int i = 0; i < M; i++) {
    // p: Problem number
    // S: Verdict (AC or WA)
    int p;
    char S[4];
    scanf("%d %s", &p, S);

    // If the verdict is AC
    if (strcmp(S, "AC") == 0) {
      // If this is the first AC for this problem, update the WA_before_AC array
      if (WA_before_AC[p] == 0) {
        WA_before_AC[p] = 1;
      }
    } else {
      // If the verdict is WA, increment the WA count for the problem
      WA_before_AC[p]++;
    }
  }

  // Calculate the number of correct answers and penalties
  int correct_answers = 0;
  int penalties = 0;
  for (int i = 1; i <= N; i++) {
    if (WA_before_AC[i] > 0) {
      correct_answers++;
      penalties += WA_before_AC[i] - 1;
    }
  }

  // Print the number of correct answers and penalties
  printf("%d %d\n", correct_answers, penalties);

  return 0;
}