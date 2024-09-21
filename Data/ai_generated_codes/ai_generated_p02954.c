#include <stdio.h>
#include <string.h>

int main() {
  // Get the string input
  char S[100001];
  scanf("%s", S);

  // Calculate the length of the string
  int N = strlen(S);

  // Create an array to store the number of children on each square
  int children[N];
  memset(children, 0, sizeof(children));

  // Initialize the children array with the initial positions
  children[0] = 1;
  for (int i = 1; i < N; i++) {
    // If the character is R, move the child to the right
    if (S[i] == 'R') {
      children[i + 1] += 1;
      children[i] -= 1;
    }
    // If the character is L, move the child to the left
    else {
      children[i - 1] += 1;
      children[i] -= 1;
    }
  }

  // Print the final number of children on each square
  for (int i = 0; i < N; i++) {
    printf("%d ", children[i]);
  }

  return 0;
}