#include <stdio.h>
#include <math.h>

#define MAX_N 200000
#define MAX_A 1000000000000LL
#define MAX_B 100

long long N, A[MAX_N], B[MAX_N];
double dp[MAX_N];

// Calculate the expected gain for a given position p
double solve(int p) {
  // If the expected gain for this position is already calculated, return it
  if (dp[p] != -1) {
    return dp[p];
  }
  // If we end the game, we get A[p] dollars
  double end_game = (double) A[p];
  // If we continue playing, we have two choices:
  // 1. Move to the left
  // 2. Move to the right
  // We take the maximum of the expected gains of these two choices
  double keep_playing = (0.5 * solve((p - 1 + N) % N) + 0.5 * solve((p + 1) % N) - (double) B[p]);
  // Return the maximum of ending the game and continuing playing
  dp[p] = fmax(end_game, keep_playing);
  return dp[p];
}

int main() {
  scanf("%lld", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%lld", &A[i]);
  }
  for (int i = 0; i < N; ++i) {
    scanf("%lld", &B[i]);
  }
  // Initialize the dp array to -1 to indicate that the expected gains are not yet calculated
  for (int i = 0; i < N; ++i) {
    dp[i] = -1;
  }
  // Calculate the expected gain for each position
  for (int i = 0; i < N; ++i) {
    solve(i);
  }
  // The expected gain of the optimal strategy is the maximum expected gain among all positions
  double max_gain = 0;
  for (int i = 0; i < N; ++i) {
    max_gain = fmax(max_gain, dp[i]);
  }
  // Print the expected gain with 10 digits after the decimal point
  printf("%.10lf\n", max_gain);
  return 0;
}