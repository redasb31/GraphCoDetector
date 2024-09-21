#include <stdio.h>

#define N 100

int min(int a, int b) {
  return a < b ? a : b;
}

int main() {
  int n, p[N + 1], m[N + 1][N + 1];
  int i, j , k, l;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d %d", &p[i - 1], &p[i]);
  }

  for (i = 1; i <= n; i++) {
    m[i][i] = 0;
  }
  for(i = 2; i <= n; i++) {
    for (j = 1; j <= n - i + 1; j++) {
      l = i + j - 1;
      m[j][l] = 100000000;
      for (k = j; k <= l - 1; k++) {
        m[j][l] = min(m[j][l], m[j][k] + m[k + 1][l] + p[j - 1] * p[k] * p[l]);
      }
    }
  }
  printf("%d\n", m[1][n]);

  return 0;
}

