#include <stdio.h>
#include <string.h>

int main() {
  // N: Number of people
  int N;
  // s: String representing hat colors (R for red, B for blue)
  char s[101];

  // Read input
  scanf("%d\n", &N);
  scanf("%s", s);

  // Count the number of red hats
  int red_count = 0;
  for (int i = 0; i < N; i++) {
    if (s[i] == 'R') {
      red_count++;
    }
  }

  // Determine if there are more red hats than blue hats
  if (red_count > N / 2) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}