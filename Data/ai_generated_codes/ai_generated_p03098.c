#include <stdio.h>

// Function to calculate the permutation f(p, q)
void calculate_f(int p[], int q[], int f[], int N) {
  for (int i = 0; i < N; i++) {
    f[p[i] - 1] = q[i]; // p[i]-th element in f is q[i]
  }
}

int main() {
  int N, K;
  scanf("%d %d", &N, &K);

  int p[N], q[N], a[N];

  // Read the input permutations
  for (int i = 0; i < N; i++) {
    scanf("%d", &p[i]);
  }
  for (int i = 0; i < N; i++) {
    scanf("%d", &q[i]);
  }

  // Initialize the first two permutations
  for (int i = 0; i < N; i++) {
    a[i] = p[i];
  }

  // Calculate the remaining permutations iteratively
  for (int i = 2; i <= K; i++) {
    // Calculate f(a[i-2], a[i-1])
    calculate_f(a, a + N, a, N);
  }

  // Print the final permutation a_K
  for (int i = 0; i < N; i++) {
    printf("%d ", a[i]);
  }

  return 0;
}