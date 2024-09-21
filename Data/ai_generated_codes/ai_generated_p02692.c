#include <stdio.h>
#include <string.h>

int main() {
  int N, A, B, C;
  scanf("%d %d %d %d", &N, &A, &B, &C);

  char choices[N][3]; // Array to store choices

  // Read the choices
  for (int i = 0; i < N; i++) {
    scanf("%s", choices[i]);
  }

  // Check if it's possible to make the choices
  int possible = 1;
  for (int i = 0; i < N; i++) {
    if (strcmp(choices[i], "AB") == 0) {
      if (A == 0 && B == 0) { // Both A and B are 0, impossible
        possible = 0;
        break;
      }
    } else if (strcmp(choices[i], "AC") == 0) {
      if (A == 0 && C == 0) { // Both A and C are 0, impossible
        possible = 0;
        break;
      }
    } else if (strcmp(choices[i], "BC") == 0) {
      if (B == 0 && C == 0) { // Both B and C are 0, impossible
        possible = 0;
        break;
      }
    }
  }

  // Print the result
  if (possible) {
    printf("Yes\n");

    // Print the chosen variable for each choice
    for (int i = 0; i < N; i++) {
      if (strcmp(choices[i], "AB") == 0) {
        if (A > B) {
          printf("B\n");
          B++;
          A--;
        } else {
          printf("A\n");
          A++;
          B--;
        }
      } else if (strcmp(choices[i], "AC") == 0) {
        if (A > C) {
          printf("C\n");
          C++;
          A--;
        } else {
          printf("A\n");
          A++;
          C--;
        }
      } else if (strcmp(choices[i], "BC") == 0) {
        if (B > C) {
          printf("C\n");
          C++;
          B--;
        } else {
          printf("B\n");
          B++;
          C--;
        }
      }
    }
  } else {
    printf("No\n");
  }

  return 0;
}