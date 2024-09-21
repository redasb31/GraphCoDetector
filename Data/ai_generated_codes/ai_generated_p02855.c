#include <stdio.h>

int main() {
  // Input variables
  int H, W, K;
  scanf("%d %d %d", &H, &W, &K);

  // Declare a 2D array to store the cake layout
  char cake[300][300]; 

  // Read the cake layout from input
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      scanf(" %c", &cake[i][j]); 
    }
  }

  // Declare a 2D array to store the piece numbers
  int pieces[300][300]; 

  // Initialize the pieces array
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      pieces[i][j] = 0;
    }
  }

  // Assign piece numbers to the strawberries
  int piece_num = 1;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (cake[i][j] == '#') {
        pieces[i][j] = piece_num;
        piece_num++;
      }
    }
  }

  // Extend the piece numbers to cover the surrounding rectangular area
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (pieces[i][j] != 0) {
        // Expand the piece to the right
        for (int k = j + 1; k < W && cake[i][k] != '#'; k++) {
          pieces[i][k] = pieces[i][j];
        }

        // Expand the piece to the left
        for (int k = j - 1; k >= 0 && cake[i][k] != '#'; k--) {
          pieces[i][k] = pieces[i][j];
        }

        // Expand the piece downwards
        for (int k = i + 1; k < H && cake[k][j] != '#'; k++) {
          pieces[k][j] = pieces[i][j];
        }

        // Expand the piece upwards
        for (int k = i - 1; k >= 0 && cake[k][j] != '#'; k--) {
          pieces[k][j] = pieces[i][j];
        }
      }
    }
  }

  // Output the piece numbers
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      printf("%d ", pieces[i][j]);
    }
    printf("\n");
  }

  return 0;
}