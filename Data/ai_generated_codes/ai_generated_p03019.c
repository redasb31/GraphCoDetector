#include <stdio.h>
#include <stdlib.h>

int main() {
  // N: number of exams
  // X: maximum score on an exam
  int N, X;
  scanf("%d %d", &N, &X);

  // b_i: Aoki's score on exam i
  // l_i: minimum importance of exam i
  // u_i: maximum importance of exam i
  int *b = (int *)malloc(N * sizeof(int));
  int *l = (int *)malloc(N * sizeof(int));
  int *u = (int *)malloc(N * sizeof(int));
  for (int i = 0; i < N; i++) {
    scanf("%d %d %d", &b[i], &l[i], &u[i]);
  }

  // Calculate the minimum number of study hours required
  long long min_hours = 0;
  for (int i = 0; i < N; i++) {
    // Calculate the minimum score Takahashi needs on exam i
    long long min_score = (long long)b[i] * u[i] + 1;

    // If Takahashi needs to study for this exam, add the required hours
    if (min_score > (long long)b[i] * l[i]) {
      min_hours += min_score - b[i];
    }
  }

  printf("%lld\n", min_hours);

  free(b);
  free(l);
  free(u);

  return 0;
}