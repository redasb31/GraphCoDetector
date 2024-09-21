#include <stdio.h>
#include <string.h>

int main() {
  // N: Number of songs
  int N;
  scanf("%d", &N);

  // s: Song titles (strings)
  char s[50][101];

  // t: Song durations (integers)
  int t[50];

  // X: Song title at which Niwango fell asleep
  char X[101];

  // Read song information
  for (int i = 0; i < N; i++) {
    scanf("%s %d", s[i], &t[i]);
  }

  // Read the song Niwango fell asleep at
  scanf("%s", X);

  // Find the index of the song Niwango fell asleep at
  int asleepIndex = -1;
  for (int i = 0; i < N; i++) {
    if (strcmp(s[i], X) == 0) {
      asleepIndex = i;
      break;
    }
  }

  // Calculate the total duration of songs played while Niwango was asleep
  int totalDuration = 0;
  for (int i = asleepIndex + 1; i < N; i++) {
    totalDuration += t[i];
  }

  // Print the answer
  printf("%d\n", totalDuration);

  return 0;
}