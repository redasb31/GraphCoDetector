#include <stdio.h>

int main() {
  int N; // Number of mountains
  int H[20]; // Heights of the mountains
  int count = 1; // Count of inns from which the ocean is visible (starting with the first inn)

  // Input the number of mountains
  scanf("%d", &N);

  // Input the heights of the mountains
  for (int i = 0; i < N; i++) {
    scanf("%d", &H[i]);
  }

  // Check if the ocean is visible from each inn starting from the second inn
  for (int i = 1; i < N; i++) {
    // Flag to track if the ocean is visible from the current inn
    int visible = 1;

    // Check if the height of the current mountain is greater than or equal to the heights of all the mountains to the west
    for (int j = 0; j < i; j++) {
      if (H[j] > H[i]) {
        visible = 0; // Ocean is not visible from this inn
        break;
      }
    }

    // Increment the count if the ocean is visible
    if (visible) {
      count++;
    }
  }

  // Output the number of inns from which the ocean is visible
  printf("%d\n", count);

  return 0;
}