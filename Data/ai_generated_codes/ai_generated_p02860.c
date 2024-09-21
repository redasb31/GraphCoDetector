#include <stdio.h>
#include <string.h>

int main() {
  int N;
  char S[101];

  // Read input
  scanf("%d\n", &N);
  scanf("%s", S);

  // Check if the string can be split into two equal halves
  if (N % 2 == 0) {
    // Find the midpoint of the string
    int mid = N / 2;

    // Compare the first and second halves of the string
    if (strncmp(S, S + mid, mid) == 0) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  } else {
    // If the length of the string is odd, it cannot be a concatenation of two equal strings
    printf("No\n");
  }

  return 0;
}