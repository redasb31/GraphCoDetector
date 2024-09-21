#include <stdio.h>
#include <string.h>

#define MAX_N 200000

int main() {
  int N, Q;
  char s[MAX_N + 1];
  char t[MAX_N + 1];
  char d[MAX_N + 1];
  int count[26] = {0}; // Count the number of golems on each square

  scanf("%d %d\n", &N, &Q);
  scanf("%s\n", s); // read the string s

  // Initialize the count array
  for (int i = 0; i < N; i++) {
    count[s[i] - 'A']++; 
  }

  for (int i = 0; i < Q; i++) {
    scanf("%c %c\n", &t[i], &d[i]);
  }

  // Process each spell
  for (int i = 0; i < Q; i++) {
    int target = t[i] - 'A'; // Index of the target character in the count array

    // Move golems to the left
    if (d[i] == 'L') {
      if (target > 0) { // If not the leftmost square
        count[target - 1] += count[target]; // Add golems to the left square
        count[target] = 0; // Reset the count of golems on the current square
      } else {
        count[target] = 0; // Golems disappear on the leftmost square
      }
    } 
    // Move golems to the right
    else if (d[i] == 'R') {
      if (target < 25) { // If not the rightmost square
        count[target + 1] += count[target]; // Add golems to the right square
        count[target] = 0; // Reset the count of golems on the current square
      } else {
        count[target] = 0; // Golems disappear on the rightmost square
      }
    }
  }

  // Calculate the total number of golems remaining
  int total = 0;
  for (int i = 0; i < 26; i++) {
    total += count[i];
  }

  printf("%d\n", total);

  return 0;
}