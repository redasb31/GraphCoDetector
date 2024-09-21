#include <stdio.h>
#include <string.h>

int main() {
  char S[16]; // String to store the results of Takahashi's matches
  int k; // Number of days that have passed
  int wins = 0; // Number of wins Takahashi has

  // Read input
  scanf("%s", S);
  k = strlen(S);

  // Count the number of wins
  for (int i = 0; i < k; i++) {
    if (S[i] == 'o') {
      wins++;
    }
  }

  // Check if Takahashi can participate in the next tournament
  if (wins + (15 - k) >= 8) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }

  return 0;
}