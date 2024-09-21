#include <stdio.h>

int main() {
  // N: length of the permutation
  int N;
  // p: the permutation array
  int p[50];

  // Read input
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &p[i]);
  }

  // Check if the permutation is already sorted
  int is_sorted = 1;
  for (int i = 1; i < N; i++) {
    if (p[i - 1] > p[i]) {
      is_sorted = 0;
      break;
    }
  }

  // If the permutation is already sorted, print YES
  if (is_sorted) {
    printf("YES\n");
    return 0;
  }

  // Check if there is only one inversion
  int inversion_count = 0;
  for (int i = 1; i < N; i++) {
    if (p[i - 1] > p[i]) {
      inversion_count++;
    }
  }

  // If there is only one inversion, print YES
  if (inversion_count == 1) {
    printf("YES\n");
    return 0;
  }

  // Otherwise, print NO
  printf("NO\n");
  return 0;
}