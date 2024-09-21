#include <stdio.h>
#include <limits.h>

// Function to calculate the total frustration for a given arrangement of sages
int calculate_frustration(int n, int *a, int *w, int *arrangement) {
  int total_frustration = 0;
  for (int i = 0; i < n; i++) {
    // Check if the sage is right-handed and a left-handed sage is on his right
    if (a[i] == 0 && arrangement[(i + 1) % n] == 1) {
      total_frustration += w[i];
    }
    // Check if the sage is left-handed and a right-handed sage is on his left
    if (a[i] == 1 && arrangement[(i + n - 1) % n] == 0) {
      total_frustration += w[i];
    }
  }
  return total_frustration;
}

// Function to find the minimum frustration achievable
int find_min_frustration(int n, int *a, int *w) {
  int min_frustration = INT_MAX;
  // Generate all possible arrangements of sages
  for (int i = 0; i < (1 << n); i++) {
    int arrangement[n];
    // Convert the integer 'i' to a binary representation for the arrangement
    for (int j = 0; j < n; j++) {
      arrangement[j] = (i >> j) & 1;
    }
    // Calculate the frustration for the current arrangement
    int frustration = calculate_frustration(n, a, w, arrangement);
    // Update the minimum frustration if necessary
    if (frustration < min_frustration) {
      min_frustration = frustration;
    }
  }
  return min_frustration;
}

int main() {
  int n;
  scanf("%d", &n);
  int a[n], w[n];
  // Read the hand information and frustration levels
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &w[i]);
  }
  // Find the minimum frustration and print it
  int min_frustration = find_min_frustration(n, a, w);
  printf("%d\n", min_frustration);
  return 0;
}