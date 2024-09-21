#include <stdio.h>

int main() {
  // Input variables
  int N, H, W;
  int x[100];

  // Read input
  scanf("%d %d %d", &N, &H, &W);
  for (int i = 0; i < N; i++) {
    scanf("%d", &x[i]);
  }

  // Calculate the open area
  int open_area = 0;
  for (int i = 0; i < N; i++) {
    // If windowpane is odd, slide it to the east
    if (i % 2 == 0) {
      open_area += (W - x[i]) * H; // Add the open area to the right of the pane
    } else {
      // If windowpane is even, slide it to the west
      open_area += x[i] * H; // Add the open area to the left of the pane
    }
  }

  // Print the open area
  printf("%d\n", open_area);

  return 0;
}