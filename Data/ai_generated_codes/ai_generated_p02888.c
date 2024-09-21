#include <stdio.h>

int main() {
  // N: Number of sticks
  int N;
  // L: Array to store the length of each stick
  int L[2000];
  // count: Number of triangles that can be formed
  int count = 0;

  // Input the number of sticks
  scanf("%d", &N);

  // Input the length of each stick
  for (int i = 0; i < N; i++) {
    scanf("%d", &L[i]);
  }

  // Iterate through all possible combinations of 3 sticks
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      for (int k = j + 1; k < N; k++) {
        // Check if the three sticks can form a triangle
        // using the triangle inequality theorem
        if (L[i] < L[j] + L[k] && L[j] < L[i] + L[k] && L[k] < L[i] + L[j]) {
          count++;
        }
      }
    }
  }

  // Output the number of triangles
  printf("%d\n", count);

  return 0;
}