#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to calculate the initial matrix values
int calculateValue(int r, int c, int A, int B, int C) {
  return ((r * A + c * B) % C);
}

// Function to perform the write operation
void writeOperation(int r, int c, int v, int **matrix, int N) {
  matrix[r - 1][c - 1] = v;
}

// Function to perform the copy operation
void copyOperation(int r1, int c1, int r2, int c2, int **matrix, int N) {
  matrix[r2 - 1][c2 - 1] = matrix[r1 - 1][c1 - 1];
}

// Function to perform the swap row operation
void swapRowOperation(int r1, int r2, int **matrix, int N) {
  for (int c = 0; c < N; c++) {
    int temp = matrix[r1 - 1][c];
    matrix[r1 - 1][c] = matrix[r2 - 1][c];
    matrix[r2 - 1][c] = temp;
  }
}

// Function to perform the swap column operation
void swapColumnOperation(int c1, int c2, int **matrix, int N) {
  for (int r = 0; r < N; r++) {
    int temp = matrix[r][c1 - 1];
    matrix[r][c1 - 1] = matrix[r][c2 - 1];
    matrix[r][c2 - 1] = temp;
  }
}

// Function to perform the rotate left operation
void rotateLeftOperation(int **matrix, int N) {
  for (int i = 0; i < N / 2; i++) {
    for (int j = i; j < N - i - 1; j++) {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[N - 1 - j][i];
      matrix[N - 1 - j][i] = matrix[N - 1 - i][N - 1 - j];
      matrix[N - 1 - i][N - 1 - j] = matrix[j][N - 1 - i];
      matrix[j][N - 1 - i] = temp;
    }
  }
}

// Function to perform the rotate right operation
void rotateRightOperation(int **matrix, int N) {
  for (int i = 0; i < N / 2; i++) {
    for (int j = i; j < N - i - 1; j++) {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[j][N - 1 - i];
      matrix[j][N - 1 - i] = matrix[N - 1 - i][N - 1 - j];
      matrix[N - 1 - i][N - 1 - j] = matrix[N - 1 - j][i];
      matrix[N - 1 - j][i] = temp;
    }
  }
}

// Function to perform the reflect horizontal operation
void reflectHorizontalOperation(int **matrix, int N) {
  for (int r = 0; r < N / 2; r++) {
    for (int c = 0; c < N; c++) {
      int temp = matrix[r][c];
      matrix[r][c] = matrix[N - 1 - r][c];
      matrix[N - 1 - r][c] = temp;
    }
  }
}

// Function to perform the reflect vertical operation
void reflectVerticalOperation(int **matrix, int N) {
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N / 2; c++) {
      int temp = matrix[r][c];
      matrix[r][c] = matrix[r][N - 1 - c];
      matrix[r][N - 1 - c] = temp;
    }
  }
}

// Function to calculate the hash value
int calculateHash(int **matrix, int N, int D, int E, int F, int G) {
  int h = 314159265;
  for (int r = D - 1; r <= E - 1; r++) {
    for (int c = F - 1; c <= G - 1; c++) {
      h = (31 * h + matrix[r][c]) % MOD;
    }
  }
  return h;
}

int main() {
  int N, Q, A, B, C, D, E, F, G;
  scanf("%d %d %d %d %d %d %d %d %d", &N, &Q, &A, &B, &C, &D, &E, &F, &G);

  // Allocate memory for the matrix
  int **matrix = (int **)malloc(sizeof(int *) * N);
  for (int i = 0; i < N; i++) {
    matrix[i] = (int *)malloc(sizeof(int) * N);
  }

  // Initialize the matrix
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      matrix[r][c] = calculateValue(r + 1, c + 1, A, B, C);
    }
  }

  // Process the operations
  char operation[10];
  int r, c, v, r1, c1, r2, c2;
  for (int i = 0; i < Q; i++) {
    scanf("%s", operation);

    if (operation[0] == 'W') {
      scanf("%d %d %d", &r, &c, &v);
      writeOperation(r, c, v, matrix, N);
    } else if (operation[0] == 'C') {
      scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
      copyOperation(r1, c1, r2, c2, matrix, N);
    } else if (operation[0] == 'S' && operation[1] == 'R') {
      scanf("%d %d", &r1, &r2);
      swapRowOperation(r1, r2, matrix, N);
    } else if (operation[0] == 'S' && operation[1] == 'C') {
      scanf("%d %d", &c1, &c2);
      swapColumnOperation(c1, c2, matrix, N);
    } else if (operation[0] == 'R' && operation[1] == 'L') {
      rotateLeftOperation(matrix, N);
    } else if (operation[0] == 'R' && operation[1] == 'R') {
      rotateRightOperation(matrix, N);
    } else if (operation[0] == 'R' && operation[1] == 'H') {
      reflectHorizontalOperation(matrix, N);
    } else if (operation[0] == 'R' && operation[1] == 'V') {
      reflectVerticalOperation(matrix, N);
    }
  }

  // Calculate the hash value
  int hash = calculateHash(matrix, N, D, E, F, G);

  // Print the hash value
  printf("%d\n", hash);

  // Free the memory
  for (int i = 0; i < N; i++) {
    free(matrix[i]);
  }
  free(matrix);

  return 0;
}