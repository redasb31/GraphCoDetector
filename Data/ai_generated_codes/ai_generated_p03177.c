#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to perform matrix multiplication
void multiplyMatrices(int **a, int **b, int **result, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      result[i][j] = 0;
      for (int k = 0; k < n; k++) {
        result[i][j] = (result[i][j] + (long long)a[i][k] * b[k][j]) % MOD;
      }
    }
  }
}

// Function to perform matrix exponentiation
void matrixExpo(int **a, int n, long long k, int **result) {
  if (k == 1) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        result[i][j] = a[i][j];
      }
    }
    return;
  }

  int **temp = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    temp[i] = (int *)malloc(n * sizeof(int));
  }
  matrixExpo(a, n, k / 2, temp);
  multiplyMatrices(temp, temp, result, n);

  if (k % 2 == 1) {
    multiplyMatrices(result, a, temp, n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        result[i][j] = temp[i][j];
      }
    }
  }

  for (int i = 0; i < n; i++) {
    free(temp[i]);
  }
  free(temp);
}

int main() {
  int n, i, j;
  long long k;

  // Input N and K
  scanf("%d %lld", &n, &k);

  // Allocate memory for the adjacency matrix
  int **adj = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    adj[i] = (int *)malloc(n * sizeof(int));
  }

  // Input the adjacency matrix
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &adj[i][j]);
    }
  }

  // Allocate memory for the result matrix
  int **result = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    result[i] = (int *)malloc(n * sizeof(int));
  }

  // Perform matrix exponentiation
  matrixExpo(adj, n, k, result);

  // Calculate the sum of all elements in the result matrix
  long long count = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      count = (count + result[i][j]) % MOD;
    }
  }

  // Print the count
  printf("%lld\n", count);

  // Free allocated memory
  for (i = 0; i < n; i++) {
    free(adj[i]);
    free(result[i]);
  }
  free(adj);
  free(result);

  return 0;
}