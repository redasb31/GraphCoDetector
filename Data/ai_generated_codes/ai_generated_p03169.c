#include <stdio.h>
#include <math.h>

int main() {
  // Read the number of dishes and the number of sushi on each dish
  int N;
  scanf("%d", &N);
  int a[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  // Calculate the expected number of operations
  double expected_operations = 0.0;
  int total_sushi = 0;
  for (int i = 0; i < N; i++) {
    total_sushi += a[i];
  }

  // For each sushi, calculate the expected number of operations to eat it
  for (int i = 1; i <= total_sushi; i++) {
    expected_operations += (double) N / (total_sushi - i + 1);
  }

  // Print the result
  printf("%.10lf\n", expected_operations);

  return 0;
}