/*
  This code solves the Shortest Common Non-Subsequence problem.
  Given two sequences of 0s and 1s, it finds the shortest sequence that is not a subsequence of either input sequence.
  It prioritizes lexicographically smaller sequences if there are multiple shortest sequences.
*/

#include <stdio.h>
#include <string.h>

int main() {
  char s1[4001], s2[4001];
  scanf("%s %s", s1, s2);
  int len1 = strlen(s1), len2 = strlen(s2);

  // Build the shortest common non-subsequence (scns)
  char scns[4001] = "";
  int scnsLen = 0;
  int i = 0, j = 0;

  // Iterate through both input sequences simultaneously
  while (i < len1 || j < len2) {
    // If both sequences have the same character, add it to the scns and move both pointers
    if (i < len1 && j < len2 && s1[i] == s2[j]) {
      scns[scnsLen++] = s1[i];
      i++;
      j++;
    }
    // If s1 has a different character, add the opposite character to the scns and move s1 pointer
    else if (i < len1) {
      scns[scnsLen++] = (s1[i] == '0') ? '1' : '0';
      i++;
    }
    // If s2 has a different character, add the opposite character to the scns and move s2 pointer
    else if (j < len2) {
      scns[scnsLen++] = (s2[j] == '0') ? '1' : '0';
      j++;
    }
  }

  // If the scns is empty, add the smallest possible sequence "01"
  if (scnsLen == 0) {
    scns[scnsLen++] = '0';
    scns[scnsLen++] = '1';
  }

  // Print the shortest common non-subsequence
  printf("%s\n", scns);

  return 0;
}