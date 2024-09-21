#include <stdio.h>
#include <stdlib.h>

#define MAX_N 2000

int N;
int p[MAX_N];
int a[MAX_N];

// Function to perform the rotation operation on the path from root to vertex v
void rotate(int v) {
  int temp;
  int current = v;
  while (current != 0) {
    temp = a[current];
    a[current] = a[p[current]];
    a[p[current]] = temp;
    current = p[current];
  }
  a[0] = temp; // Rotate the value at the root
}

// Function to find the vertex with the correct value at its position
int find_mismatch(int target) {
  for (int i = 0; i < N; i++) {
    if (a[i] == target) {
      return i;
    }
  }
  return -1; // Should not happen
}

int main() {
  scanf("%d", &N);

  // Read parent array
  for (int i = 1; i < N; i++) {
    scanf("%d", &p[i]);
  }

  // Read initial values
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  int Q = 0; // Number of operations
  int operations[MAX_N];

  // Perform operations to bring the values to their correct positions
  for (int i = 1; i < N; i++) {
    int mismatch = find_mismatch(i); 
    if (mismatch != i) {
      // If the value is not at the correct position, rotate the path
      rotate(mismatch);
      operations[Q++] = mismatch; // Store the chosen vertex
    }
  }

  // Print the number of operations and the chosen vertices
  printf("%d\n", Q);
  for (int i = 0; i < Q; i++) {
    printf("%d\n", operations[i]);
  }

  return 0;
}