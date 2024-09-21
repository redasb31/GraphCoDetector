#include <stdio.h>
#include <string.h>

#define MAX_N 1000000000
#define MAX_A 1000
#define MAX_B 1000
#define MAX_Q 1000

int n, a, b, q;
char secret[MAX_N + 1];
int hint_pos[MAX_A];
char hint_letter[MAX_A];
int hint_sub_start[MAX_B];
int hint_sub_len[MAX_B];

void solve() {
  // Initialize secret string with '?'
  memset(secret, '?', sizeof(secret));

  // Fill in the letters from direct hints
  for (int i = 0; i < a; i++) {
    secret[hint_pos[i] - 1] = hint_letter[i];
  }

  // Process substring hints
  for (int i = 0; i < b; i++) {
    // Find the substring length
    int len = hint_sub_len[i];

    // If the length is 0, it means it's the end of the previous substring, skip it
    if (len == 0) {
      continue;
    }

    // Iterate through the substring
    for (int j = 0; j < len; j++) {
      // Copy the letter from the starting position of the substring to the current position
      secret[hint_sub_start[i] - 1 + j] = secret[hint_sub_start[i - 1] - 1 + j];
    }
  }

  // Output the answer
  for (int i = 0; i < q; i++) {
    printf("%c", secret[i]);
  }
  printf("\n");
}

int main() {
  // Read input
  scanf("%d %d %d %d", &n, &a, &b, &q);

  // Read letter hints
  for (int i = 0; i < a; i++) {
    scanf("%d %c", &hint_pos[i], &hint_letter[i]);
  }

  // Read substring hints
  for (int i = 0; i < b; i++) {
    scanf("%d %d", &hint_sub_start[i], &hint_sub_len[i]);
  }

  // Solve the puzzle
  solve();

  return 0;
}