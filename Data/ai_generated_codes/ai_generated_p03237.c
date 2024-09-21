#include <stdio.h>

#define MAX_N 1500

int N;
char A[MAX_N][MAX_N];

// Function to check if a cell is empty
int is_empty(int i, int j) {
  return A[i][j] != '#';
}

// Function to calculate the sum of products of reachable pairs
long long calculate_sum_of_products() {
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (is_empty(i, j)) {
        // Explore reachable cells from the current cell
        for (int k = i; k < N; k++) {
          for (int l = j; l < N; l++) {
            if (is_empty(k, l) && (k != i || l != j)) {
              sum += (A[i][j] - '0') * (A[k][l] - '0');
            }
          }
        }
      }
    }
  }
  return sum;
}

int main() {
  scanf("%d", &N);

  // Read the board input
  for (int i = 0; i < N; i++) {
    scanf("%s", A[i]);
  }

  // Calculate and print the sum of products
  long long result = calculate_sum_of_products();
  printf("%lld\n", result);

  return 0;
}