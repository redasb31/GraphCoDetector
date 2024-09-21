#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Function to perform the operation labeled k
void performOperation(int *p, int N, int k) {
  for (int i = k; i < N; i++) {
    swap(&p[i], &p[i - k]);
  }
}

int main() {
  int N;
  scanf("%d", &N);

  int p[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &p[i]);
  }

  // Array to store the operations to be performed
  int operations[100000];
  int operationCount = 0;

  // Iterate over the array p in reverse order
  for (int i = N - 1; i >= 0; i--) {
    // Find the current position of the element i in the array
    int j = 0;
    while (p[j] != i) {
      j++;
    }

    // If the element is not in its correct position, perform operations to move it
    if (j != i) {
      // If the element is to the right of its correct position
      if (j > i) {
        // Perform operations to move the element to the left until it reaches its correct position
        while (j > i) {
          operations[operationCount++] = j - i; // Store the operation label
          performOperation(p, N, j - i);       // Perform the operation
          j = i;
        }
      } else { // If the element is to the left of its correct position
        // Perform operations to move the element to the right until it reaches its correct position
        while (j < i) {
          operations[operationCount++] = i - j; // Store the operation label
          performOperation(p, N, i - j);       // Perform the operation
          j = i;
        }
      }
    }
  }

  // Print the number of operations and the operations themselves
  printf("%d\n", operationCount);
  for (int i = 0; i < operationCount; i++) {
    printf("%d\n", operations[i]);
  }

  return 0;
}