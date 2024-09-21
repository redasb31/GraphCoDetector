#include <stdio.h>
#include <string.h>

int main() {
  // Read input
  int N, Q;
  scanf("%d\n", &N);
  char S[1000001];
  scanf("%s\n", S);
  scanf("%d\n", &Q);
  int k[75];
  for (int i = 0; i < Q; i++) {
    scanf("%d ", &k[i]);
  }

  // Calculate the number of D, M, and C in the string
  int D_count = 0, M_count = 0, C_count = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == 'D') {
      D_count++;
    } else if (S[i] == 'M') {
      M_count++;
    } else if (S[i] == 'C') {
      C_count++;
    }
  }

  // Calculate k-DMC number for each k
  for (int i = 0; i < Q; i++) {
    int DMC_count = 0;
    // Loop through all possible 'D' positions
    for (int a = 0; a < N; a++) {
      if (S[a] == 'D') {
        // Loop through all possible 'M' positions
        for (int b = a + 1; b < N; b++) {
          if (S[b] == 'M' && b - a < k[i]) {
            // Loop through all possible 'C' positions
            for (int c = b + 1; c < N; c++) {
              if (S[c] == 'C' && c - a < k[i]) {
                DMC_count++;
              }
            }
          }
        }
      }
    }
    printf("%d\n", DMC_count);
  }

  return 0;
}