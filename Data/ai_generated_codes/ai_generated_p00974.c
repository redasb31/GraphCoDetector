#include <stdio.h>

int main() {
  int n; // Number of cards
  scanf("%d", &n);

  int a[100000]; // Array to store the numbers on the cards
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // Calculate the minimum number of swaps
  int swaps = 0;
  for (int i = 1; i < n; i++) {
    // Check if the current element is in the correct order
    if (a[i] < a[i - 1]) {
      // If not, find the next element in the correct order
      int j = i + 1;
      while (j < n && a[j] < a[i - 1]) {
        j++;
      }
      // Swap the current element with the next element in the correct order
      if (j < n) {
        for (int k = j; k > i; k--) {
          int temp = a[k];
          a[k] = a[k - 1];
          a[k - 1] = temp;
          swaps++;
        }
      }
    }
  }

  // Print the minimum number of swaps
  printf("%d\n", swaps);

  return 0;
}