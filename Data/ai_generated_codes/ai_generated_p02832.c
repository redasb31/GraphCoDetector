#include <stdio.h>

int main() {
  int N; // Number of bricks
  scanf("%d", &N);

  int bricks[N]; // Array to store the integers on the bricks
  for (int i = 0; i < N; i++) {
    scanf("%d", &bricks[i]);
  }

  // Check if the sequence is already correct
  int broken = 0;
  for (int i = 0; i < N; i++) {
    if (bricks[i] != i + 1) {
      broken++;
    }
  }

  // If the sequence is already correct, we need to break 0 bricks
  if (broken == 0) {
    printf("0\n");
    return 0;
  }

  // Check if the sequence can be made correct by breaking bricks
  int missing = 0; // Counts the number of missing bricks
  for (int i = 0; i < N; i++) {
    if (bricks[i] != i + 1) {
      missing++;
    }
  }

  // If the number of missing bricks is equal to the number of bricks to be broken,
  // then the sequence can be made correct
  if (missing == broken) {
    printf("%d\n", broken);
    return 0;
  }

  // If the sequence cannot be made correct, print -1
  printf("-1\n");
  return 0;
}