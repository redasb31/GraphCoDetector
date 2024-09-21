#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353

int N;
char A[1501][1501];

// Function to calculate the number of ways to set the remaining bulbs
long long count_ways(int i, int j) {
  // Base case: If the bulb is already set, there is only one way
  if (A[i][j] != '?') {
    return 1;
  }

  // Calculate the number of ways to set the bulb to ON and OFF
  long long count_on = 1;
  long long count_off = 1;

  // Calculate the number of ways to set the bulb to ON by checking the states of the bulbs on its path
  for (int k = 1; k <= i; k++) {
    if (A[i - k][j - k] == 'o') {
      count_on = (count_on * 2) % MOD;
    } else if (A[i - k][j - k] == 'x') {
      count_on = (count_on * 1) % MOD;
    } else if (A[i - k][j - k] == '?') {
      count_on = (count_on * 2) % MOD;
    }
  }
  for (int k = 1; k <= i; k++) {
    if (A[i - k][j + k] == 'o') {
      count_on = (count_on * 2) % MOD;
    } else if (A[i - k][j + k] == 'x') {
      count_on = (count_on * 1) % MOD;
    } else if (A[i - k][j + k] == '?') {
      count_on = (count_on * 2) % MOD;
    }
  }
  for (int k = 1; k <= N - i; k++) {
    if (A[i + k][j - k] == 'o') {
      count_on = (count_on * 2) % MOD;
    } else if (A[i + k][j - k] == 'x') {
      count_on = (count_on * 1) % MOD;
    } else if (A[i + k][j - k] == '?') {
      count_on = (count_on * 2) % MOD;
    }
  }
  for (int k = 1; k <= N - i; k++) {
    if (A[i + k][j + k] == 'o') {
      count_on = (count_on * 2) % MOD;
    } else if (A[i + k][j + k] == 'x') {
      count_on = (count_on * 1) % MOD;
    } else if (A[i + k][j + k] == '?') {
      count_on = (count_on * 2) % MOD;
    }
  }

  // Calculate the number of ways to set the bulb to OFF by checking the states of the bulbs on its path
  for (int k = 1; k <= i; k++) {
    if (A[i - k][j - k] == 'o') {
      count_off = (count_off * 1) % MOD;
    } else if (A[i - k][j - k] == 'x') {
      count_off = (count_off * 2) % MOD;
    } else if (A[i - k][j - k] == '?') {
      count_off = (count_off * 2) % MOD;
    }
  }
  for (int k = 1; k <= i; k++) {
    if (A[i - k][j + k] == 'o') {
      count_off = (count_off * 1) % MOD;
    } else if (A[i - k][j + k] == 'x') {
      count_off = (count_off * 2) % MOD;
    } else if (A[i - k][j + k] == '?') {
      count_off = (count_off * 2) % MOD;
    }
  }
  for (int k = 1; k <= N - i; k++) {
    if (A[i + k][j - k] == 'o') {
      count_off = (count_off * 1) % MOD;
    } else if (A[i + k][j - k] == 'x') {
      count_off = (count_off * 2) % MOD;
    } else if (A[i + k][j - k] == '?') {
      count_off = (count_off * 2) % MOD;
    }
  }
  for (int k = 1; k <= N - i; k++) {
    if (A[i + k][j + k] == 'o') {
      count_off = (count_off * 1) % MOD;
    } else if (A[i + k][j + k] == 'x') {
      count_off = (count_off * 2) % MOD;
    } else if (A[i + k][j + k] == '?') {
      count_off = (count_off * 2) % MOD;
    }
  }

  // Return the product of the number of ways to set the bulb to ON and OFF
  return (count_on * count_off) % MOD;
}

int main() {
  scanf("%d", &N);

  // Read the input
  for (int i = 1; i <= N - 1; i++) {
    scanf("%s", A[i] + 1);
  }

  // Calculate the number of ways to set the remaining bulbs
  long long ways = 1;
  for (int i = 1; i <= N - 1; i++) {
    for (int j = 1; j <= N - 1; j++) {
      ways = (ways * count_ways(i, j)) % MOD;
    }
  }

  // Print the answer
  printf("%lld\n", ways);

  return 0;
}