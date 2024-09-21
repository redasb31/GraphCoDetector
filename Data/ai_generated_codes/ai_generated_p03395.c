#include <stdio.h>
#include <limits.h>

// Function to calculate the minimum cost to transform sequence a to b
long long min_cost(int n, int a[], int b[]) {
  long long cost = 0;  // Initialize the cost
  int i;

  // Iterate through each element
  for (i = 0; i < n; ++i) {
    // Check if the elements are already equal
    if (a[i] == b[i]) {
      continue;
    }

    // Find the smallest k that can transform a[i] to b[i]
    int k = 1;
    while (a[i] % k != b[i] % k) {
      k++;
    }

    // Update the cost with 2^k
    cost += 1LL << k;
  }

  // Return the minimum cost
  return cost;
}

int main() {
  int n;
  scanf("%d", &n);

  int a[50], b[50];

  // Input the sequences
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
  }

  // Calculate the minimum cost
  long long cost = min_cost(n, a, b);

  // Print the minimum cost or -1 if impossible
  if (cost == LLONG_MAX) {
    printf("-1\n");
  } else {
    printf("%lld\n", cost);
  }

  return 0;
}