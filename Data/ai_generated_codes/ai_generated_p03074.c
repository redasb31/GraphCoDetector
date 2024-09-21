#include <stdio.h>
#include <string.h>

int main() {
  // Read input
  int N, K;
  scanf("%d %d", &N, &K);
  char S[100001];
  scanf("%s", S);

  // Calculate the maximum number of consecutive people standing on hands
  int max_consecutive = 0;
  int current_consecutive = 0;
  for (int i = 0; i < N; i++) {
    // If the current person is standing on hands
    if (S[i] == '1') {
      // Increment the current consecutive count
      current_consecutive++;
      // Update the maximum consecutive count
      max_consecutive = (current_consecutive > max_consecutive) ? current_consecutive : max_consecutive;
    } else {
      // Reset the current consecutive count
      current_consecutive = 0;
    }
  }

  // Check if we can flip the entire string to maximize the consecutive count
  if (K > 0 && max_consecutive < N) {
    // If the number of flips is greater than zero and the maximum consecutive count is less than the total number of people,
    // we can flip the entire string to maximize the consecutive count.
    max_consecutive = N;
  }

  // Print the maximum consecutive count
  printf("%d\n", max_consecutive);

  return 0;
}