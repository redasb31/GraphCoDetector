#include <stdio.h>
#include <math.h>

int main() {
  int N;
  double p[3000];
  double probability = 0.0; // Initialize the probability to 0.0

  // Input the number of coins and probabilities
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%lf", &p[i]);
  }

  // Calculate probability for each combination
  for (int i = 0; i < (1 << N); i++) { 
    int heads = 0;
    for (int j = 0; j < N; j++) {
      if (i & (1 << j)) { 
        heads++;
      }
    }

    // If the number of heads is greater than half the number of coins,
    // calculate the probability of that combination and add it to the total probability.
    if (heads > N / 2) {
      double combination_probability = 1.0;
      for (int j = 0; j < N; j++) {
        if (i & (1 << j)) {
          combination_probability *= p[j]; 
        } else {
          combination_probability *= (1 - p[j]); 
        }
      }
      probability += combination_probability;
    }
  }

  // Print the calculated probability 
  printf("%.9lf\n", probability);

  return 0;
}