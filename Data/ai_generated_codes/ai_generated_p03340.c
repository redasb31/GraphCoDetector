/*
 *  Author: [Your Name]
 *  Date: [Date]
 *  Problem: XOR and Sum (AtCoder ABC 164 E)
 *  Score: 500 points
 */
#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // Calculate the prefix XOR and prefix sum
  int xor_sum[n + 1] = {0};
  int sum[n + 1] = {0};
  for (int i = 0; i < n; i++) {
    xor_sum[i + 1] = xor_sum[i] ^ a[i];
    sum[i + 1] = sum[i] + a[i];
  }

  // Count the valid pairs
  long long count = 0;
  for (int l = 1; l <= n; l++) {
    for (int r = l; r <= n; r++) {
      // Check if XOR equals sum
      if (xor_sum[r] ^ xor_sum[l - 1] == sum[r] - sum[l - 1]) {
        count++;
      }
    }
  }

  printf("%lld\n", count);

  return 0;
}