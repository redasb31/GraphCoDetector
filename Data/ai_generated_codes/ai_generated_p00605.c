#include <stdio.h>

int main() {
  int N, K; // Number of vampires and blood types
  int S[100]; // Amount of each blood type in fridge
  int B[100][100]; // Blood type requirements for each vampire

  while (1) {
    scanf("%d %d", &N, &K);

    // End of input
    if (N == 0 && K == 0) {
      break;
    }

    // Read blood type amounts in fridge
    for (int i = 0; i < K; i++) {
      scanf("%d", &S[i]);
    }

    // Read blood type requirements for each vampire
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < K; j++) {
        scanf("%d", &B[i][j]);
      }
    }

    // Check if enough blood for all vampires
    int canPrepare = 1; // Flag to indicate if dinner can be prepared
    for (int i = 0; i < K; i++) {
      int totalRequired = 0; // Total required amount for blood type i
      for (int j = 0; j < N; j++) {
        totalRequired += B[j][i]; // Sum up requirements for all vampires
      }
      if (totalRequired > S[i]) { // Not enough blood for this type
        canPrepare = 0;
        break;
      }
    }

    // Print result
    if (canPrepare) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }

  return 0;
}