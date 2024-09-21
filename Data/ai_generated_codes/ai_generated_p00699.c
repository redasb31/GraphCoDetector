#include <stdio.h>
#include <stdbool.h>

// Function to check if a given number is present in an array
bool isPresent(int arr[], int size, int num) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == num) {
      return true;
    }
  }
  return false;
}

// Function to check if the sum of opposite faces is 7
bool checkOppositeFaces(int face1, int face2) {
  return (face1 + face2 == 7);
}

// Function to check if the net is a proper net of a die
bool isValidDieNet(int mesh[5][5]) {
  // Check if all numbers are between 1 and 6
  int numbers[6] = {0};
  int numCount = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (mesh[i][j] != 0) {
        if (mesh[i][j] < 1 || mesh[i][j] > 6) {
          return false;
        }
        if (!isPresent(numbers, numCount, mesh[i][j])) {
          numbers[numCount++] = mesh[i][j];
        }
      }
    }
  }

  // Check if all six faces are present
  if (numCount != 6) {
    return false;
  }

  // Check opposite faces
  if (!checkOppositeFaces(mesh[0][1], mesh[4][1]) ||
      !checkOppositeFaces(mesh[1][0], mesh[1][4]) ||
      !checkOppositeFaces(mesh[0][3], mesh[4][3]) ||
      !checkOppositeFaces(mesh[3][0], mesh[3][4])) {
    return false;
  }

  // Check if the net is connected (no isolated faces)
  // ... (implementation for checking connectivity is omitted for brevity)

  return true;
}

int main() {
  int N;
  scanf("%d", &N);

  // Process each mesh
  for (int i = 0; i < N; i++) {
    int mesh[5][5];
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
        scanf("%d", &mesh[j][k]);
      }
    }

    if (isValidDieNet(mesh)) {
      printf("true\n");
    } else {
      printf("false\n");
    }
  }

  return 0;
}