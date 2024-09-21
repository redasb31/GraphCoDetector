#include <stdio.h>
#include <math.h>

// Function to calculate the probability of getting within a certain error margin
double calculate_probability(int k, double r, double l, double p, double e, double t) {
  // Calculate the initial midpoint
  double h = (r + l) / 2;
  double probability = 1.0; // Initialize probability to 1

  // Iterate for K nights
  for (int i = 0; i < k; i++) {
    // Calculate the probability of getting the correct decision
    double correct_decision_probability = 1 - p;

    // Update L or R based on the decision
    if (h >= t) {
      l = h;
    } else {
      r = h;
    }

    // Calculate the probability of getting within the error margin
    if (fabs(h - t) <= e) {
      probability *= correct_decision_probability;
    } else {
      probability *= p; // Probability of making a mistake
    }

    // Calculate the new midpoint
    h = (r + l) / 2;
  }
  
  return probability;
}

int main() {
  int k;
  double r, l, p, e, t;

  // Read input values
  scanf("%d %lf %lf", &k, &r, &l);
  scanf("%lf", &p);
  scanf("%lf", &e);
  scanf("%lf", &t);

  // Calculate and print the probability
  double pp = calculate_probability(k, r, l, p, e, t);
  printf("%.6lf\n", pp);

  return 0;
}