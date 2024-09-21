#include <stdio.h>
#include <string.h>

int main() {
  int N, K, C;
  char S[200001];

  // Input
  scanf("%d %d %d\n", &N, &K, &C);
  scanf("%s", S);

  // Check if Takahashi has to work on the first day.
  if (S[0] != 'x') {
    // If Takahashi has to work on the first day, check if he is bound to work on any other day.
    for (int i = 1; i < N; i++) {
      // If Takahashi has to work on the first day, and the current day is not restricted by 'x' or by the 'C' days restriction, he is bound to work on this day.
      if (S[i] != 'x' && i % (C + 1) != 0) {
        printf("%d\n", i + 1); 
      }
    }
  } else {
    // If Takahashi doesn't have to work on the first day, check if he is bound to work on any other day.
    for (int i = 1; i < N; i++) {
      // If Takahashi doesn't have to work on the first day, and the current day is not restricted by 'x' or by the 'C' days restriction, he is bound to work on this day.
      if (S[i] != 'x' && i % (C + 1) == 0) {
        printf("%d\n", i + 1); 
      }
    }
  }

  return 0;
}