#include <stdio.h>

int main() {
  // Declare variables for the four digits
  int N1, N2, N3, N4;

  // Read the four digits from standard input
  scanf("%d %d %d %d", &N1, &N2, &N3, &N4);

  // Check if the digits can be arranged to form "1974"
  if ((N1 == 1 && N2 == 9 && N3 == 7 && N4 == 4) ||
      (N1 == 1 && N2 == 7 && N3 == 9 && N4 == 4) ||
      (N1 == 9 && N2 == 1 && N3 == 7 && N4 == 4) ||
      (N1 == 9 && N2 == 7 && N3 == 1 && N4 == 4) ||
      (N1 == 7 && N2 == 1 && N3 == 9 && N4 == 4) ||
      (N1 == 7 && N2 == 9 && N3 == 1 && N4 == 4)) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }

  return 0;
}