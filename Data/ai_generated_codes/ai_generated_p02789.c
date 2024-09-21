#include <stdio.h>

int main() {
  // N: total number of test cases
  // M: number of passed test cases
  int N, M;

  // Read the input
  scanf("%d %d", &N, &M);

  // Check if all test cases are passed
  if (M == N) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}