#include <stdio.h>

int main() {
  // N: the number of positive integers
  int N;
  scanf("%d", &N);

  // a: array to store the positive integers
  int a[3000]; 

  // Read the positive integers from the input
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  // Initialize the maximum value of f to 0
  int max_f = 0;

  // Iterate over all possible values of m
  for (int m = 0; m < 100000; m++) {
    // Calculate the value of f(m)
    int f = 0;
    for (int i = 0; i < N; i++) {
      f += (m % a[i]);
    }

    // Update the maximum value of f
    if (f > max_f) {
      max_f = f;
    }
  }

  // Print the maximum value of f
  printf("%d\n", max_f);

  return 0;
}