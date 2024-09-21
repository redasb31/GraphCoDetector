#include <stdio.h>
#include <stdlib.h>

// Function to calculate the XOR of a range of integers in the sequence.
int xor_range(int a[], int start, int end, int K) {
  int xor = 0;
  for (int i = start; i <= end; i++) {
    xor ^= a[i];
  }
  return xor == K;
}

// Function to check if a sequence satisfies the given conditions.
int check_sequence(int a[], int M, int K) {
  // Check if each integer between 0 and 2^M - 1 occurs twice.
  int count[1 << M]; // Array to store the count of each integer.
  for (int i = 0; i < (1 << M); i++) {
    count[i] = 0;
  }
  for (int i = 0; i < (1 << M) + 1; i++) {
    count[a[i]]++;
  }
  for (int i = 0; i < (1 << M); i++) {
    if (count[i] != 2) {
      return 0;
    }
  }

  // Check if the XOR condition holds for all pairs of indices.
  for (int i = 0; i < (1 << M) + 1; i++) {
    for (int j = i + 1; j < (1 << M) + 1; j++) {
      if (a[i] == a[j] && !xor_range(a, i, j - 1, K)) {
        return 0;
      }
    }
  }

  return 1;
}

// Function to construct the sequence if it exists.
int construct_sequence(int M, int K, int a[]) {
  // Handle the base case where M is 0.
  if (M == 0) {
    a[0] = K;
    a[1] = K;
    return 1;
  }

  // Construct the sequence for M - 1.
  if (!construct_sequence(M - 1, K, a)) {
    return 0;
  }

  // Extend the sequence for M.
  int N = (1 << M);
  for (int i = 0; i < N; i++) {
    a[N + i] = a[i];
  }
  a[N * 2] = K;
  return check_sequence(a, M, K);
}

int main() {
  int M, K;
  scanf("%d %d", &M, &K);

  int *a = malloc(sizeof(int) * (1 << M) + 1);
  if (a == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  if (construct_sequence(M, K, a)) {
    for (int i = 0; i < (1 << M) + 1; i++) {
      printf("%d ", a[i]);
    }
    printf("\n");
  } else {
    printf("No such sequence exists.\n");
  }

  free(a);
  return 0;
}