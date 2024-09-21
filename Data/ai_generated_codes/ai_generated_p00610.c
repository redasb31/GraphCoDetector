#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_N 64

// Function to generate the k-th lexicographically ordered carpet layout
void generate_layout(int N, long long K, char layout[MAX_N][MAX_N]) {
  // Base case: If K is 1, then the layout is all '.'
  if (K == 1) {
    memset(layout, '.', sizeof(char) * MAX_N * MAX_N);
    return;
  }

  // Calculate the number of possible layouts with the first row fixed
  long long count = (long long)pow(2, N * (N - 1));

  // If K is less than or equal to the number of layouts with the first row fixed,
  // then the first row is all '.'
  if (K <= count) {
    memset(layout[0], '.', sizeof(char) * N);
    generate_layout(N, K, layout + 1);
    return;
  }

  // Otherwise, the first row has at least one 'E'
  // Calculate the number of layouts with the first row fixed and the first character 'E'
  count = (long long)pow(2, N * (N - 1) - 1);

  // If K is less than or equal to the number of layouts with the first row fixed
  // and the first character 'E', then the first character is 'E'
  if (K <= count) {
    layout[0][0] = 'E';
    generate_layout(N, K, layout + 1);
    return;
  }

  // Otherwise, the first character is '.'
  // Calculate the number of layouts with the first row fixed, the first character '.'
  // and the second character 'E'
  count = (long long)pow(2, N * (N - 1) - 2);

  // If K is less than or equal to the number of layouts with the first row fixed,
  // the first character '.', and the second character 'E', then the second character is 'E'
  if (K <= count) {
    layout[0][0] = '.';
    layout[0][1] = 'E';
    generate_layout(N, K, layout + 1);
    return;
  }

  // Otherwise, the second character is '.'
  // Recursively generate the rest of the layout
  layout[0][0] = '.';
  layout[0][1] = '.';
  generate_layout(N, K - count, layout + 1);
}

int main() {
  int N;
  long long K;
  char layout[MAX_N][MAX_N];

  while (1) {
    scanf("%d %lld", &N, &K);
    if (N == 0 && K == 0) {
      break;
    }

    // Generate the layout
    generate_layout(N, K, layout);

    // Check if the layout is valid
    int valid = 1;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        // Check if there is a room with only one adjacent room of the same color
        int count = 0;
        if (i > 0 && layout[i - 1][j] == layout[i][j]) {
          count++;
        }
        if (i < N - 1 && layout[i + 1][j] == layout[i][j]) {
          count++;
        }
        if (j > 0 && layout[i][j - 1] == layout[i][j]) {
          count++;
        }
        if (j < N - 1 && layout[i][j + 1] == layout[i][j]) {
          count++;
        }
        if (count == 1) {
          valid = 0;
          break;
        }
      }
      if (!valid) {
        break;
      }
    }

    // Print the layout or "No"
    if (valid) {
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          printf("%c", layout[i][j]);
        }
        printf("\n");
      }
    } else {
      printf("No\n");
    }

    printf("\n");
  }

  return 0;
}