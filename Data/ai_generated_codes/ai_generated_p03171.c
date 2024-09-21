#include <stdio.h>

int main() {
  // Input the number of elements in the sequence
  int N;
  scanf("%d", &N);

  // Input the sequence of numbers
  int a[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  // Calculate the difference between Taro's and Jiro's scores
  long long X = 0; // Taro's score
  long long Y = 0; // Jiro's score
  int left = 0; // Index of the leftmost element
  int right = N - 1; // Index of the rightmost element

  // Play the game optimally
  while (left <= right) {
    // Taro's turn: Choose the element that maximizes the difference
    if (a[left] > a[right]) {
      X += a[left];
      left++;
    } else {
      X += a[right];
      right--;
    }

    // Jiro's turn: Choose the element that minimizes the difference
    if (left <= right) {
      if (a[left] > a[right]) {
        Y += a[right];
        right--;
      } else {
        Y += a[left];
        left++;
      }
    }
  }

  // Print the final result
  printf("%lld\n", X - Y);

  return 0;
}