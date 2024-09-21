#include <stdio.h>

int main() {
  // Get the number of integers
  int N;
  scanf("%d", &N);

  // Declare an array to store the integers
  int A[100];

  // Read the integers from the input
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Calculate the sum of the inverses
  double sum = 0;
  for (int i = 0; i < N; i++) {
    sum += 1.0 / A[i];
  }

  // Calculate the inverse of the sum
  double inverse = 1.0 / sum;

  // Print the result
  printf("%.16lf\n", inverse);

  return 0;
}