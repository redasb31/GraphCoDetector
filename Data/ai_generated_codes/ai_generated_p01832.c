#include <stdio.h>
#include <string.h>

// Function to perform left shift on a row
void leftShift(int matrix[][100], int row, int N) {
  int temp = matrix[row - 1][0];
  for (int j = 1; j <= N; j++) {
    matrix[row - 1][j - 1] = matrix[row - 1][j];
  }
  matrix[row - 1][N - 1] = temp;
}

// Function to perform right shift on a row
void rightShift(int matrix[][100], int row, int N) {
  int temp = matrix[row - 1][N - 1];
  for (int j = N - 1; j >= 1; j--) {
    matrix[row - 1][j] = matrix[row - 1][j - 1];
  }
  matrix[row - 1][0] = temp;
}

// Function to perform up shift on a column
void upShift(int matrix[][100], int col, int N) {
  int temp = matrix[0][col - 1];
  for (int i = 1; i <= N; i++) {
    matrix[i - 1][col - 1] = matrix[i][col - 1];
  }
  matrix[N - 1][col - 1] = temp;
}

// Function to perform down shift on a column
void downShift(int matrix[][100], int col, int N) {
  int temp = matrix[N - 1][col - 1];
  for (int i = N - 1; i >= 1; i--) {
    matrix[i][col - 1] = matrix[i - 1][col - 1];
  }
  matrix[0][col - 1] = temp;
}

// Function to process the operation sequence
void processSequence(int matrix[][100], int N, char *sequence, int start, int end) {
  int i = start;
  while (i < end) {
    if (sequence[i] == '(') {
      // Find the closing parenthesis
      int j = i + 1;
      int count = 1;
      while (count != 0) {
        if (sequence[j] == '(') {
          count++;
        } else if (sequence[j] == ')') {
          count--;
        }
        j++;
      }
      // Recursively process the sequence inside parentheses
      processSequence(matrix, N, sequence, i + 1, j - 1);
      // Get the repetition count
      int repetition = 0;
      j++;
      while (sequence[j] >= '0' && sequence[j] <= '9') {
        repetition = repetition * 10 + (sequence[j] - '0');
        j++;
      }
      // Repeat the sequence for the specified count
      for (int k = 0; k < repetition; k++) {
        processSequence(matrix, N, sequence, i + 1, j - 1);
      }
      // Update the index to skip the processed sequence
      i = j;
    } else {
      // Process a single operation
      char operation = sequence[i];
      int num = 0;
      i++;
      while (sequence[i] >= '0' && sequence[i] <= '9') {
        num = num * 10 + (sequence[i] - '0');
        i++;
      }
      switch (operation) {
        case 'L':
          leftShift(matrix, num, N);
          break;
        case 'R':
          rightShift(matrix, num, N);
          break;
        case 'U':
          upShift(matrix, num, N);
          break;
        case 'D':
          downShift(matrix, num, N);
          break;
      }
    }
  }
}

int main() {
  int N, L;
  char sequence[1000];
  scanf("%d %d\n", &N, &L);
  fgets(sequence, 1000, stdin);
  sequence[strlen(sequence) - 1] = '\0'; // Remove the newline character

  // Initialize the matrix
  int matrix[100][100];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      matrix[i][j] = (i * N) + (j + 1);
    }
  }

  // Process the operation sequence
  processSequence(matrix, N, sequence, 0, strlen(sequence));

  // Print the matrix
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  return 0;
}