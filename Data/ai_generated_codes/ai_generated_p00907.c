#include <stdio.h>
#include <math.h>

int main() {
  int degree;
  double values[100]; // Assuming a maximum degree of 97

  while (1) {
    scanf("%d", &degree);

    // End of input
    if (degree == 0) {
      break;
    }

    // Read values from input
    for (int i = 0; i <= degree + 2; i++) {
      scanf("%lf", &values[i]);
    }

    // Calculate expected values using polynomial equation
    for (int i = 0; i <= degree + 2; i++) {
      double expected_value = 1.0; // Initialize to 1 for x^0 term
      for (int j = 1; j <= degree; j++) {
        expected_value += pow(i, j); // Calculate x^j term
      }
      expected_value += i * i + 2 * i + 1; // Add x^2 + 2x + 1

      // Compare expected value with input value and find the outlier
      if (fabs(values[i] - expected_value) > 1.0) {
        printf("%d\n", i);
        break; // Only one outlier is expected
      }
    }
  }

  return 0;
}