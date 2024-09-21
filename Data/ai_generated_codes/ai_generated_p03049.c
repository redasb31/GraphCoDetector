#include <stdio.h>
#include <string.h>

int main() {
  int N;
  scanf("%d", &N);

  // Store the strings in an array of strings
  char strings[10000][11]; 
  for (int i = 0; i < N; i++) {
    scanf("%s", strings[i]); 
  }

  // Count the number of 'A' and 'B' characters in each string
  int countA[10000] = {0}; 
  int countB[10000] = {0}; 
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < strlen(strings[i]); j++) {
      if (strings[i][j] == 'A') {
        countA[i]++;
      } else if (strings[i][j] == 'B') {
        countB[i]++;
      }
    }
  }

  // Calculate the maximum number of "AB" occurrences
  int maxAB = 0;
  for (int i = 0; i < N; i++) {
    // Count the potential 'AB' occurrences in the current string
    int potentialAB = countA[i] * countB[i]; 

    // Adjust for the case where 'B' might come before 'A' in the string
    if (strings[i][0] == 'B' && strings[i][strlen(strings[i]) - 1] == 'A') {
      potentialAB--;
    } 

    maxAB += potentialAB; 
  }

  // Print the maximum number of "AB" occurrences
  printf("%d\n", maxAB);

  return 0;
}