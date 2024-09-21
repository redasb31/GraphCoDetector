#include <stdio.h>

int main() {
  int N, K;
  // Read the input values N and K from the user
  scanf("%d %d", &N, &K);

  // If K is greater than N/2, it is not possible to choose K distinct integers
  // that do not differ by 1.
  if (K > N / 2) {
    printf("NO\n");
  } else {
    // If K is less than or equal to N/2, it is always possible to choose K distinct
    // integers that do not differ by 1.
    printf("YES\n");
  }

  return 0;
}