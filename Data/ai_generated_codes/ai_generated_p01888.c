#include <stdio.h>
#include <math.h>

// Function to calculate the expected cost of a parallel test
double expected_cost(int R_PASS, int R_RC, int K, int *T, int start, int end) {
  // Base case: If start equals end, then the bug is found, and the cost is T[0]
  if (start == end) {
    return T[0];
  }

  // Calculate the middle point of the range
  int mid = (start + end) / 2;

  // Calculate the expected cost of testing revisions from start to mid
  double expected_cost_left = expected_cost(R_PASS, R_RC, K, T, start, mid);

  // Calculate the expected cost of testing revisions from mid + 1 to end
  double expected_cost_right = expected_cost(R_PASS, R_RC, K, T, mid + 1, end);

  // Calculate the expected cost of testing the middle point
  double expected_cost_mid = 0;
  for (int i = 0; i <= K; i++) {
    // The probability of i tests failing in a parallel test is 1/(end - start + 1)
    expected_cost_mid += (double) T[i] / (end - start + 1);
  }

  // Return the minimum expected cost among the three options
  return fmin(expected_cost_left, fmin(expected_cost_right, expected_cost_mid));
}

int main() {
  int R_PASS, R_RC, K;
  int T[31];

  // Read the input
  scanf("%d %d %d", &R_PASS, &R_RC, &K);
  for (int i = 0; i <= K; i++) {
    scanf("%d", &T[i]);
  }

  // Calculate the minimum expected cost
  double min_expected_cost = expected_cost(R_PASS, R_RC, K, T, R_PASS + 1, R_RC);

  // Print the minimum expected cost
  printf("%.7lf\n", min_expected_cost);

  return 0;
}