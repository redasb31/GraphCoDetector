#include <stdio.h>
#include <string.h>

int main() {
  // Read the input
  int N, K;
  scanf("%d %d", &N, &K);
  char S[100001];
  scanf("%s", S);

  // Count initial happy people
  int happy = 0;
  for (int i = 1; i < N; i++) {
    if (S[i] == S[i - 1]) {
      happy++;
    }
  }

  // Iterate over all possible rotation lengths
  for (int len = 1; len <= N; len++) {
    // Calculate the number of operations required for this length
    int operations = (N - len) / 2;
    // If we can perform enough operations
    if (operations <= K) {
      // Calculate the number of happy people after the rotation
      int happy_with_rotation = 0;
      for (int i = 0; i < N - len; i++) {
        if (S[i] == S[i + len]) {
          happy_with_rotation++;
        }
      }
      // Update the maximum number of happy people
      happy = (happy_with_rotation > happy) ? happy_with_rotation : happy;
    }
  }

  // Print the result
  printf("%d\n", happy);

  return 0;
}