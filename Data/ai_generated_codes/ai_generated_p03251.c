#include <stdio.h>

int main() {
  // Read input values
  int N, M, X, Y;
  scanf("%d %d %d %d", &N, &M, &X, &Y);

  // Read cities under Empire A's control
  int x[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &x[i]);
  }

  // Read cities under Empire B's control
  int y[M];
  for (int i = 0; i < M; i++) {
    scanf("%d", &y[i]);
  }

  // Check if there exists a valid Z
  int war = 1; // Assume war by default
  for (int Z = X + 1; Z <= Y; Z++) {
    // Check condition 1: X < Z <= Y
    if (Z > X && Z <= Y) {
      // Check condition 2: x_1, x_2, ..., x_N < Z
      int condition2 = 1;
      for (int i = 0; i < N; i++) {
        if (x[i] >= Z) {
          condition2 = 0;
          break;
        }
      }

      // Check condition 3: y_1, y_2, ..., y_M ≥Z
      int condition3 = 1;
      for (int i = 0; i < M; i++) {
        if (y[i] < Z) {
          condition3 = 0;
          break;
        }
      }

      // If all conditions are met, peace
      if (condition2 && condition3) {
        war = 0;
        break;
      }
    }
  }

  // Print the result
  if (war) {
    printf("War\n");
  } else {
    printf("No War\n");
  }

  return 0;
}