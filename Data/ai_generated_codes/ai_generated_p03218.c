#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353

long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  int n;
  scanf("%d", &n);

  // Array to store the sizes of the chickens.
  long long *a = malloc(n * sizeof(long long));
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }

  // Array to store the sum of f(p) for each number of cycles.
  long long *b = malloc((n + 1) * sizeof(long long));
  for (int i = 0; i <= n; i++) {
    b[i] = 0;
  }

  // Calculate the beauty of each permutation recursively.
  long long dfs(int i, int cnt, long long min) {
    if (i == n) {
      // If all chickens have been assigned to cycles.
      if (cnt == 0) {
        // Return the beauty of the permutation.
        return min;
      } else {
        // If all chickens have not been assigned to cycles, return 0.
        return 0;
      }
    } else {
      // Calculate the beauty of the permutation by including the current chicken in the current cycle.
      long long res = dfs(i + 1, cnt, min > a[i] ? a[i] : min);

      // Calculate the beauty of the permutation by starting a new cycle with the current chicken.
      res = (res + dfs(i + 1, cnt - 1, a[i])) % MOD;

      // Return the sum of the two beauties.
      return res;
    }
  }

  // Calculate the sum of f(p) for each number of cycles.
  for (int i = 1; i <= n; i++) {
    b[i] = dfs(0, i, 1e18);
  }

  // Calculate the greatest common divisor of b[1], b[2], ..., b[n].
  long long g = b[1];
  for (int i = 2; i <= n; i++) {
    g = gcd(g, b[i]);
  }

  // Print the answer.
  printf("%lld\n", g);

  // Free memory.
  free(a);
  free(b);

  return 0;
}