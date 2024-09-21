#include <stdio.h>
#include <string.h>

int main() {
  // Get the number of people
  int N;
  scanf("%d", &N);

  // Get the directions of the people
  char S[300001];
  scanf("%s", S);

  // Initialize the minimum number of changes
  int min_changes = N;

  // Loop through each person as a potential leader
  for (int i = 0; i < N; i++) {
    // Count the number of changes needed if the current person is the leader
    int changes = 0;
    for (int j = 0; j < N; j++) {
      // If the current person is facing the opposite direction from the leader,
      // they need to change their direction
      if (S[j] != S[i]) {
        changes++;
      }
    }

    // Update the minimum number of changes
    min_changes = (changes < min_changes) ? changes : min_changes;
  }

  // Print the minimum number of changes
  printf("%d\n", min_changes);

  return 0;
}