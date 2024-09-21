#include <stdio.h>
#include <string.h>

int main() {
  char S[100005]; // String to store the colors of the cubes
  int N; // Number of cubes

  // Read the string S from standard input
  scanf("%s", S); 
  N = strlen(S); // Calculate the length of the string (number of cubes)

  int removed = 0; // Initialize the count of removed cubes
  int i = 0; // Index to traverse the string

  // Iterate through the string, removing adjacent red and blue cubes
  while (i < N) {
    // If the current cube is red (0)
    if (S[i] == '0') {
      // If the next cube is blue (1)
      if (i + 1 < N && S[i + 1] == '1') {
        removed += 2; // Increment the count of removed cubes by 2
        i += 2; // Move the index to the next pair of cubes
      } else {
        // If the next cube is not blue, move the index to the next cube
        i++; 
      }
    } else {
      // If the current cube is blue, move the index to the next cube
      i++;
    }
  }

  // Print the maximum number of cubes that can be removed
  printf("%d\n", removed); 

  return 0;
}