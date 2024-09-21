#include <stdio.h>

// Function to calculate the number of holes punched at a given coordinate
int calculateHoles(int width, int height, int *foldX, int *foldY, int numFolds, int x, int y) {
  int holes = 1; // Initially, there's one hole at the given point
  
  // Iterate through the folding instructions
  for (int i = 0; i < numFolds; i++) {
    // Horizontal fold
    if (foldY[i] == y) {
      if (foldX[i] < x) {
        holes *= 2; // Double the number of holes
      }
    } 
    // Vertical fold
    else if (foldX[i] == x) {
      if (foldY[i] < y) {
        holes *= 2;
      }
    }
  }

  return holes;
}

int main() {
  int width, height, numFolds, numPunches;
  int foldDirection, foldValue, x, y;
  
  while (1) {
    scanf("%d %d %d %d", &width, &height, &numFolds, &numPunches);

    // Check for end of input
    if (width == 0 && height == 0 && numFolds == 0 && numPunches == 0) {
      break;
    }

    // Arrays to store folding instructions
    int foldX[20], foldY[20];
    
    // Read folding instructions
    for (int i = 0; i < numFolds; i++) {
      scanf("%d %d", &foldDirection, &foldValue);
      if (foldDirection == 1) {
        foldX[i] = foldValue;
        foldY[i] = -1; // Dummy value for vertical fold
      } else {
        foldY[i] = foldValue;
        foldX[i] = -1; // Dummy value for horizontal fold
      }
    }

    // Read punching instructions and calculate holes
    for (int i = 0; i < numPunches; i++) {
      scanf("%d %d", &x, &y);
      printf("%d\n", calculateHoles(width, height, foldX, foldY, numFolds, x, y));
    }
  }

  return 0;
}