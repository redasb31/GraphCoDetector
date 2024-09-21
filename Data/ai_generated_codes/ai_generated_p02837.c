#include <stdio.h>
#include <stdbool.h>

#define MAX_N 15

int main() {
  int N; // Number of people
  int A[MAX_N]; // Number of testimonies for each person
  int x[MAX_N][MAX_N]; // Person being testified about
  int y[MAX_N][MAX_N]; // Testimony type (0: unkind, 1: honest)

  // Input
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
    for (int j = 1; j <= A[i]; j++) {
      scanf("%d %d", &x[i][j], &y[i][j]);
    }
  }

  // Initialize all people as potentially honest
  bool honest[MAX_N + 1]; 
  for (int i = 1; i <= N; i++) {
    honest[i] = true;
  }

  // Check for inconsistencies
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= A[i]; j++) {
      // If person i testifies person x[i][j] is honest
      if (y[i][j] == 1) {
        // If person x[i][j] is marked as unkind, there's an inconsistency
        if (!honest[x[i][j]]) {
          honest[i] = false;
          break; // No need to check further testimonies of this person
        }
      } else { // If person i testifies person x[i][j] is unkind
        // If person x[i][j] is marked as honest, there's an inconsistency
        if (honest[x[i][j]]) {
          honest[i] = false;
          break; // No need to check further testimonies of this person
        }
      }
    }
  }

  // Count honest people
  int count = 0;
  for (int i = 1; i <= N; i++) {
    if (honest[i]) {
      count++;
    }
  }

  printf("%d\n", count);

  return 0;
}