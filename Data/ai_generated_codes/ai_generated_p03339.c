#include <stdio.h>
#include <string.h>

int main() {
  int N; // Number of people
  char S[300001]; // String representing the direction of each person

  // Input the number of people
  scanf("%d", &N);

  // Input the direction string
  scanf("%s", S);

  // Calculate the minimum number of changes required
  int min_changes = N / 2; // Initial guess: half the people have to change
  int changes_east = 0; // Number of changes required if the leader faces east
  int changes_west = 0; // Number of changes required if the leader faces west

  // Count the number of 'E' and 'W' characters
  for (int i = 0; i < N; i++) {
    if (S[i] == 'E') {
      changes_east++;
    } else {
      changes_west++;
    }
  }

  // Update min_changes based on the counts
  min_changes = (changes_east < changes_west) ? changes_east : changes_west;

  // Print the minimum number of changes
  printf("%d\n", min_changes);

  return 0;
}