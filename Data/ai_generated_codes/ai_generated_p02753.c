#include <stdio.h>
#include <string.h>

int main() {
  // Declare a string variable to store the input string.
  char S[4];

  // Get the input string from the user.
  scanf("%s", S);

  // Check if there are any pairs of stations operated by different companies.
  // If there are, print "Yes"; otherwise, print "No".
  if ((S[0] == 'A' && S[1] == 'B') || (S[0] == 'A' && S[2] == 'B') || (S[1] == 'A' && S[0] == 'B') || (S[1] == 'A' && S[2] == 'B') || (S[2] == 'A' && S[0] == 'B') || (S[2] == 'A' && S[1] == 'B')) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}