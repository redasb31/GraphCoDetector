#include <stdio.h>

int main() {
  // N: number of spots (excluding spot 0)
  // Q: number of tectonic movements
  // S: temperature decrease per altitude increase
  // T: temperature increase per altitude decrease
  int N, Q, S, T;
  scanf("%d %d %d %d", &N, &Q, &S, &T);

  // A: array storing altitudes of spots (A[0] is always 0)
  int A[N + 1];
  for (int i = 0; i <= N; i++) {
    scanf("%d", &A[i]);
  }

  // Process each tectonic movement
  for (int j = 1; j <= Q; j++) {
    // L, R: range of spots affected by the tectonic movement
    // X: change in altitude for the affected spots
    int L, R, X;
    scanf("%d %d %d", &L, &R, &X);

    // Apply the altitude change to the affected spots
    for (int k = L; k <= R; k++) {
      A[k] += X;
    }

    // Calculate the temperature at Mr. JOI's house (spot N)
    int temperature = 0;
    for (int i = 0; i < N; i++) {
      // Temperature change based on altitude difference
      if (A[i] < A[i + 1]) {
        temperature -= (A[i + 1] - A[i]) * S;
      } else {
        temperature += (A[i] - A[i + 1]) * T;
      }
    }

    // Print the temperature at Mr. JOI's house after the movement
    printf("%d\n", temperature);
  }

  return 0;
}