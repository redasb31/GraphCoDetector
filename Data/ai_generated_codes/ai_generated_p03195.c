#include <stdio.h>

int main() {
  // N: Number of apple colors
  int N;
  // a[i]: Number of apples of color i
  int a[100000];

  // Input the number of apple colors
  scanf("%d", &N);

  // Input the number of apples of each color
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  // Calculate the total number of apples
  int total_apples = 0;
  for (int i = 0; i < N; i++) {
    total_apples += a[i];
  }

  // If the total number of apples is odd, you win
  if (total_apples % 2 == 1) {
    printf("first\n");
  } 
  // Otherwise, Lunlun wins
  else {
    printf("second\n");
  }

  return 0;
}