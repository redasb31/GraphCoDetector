#include <stdio.h>
#include <string.h>

int main() {
  char S[1001];
  char T[1001];

  // Get the input strings
  scanf("%s", S);
  scanf("%s", T);

  // Check if the lengths of S and T are the same
  if (strlen(S) != strlen(T)) {
    printf("No\n");
    return 0;
  }

  // Initialize variables to track the indices of S and T
  int s_idx = 0;
  int t_idx = 0;

  // Iterate over the characters of S
  for (int i = 0; i < strlen(S); i++) {
    // If the current character of S matches the current character of T
    if (S[i] == T[t_idx]) {
      // Increment the index of T
      t_idx++;
    } else {
      // If the current character of S does not match the current character of T
      // and the index of S is less than the length of S
      if (s_idx < strlen(S)) {
        // Increment the index of S
        s_idx++;
        // If the current character of S matches the current character of T
        if (S[i] == T[t_idx]) {
          // Increment the index of T
          t_idx++;
        } else {
          // If the current character of S still does not match the current character of T
          // then it is not possible to make S by combining S and T
          printf("No\n");
          return 0;
        }
      } else {
        // If the index of S is greater than or equal to the length of S
        // then it is not possible to make S by combining S and T
        printf("No\n");
        return 0;
      }
    }
  }

  // If all characters of S have been matched with characters from S and T
  // then it is possible to make S by combining S and T
  printf("Yes\n");

  return 0;
}