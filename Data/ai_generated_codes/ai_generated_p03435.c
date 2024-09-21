#include <stdio.h>

int main() {
  // Input the grid values
  int c[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", &c[i][j]);
    }
  }

  // Check if Takahashi's statement is correct
  int correct = 1; // Assume Takahashi is correct initially

  // Check if the differences between rows are consistent
  for (int i = 1; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (c[i][j] - c[i - 1][j] != c[i][0] - c[i - 1][0]) {
        correct = 0; // Takahashi is incorrect
        break;
      }
    }
    if (!correct) {
      break;
    }
  }

  // Check if the differences between columns are consistent
  for (int i = 0; i < 3; i++) {
    for (int j = 1; j < 3; j++) {
      if (c[i][j] - c[i][j - 1] != c[0][j] - c[0][j - 1]) {
        correct = 0; // Takahashi is incorrect
        break;
      }
    }
    if (!correct) {
      break;
    }
  }

  // Print the result
  if (correct) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}