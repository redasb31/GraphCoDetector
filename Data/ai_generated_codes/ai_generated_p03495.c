#include <stdio.h>

// Function to count the frequency of each element in the array
void countFrequency(int arr[], int n, int freq[]) {
  for (int i = 0; i < n; i++) {
    freq[arr[i]]++;
  }
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);

  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // Create an array to store the frequency of each element
  int freq[n + 1] = {0};
  countFrequency(a, n, freq);

  // Sort the frequency array in descending order
  // This will help us to choose the most frequent elements
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= i; j++) {
      if (freq[j - 1] < freq[j]) {
        int temp = freq[j - 1];
        freq[j - 1] = freq[j];
        freq[j] = temp;
      }
    }
  }

  // Calculate the minimum number of balls to rewrite
  int count = 0;
  int numDistinctElements = 0;
  for (int i = 0; i <= n; i++) {
    if (freq[i] > 0) {
      numDistinctElements++;
      // If we have reached the maximum allowed distinct elements, stop counting
      if (numDistinctElements == k) {
        break;
      }
    } else {
      count += freq[i];
    }
  }

  // Print the minimum number of balls
  printf("%d\n", count);

  return 0;
}