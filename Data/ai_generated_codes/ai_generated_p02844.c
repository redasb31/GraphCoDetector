#include <stdio.h>
#include <string.h>

int main() {
  // N is the length of the lucky number S
  int N;
  // S is the lucky number as a string
  char S[30001];

  // Read the input
  scanf("%d\n", &N);
  scanf("%s", S);

  // Count the number of different PIN codes
  int count = 0;
  for (int i = 0; i <= N - 3; i++) {
    for (int j = i + 1; j <= N - 2; j++) {
      for (int k = j + 1; k <= N - 1; k++) {
        // Concatenate the 3 digits to form a PIN code
        char pin_code[4];
        pin_code[0] = S[i];
        pin_code[1] = S[j];
        pin_code[2] = S[k];
        pin_code[3] = '\0';

        // Increment the count if the PIN code is unique
        count++;
      }
    }
  }

  // Print the number of different PIN codes
  printf("%d\n", count);

  return 0;
}