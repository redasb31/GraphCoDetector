#include <stdio.h>
#include <string.h>

int main() {
  char S[11]; // Maximum string length is 10

  // Input the string
  scanf("%s", S);

  // Check the first character
  if (S[0] != 'A') {
    printf("WA\n");
    return 0; 
  }

  // Check for the number of C occurrences
  int countC = 0;
  for (int i = 2; i < strlen(S) - 1; i++) {
    if (S[i] == 'C') {
      countC++;
    }
  }

  if (countC != 1) {
    printf("WA\n");
    return 0;
  }

  // Check if the remaining letters are lowercase
  for (int i = 1; i < strlen(S); i++) {
    if (S[i] != 'C' && (S[i] < 'a' || S[i] > 'z')) {
      printf("WA\n");
      return 0;
    }
  }

  // If all conditions are met, print "AC"
  printf("AC\n");

  return 0;
}