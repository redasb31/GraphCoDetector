#include <stdio.h>
#include <string.h>

int main() {
  // Declare a character array to store the input string
  char S[4];

  // Read the input string from standard input
  scanf("%s", S);

  // Check if the string contains all three characters 'a', 'b', and 'c'
  if (strchr(S, 'a') != NULL && strchr(S, 'b') != NULL && strchr(S, 'c') != NULL) {
    // If all three characters are present, print "Yes"
    printf("Yes\n");
  } else {
    // Otherwise, print "No"
    printf("No\n");
  }

  return 0;
}