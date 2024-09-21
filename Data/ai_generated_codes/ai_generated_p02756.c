#include <stdio.h>
#include <string.h>

int main() {
  char S[100001]; // String S
  int Q; // Number of operations

  // Input String S
  scanf("%s", S);

  // Input number of operations
  scanf("%d", &Q);

  // Iterate through each operation
  for (int i = 0; i < Q; i++) {
    int T; // Type of operation
    scanf("%d", &T);

    // If operation type is 1 (reverse)
    if (T == 1) {
      // Reverse string S using strrev()
      strrev(S);
    } else if (T == 2) { // If operation type is 2 (add character)
      int F; // Position to add character
      char C; // Character to add
      scanf("%d %c", &F, &C);

      // If adding character at the beginning (F=1)
      if (F == 1) {
        // Shift existing characters one position to the right
        for (int j = strlen(S); j >= 0; j--) {
          S[j + 1] = S[j];
        }
        // Add the new character at the beginning
        S[0] = C;
      } else if (F == 2) { // If adding character at the end (F=2)
        // Add the new character at the end of the string
        S[strlen(S)] = C;
        S[strlen(S) + 1] = '\0'; // Add null terminator
      }
    }
  }

  // Print the final string S
  printf("%s\n", S);

  return 0;
}