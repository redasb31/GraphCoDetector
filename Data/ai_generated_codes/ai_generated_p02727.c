#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers
int compare(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
}

int main() {
  // Input variables
  int X, Y, A, B, C;
  scanf("%d %d %d %d %d", &X, &Y, &A, &B, &C);

  // Arrays to store deliciousness values
  int *p = (int *)malloc(A * sizeof(int));
  int *q = (int *)malloc(B * sizeof(int));
  int *r = (int *)malloc(C * sizeof(int));

  // Read deliciousness values
  for (int i = 0; i < A; i++) {
    scanf("%d", &p[i]);
  }
  for (int i = 0; i < B; i++) {
    scanf("%d", &q[i]);
  }
  for (int i = 0; i < C; i++) {
    scanf("%d", &r[i]);
  }

  // Sort the arrays in descending order
  qsort(p, A, sizeof(int), compare);
  qsort(q, B, sizeof(int), compare);
  qsort(r, C, sizeof(int), compare);

  // Calculate the maximum sum of deliciousness
  long long sum = 0; // Use long long to prevent overflow
  int i = 0, j = 0, k = C - 1; // Pointers for red, green, and colorless apples

  // Choose the maximum deliciousness apples until either red or green apples are exhausted
  while (i < A && j < B && X > 0 && Y > 0) {
    if (p[i] > q[j]) {
      sum += p[i];
      i++;
      X--;
    } else {
      sum += q[j];
      j++;
      Y--;
    }
  }

  // Choose remaining red apples
  while (i < A && X > 0) {
    sum += p[i];
    i++;
    X--;
  }

  // Choose remaining green apples
  while (j < B && Y > 0) {
    sum += q[j];
    j++;
    Y--;
  }

  // Choose colorless apples to maximize deliciousness
  while (k >= 0 && (X > 0 || Y > 0)) {
    if (X > 0 && (k >= 0 && r[k] > q[j])) {
      sum += r[k];
      k--;
      X--;
    } else if (Y > 0 && (k >= 0 && r[k] > p[i])) {
      sum += r[k];
      k--;
      Y--;
    } else {
      break;
    }
  }

  // Print the maximum sum
  printf("%lld\n", sum);

  // Free allocated memory
  free(p);
  free(q);
  free(r);

  return 0;
}