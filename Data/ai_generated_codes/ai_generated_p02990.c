#include <stdio.h>

#define MOD 1000000007

// Function to calculate factorial modulo 10^9+7
long long fact(int n) {
  long long res = 1;
  for (int i = 2; i <= n; i++) {
    res = (res * i) % MOD;
  }
  return res;
}

// Function to calculate combinations modulo 10^9+7
long long comb(int n, int k) {
  return (fact(n) * (fact(k) * fact(n - k) % MOD) % MOD);
}

int main() {
  int N, K;

  // Input N and K
  scanf("%d %d", &N, &K);

  // Calculate the number of ways for each number of moves
  for (int i = 1; i <= K; i++) {
    // Calculate the number of ways to arrange blue and red balls 
    // so that Takahashi needs exactly 'i' moves
    long long ways = (comb(K, i) * comb(N - K, i - 1)) % MOD; 
    // Print the result for each 'i'
    printf("%lld\n", ways);
  }

  return 0;
}