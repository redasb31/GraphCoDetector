#include <stdio.h>
#include <string.h>

#define MAX_N 500000
#define MAX_Q 20000

char S[MAX_N + 1];
int freq[26]; // Frequency of each lowercase letter

int main() {
  int N, Q;
  scanf("%d\n", &N);
  scanf("%s\n", S);
  scanf("%d\n", &Q);

  // Pre-calculate the frequency of each letter in S
  for (int i = 0; i < N; i++) {
    freq[S[i] - 'a']++;
  }

  for (int i = 0; i < Q; i++) {
    int type, i_q, l_q, r_q;
    char c_q;
    scanf("%d", &type);

    if (type == 1) {
      scanf("%d %c\n", &i_q, &c_q);
      // Update frequency if the character changes
      if (S[i_q - 1] != c_q) {
        freq[S[i_q - 1] - 'a']--;
        freq[c_q - 'a']++;
        S[i_q - 1] = c_q;
      }
    } else if (type == 2) {
      scanf("%d %d\n", &l_q, &r_q);
      // Reset frequency count for each letter
      memset(freq, 0, sizeof(freq));

      // Calculate frequency of letters in the substring
      for (int j = l_q - 1; j < r_q; j++) {
        freq[S[j] - 'a']++;
      }

      // Count the number of different letters
      int count = 0;
      for (int j = 0; j < 26; j++) {
        if (freq[j] > 0) {
          count++;
        }
      }

      printf("%d\n", count);
    }
  }

  return 0;
}