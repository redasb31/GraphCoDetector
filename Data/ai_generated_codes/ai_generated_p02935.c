#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum possible value of the last ingredient
double findMax(int n, double *values) {
  // If there is only one ingredient, return its value
  if (n == 1) {
    return values[0];
  }

  // Create a temporary array to store the values of the new ingredients
  double *temp = (double *)malloc(sizeof(double) * (n - 1));

  // Calculate the values of the new ingredients for all possible combinations
  for (int i = 0; i < n - 1; i++) {
    temp[i] = (values[i] + values[i + 1]) / 2;
  }

  // Recursively call the function to find the maximum value of the remaining ingredients
  double max = findMax(n - 1, temp);

  // Free the temporary array
  free(temp);

  // Return the maximum value
  return max;
}

int main() {
  // Get the number of ingredients
  int n;
  scanf("%d", &n);

  // Allocate memory for the values of the ingredients
  double *values = (double *)malloc(sizeof(double) * n);

  // Read the values of the ingredients
  for (int i = 0; i < n; i++) {
    scanf("%lf", &values[i]);
  }

  // Find the maximum possible value of the last ingredient
  double max = findMax(n, values);

  // Print the maximum value
  printf("%.5lf\n", max);

  // Free the memory allocated for the values of the ingredients
  free(values);

  return 0;
}