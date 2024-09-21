#include <stdio.h>
#include <math.h>

int main() {
  // Declare variables to store the input values
  int N, K;

  // Read the input values from the user
  scanf("%d %d", &N, &K);

  // Initialize a variable to store the probability of winning
  double win_probability = 0.0;

  // Iterate over all possible die rolls
  for (int i = 1; i <= N; i++) {
    // Calculate the number of heads required to reach K or above
    int heads_needed = (int)ceil(log2((double)K / i));

    // Calculate the probability of getting the required number of heads
    double probability = pow(0.5, heads_needed);

    // Add the probability to the total win probability
    win_probability += probability / N;
  }

  // Print the probability of winning
  printf("%.12lf\n", win_probability);

  return 0;
}