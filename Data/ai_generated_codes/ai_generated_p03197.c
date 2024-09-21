#include <stdio.h>

int main() {
  int N; // Number of colors
  scanf("%d", &N);

  int a[100000]; // Number of apples of each color
  int total_apples = 0; // Total number of apples

  // Read the number of apples for each color
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
    total_apples += a[i];
  }

  // Check if the total number of apples is odd or even
  if (total_apples % 2 == 0) {
    printf("second\n"); // Lunlun wins if the total is even
  } else {
    printf("first\n"); // You win if the total is odd
  }

  return 0;
}