#include <stdio.h>

// Function to find the second largest element in an array
int findSecondLargest(int arr[], int start, int end) {
  // Handle edge cases where the array has less than two elements
  if (end - start + 1 < 2) {
    return -1; // Indicate no second largest element
  }

  int largest = arr[start];
  int secondLargest = arr[start + 1];

  // Find the largest and second largest elements in the array
  for (int i = start + 2; i <= end; i++) {
    if (arr[i] > largest) {
      secondLargest = largest;
      largest = arr[i];
    } else if (arr[i] > secondLargest && arr[i] != largest) {
      secondLargest = arr[i];
    }
  }

  return secondLargest;
}

int main() {
  int N;
  scanf("%d", &N);

  int P[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &P[i]);
  }

  long long sum = 0;

  // Calculate the sum of X_L,R for all pairs (L, R)
  for (int L = 1; L <= N - 1; L++) {
    for (int R = L + 1; R <= N; R++) {
      sum += findSecondLargest(P, L - 1, R - 1);
    }
  }

  printf("%lld\n", sum);

  return 0;
}