#include <stdio.h>

int main() {
  int N; // Number of rolls
  int D[100][2]; // Array to store the results of each roll

  // Read the number of rolls
  scanf("%d", &N);

  // Read the results of each roll
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &D[i][0], &D[i][1]);
  }

  // Check for three consecutive doublets
  int doubletsCount = 0; // Counter for consecutive doublets
  for (int i = 0; i < N - 2; i++) {
    // Check if the current roll is a doublet
    if (D[i][0] == D[i][1]) {
      doubletsCount++;
    } else {
      doubletsCount = 0; // Reset the counter if not a doublet
    }
    // Check if there are at least three consecutive doublets
    if (doubletsCount >= 3) {
      printf("Yes\n");
      return 0; // Exit if three consecutive doublets are found
    }
  }

  // If no three consecutive doublets are found
  printf("No\n");
  return 0;
}