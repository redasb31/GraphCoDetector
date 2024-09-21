#include <stdio.h>
#include <stdlib.h>

int main() {
  // N: the number of people
  int N;
  scanf("%d", &N);

  // X: an array to store the coordinate of each person
  int *X = malloc(N * sizeof(int));

  // Read the coordinates of each person
  for (int i = 0; i < N; i++) {
    scanf("%d", &X[i]);
  }

  // Calculate the minimum total stamina
  long long min_stamina = 0;
  for (int i = 0; i < N; i++) {
    min_stamina += (long long) (X[i] - X[N / 2]) * (X[i] - X[N / 2]);
  }

  // Print the minimum total stamina
  printf("%lld\n", min_stamina);

  // Free the allocated memory
  free(X);

  return 0;
}