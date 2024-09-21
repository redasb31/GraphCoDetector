#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  // Define the value of m
  int m = 3;

  // Initialize the matrix
  long long a[N][N];

  // Fill the first row with consecutive numbers starting from m + 1
  for (int i = 0; i < N; i++) {
    a[0][i] = m + 1 + i;
  }

  // Fill the rest of the rows
  for (int i = 1; i < N; i++) {
    // The first element of each row is calculated based on the last element of the previous row and m
    a[i][0] = a[i - 1][N - 1] + m; 
    for (int j = 1; j < N; j++) {
      // The remaining elements are calculated based on the previous element in the same row and m
      a[i][j] = a[i][j - 1] + m; 
    }
  }

  // Print the matrix
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%lld ", a[i][j]);
    }
    printf("\n");
  }

  return 0;
}