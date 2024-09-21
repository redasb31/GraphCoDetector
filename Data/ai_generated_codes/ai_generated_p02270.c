#include <stdio.h>

// Function to find the minimum maximum load P
int find_min_max_load(int n, int k, int *w) {
  // Initialize the minimum maximum load P to the maximum weight
  int min_p = w[0];
  for (int i = 1; i < n; i++) {
    if (w[i] > min_p) {
      min_p = w[i];
    }
  }

  // Binary search for the minimum maximum load P
  int low = min_p;
  int high = 0;
  for (int i = 0; i < n; i++) {
    high += w[i];
  }
  while (low <= high) {
    int mid = (low + high) / 2;
    // Check if the current maximum load P is feasible
    int trucks = 1;
    int current_load = 0;
    for (int i = 0; i < n; i++) {
      if (current_load + w[i] > mid) {
        trucks++;
        current_load = w[i];
      } else {
        current_load += w[i];
      }
    }
    // If the current maximum load P is feasible, then try to decrease it
    if (trucks <= k) {
      high = mid - 1;
    } else {
      // If the current maximum load P is not feasible, then try to increase it
      low = mid + 1;
    }
  }
  // Return the minimum maximum load P
  return low;
}

int main() {
  // Read the number of packages and the number of trucks
  int n, k;
  scanf("%d %d", &n, &k);

  // Read the weights of the packages
  int w[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &w[i]);
  }

  // Find the minimum maximum load P and print it
  int min_p = find_min_max_load(n, k, w);
  printf("%d\n", min_p);

  return 0;
}