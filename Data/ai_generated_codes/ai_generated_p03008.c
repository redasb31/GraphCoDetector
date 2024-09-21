#include <stdio.h>

int main() {
  // N: Initial number of acorns
  int N;
  // g_X, s_X, b_X: Costs and gains of gold, silver, and bronze in Exchange X (X = A, B)
  int g_A, s_A, b_A, g_B, s_B, b_B;

  // Read input values
  scanf("%d", &N);
  scanf("%d %d %d", &g_A, &s_A, &b_A);
  scanf("%d %d %d", &g_B, &s_B, &b_B);

  // Calculate the maximum number of acorns achievable
  // The logic is to maximize the profit by trading in the exchange with the highest profit per acorn
  int max_acorns = N;
  int max_profit_exchange = -1;
  int max_profit = 0;

  // Check profit per acorn for each exchange for each metal
  // Exchange A
  if (g_A > 0 && g_A < N) {
    if (N / g_A > max_profit) {
      max_profit = N / g_A;
      max_profit_exchange = 0; // 0 represents Exchange A
    }
  }
  if (s_A > 0 && s_A < N) {
    if (N / s_A > max_profit) {
      max_profit = N / s_A;
      max_profit_exchange = 0;
    }
  }
  if (b_A > 0 && b_A < N) {
    if (N / b_A > max_profit) {
      max_profit = N / b_A;
      max_profit_exchange = 0;
    }
  }
  // Exchange B
  if (g_B > 0 && g_B < N) {
    if (N / g_B > max_profit) {
      max_profit = N / g_B;
      max_profit_exchange = 1; // 1 represents Exchange B
    }
  }
  if (s_B > 0 && s_B < N) {
    if (N / s_B > max_profit) {
      max_profit = N / s_B;
      max_profit_exchange = 1;
    }
  }
  if (b_B > 0 && b_B < N) {
    if (N / b_B > max_profit) {
      max_profit = N / b_B;
      max_profit_exchange = 1;
    }
  }

  // Perform trades in the exchange with the highest profit
  if (max_profit_exchange == 0) {
    // Exchange A
    if (g_A > 0 && g_A < N) {
      max_acorns += (N / g_A) * (g_A - 1);
      N %= g_A;
    }
    if (s_A > 0 && s_A < N) {
      max_acorns += (N / s_A) * (s_A - 1);
      N %= s_A;
    }
    if (b_A > 0 && b_A < N) {
      max_acorns += (N / b_A) * (b_A - 1);
      N %= b_A;
    }
  } else if (max_profit_exchange == 1) {
    // Exchange B
    if (g_B > 0 && g_B < N) {
      max_acorns += (N / g_B) * (g_B - 1);
      N %= g_B;
    }
    if (s_B > 0 && s_B < N) {
      max_acorns += (N / s_B) * (s_B - 1);
      N %= s_B;
    }
    if (b_B > 0 && b_B < N) {
      max_acorns += (N / b_B) * (b_B - 1);
      N %= b_B;
    }
  }

  // Print the maximum number of acorns
  printf("%d\n", max_acorns);

  return 0;
}