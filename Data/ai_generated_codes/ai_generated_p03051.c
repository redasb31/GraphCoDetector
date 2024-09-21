#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

long long int a[500005];
long long int dp[500005];

int main() {
  int n;
  scanf("%d", &n);

  // Read the input array
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
  }

  // Calculate the prefix XORs
  for (int i = 2; i <= n; ++i) {
    a[i] ^= a[i - 1];
  }

  // Initialize the DP array
  dp[0] = 1;
  dp[1] = 1;

  // Dynamic programming to count valid partitions
  for (int i = 2; i <= n; ++i) {
    // If the current XOR is the same as the previous XOR, we have one more valid partition
    if (a[i] == a[i - 1]) {
      dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    // Otherwise, we only have the previous partition as a valid option
    else {
      dp[i] = dp[i - 1];
    }
  }

  // Print the final count modulo 10^9+7
  printf("%lld\n", dp[n]);
  return 0;
}