#include <stdio.h>

int main() {
  // Input variables
  int D; // Number of days
  int c[26]; // Contest difficulty for each type
  int s[365][26]; // Satisfaction for each day and contest type
  int t[365]; // Chosen contest type for each day

  // Input the number of days
  scanf("%d", &D);

  // Input contest difficulty
  for (int i = 0; i < 26; i++) {
    scanf("%d", &c[i]);
  }

  // Input satisfaction for each day and contest type
  for (int i = 0; i < D; i++) {
    for (int j = 0; j < 26; j++) {
      scanf("%d", &s[i][j]);
    }
  }

  // Input chosen contest type for each day
  for (int i = 0; i < D; i++) {
    scanf("%d", &t[i]);
  }

  // Calculate satisfaction for each day
  int v[365];
  for (int d = 0; d < D; d++) {
    v[d] = s[d][t[d] - 1]; // t_d is 1-indexed, so we subtract 1
    for (int i = 0; i < d; i++) {
      v[d] += (c[t[d] - 1] - c[t[i] - 1]) * (c[t[d] - 1] - c[t[i] - 1]);
    }
    printf("%d\n", v[d]);
  }

  return 0;
}