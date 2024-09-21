#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 300

int main() {
  // Input variables
  int H, W;
  char grid[MAX_SIZE][MAX_SIZE];

  // Read the input
  scanf("%d %d", &H, &W);
  for (int i = 0; i < H; i++) {
    scanf("%s", grid[i]);
  }

  // Initialize variables for counting the triples
  int count = 0;

  // Iterate over all possible triples of coins
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (grid[i][j] == '#') {
        for (int k = i + 1; k < H; k++) {
          for (int l = 0; l < W; l++) {
            if (grid[k][l] == '#' && abs(i - k) + abs(j - l) == 2) {
              for (int m = k + 1; m < H; m++) {
                for (int n = 0; n < W; n++) {
                  if (grid[m][n] == '#' && abs(k - m) + abs(l - n) == 2 && abs(i - m) + abs(j - n) == 2) {
                    // Check if the triple is valid
                    if (abs(i - k) + abs(j - l) == abs(k - m) + abs(l - n) && abs(i - k) + abs(j - l) == abs(i - m) + abs(j - n)) {
                      // Increment the count
                      count++;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  // Print the count of valid triples
  printf("%d\n", count);

  return 0;
}