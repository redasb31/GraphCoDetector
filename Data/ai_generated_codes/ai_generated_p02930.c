#include <stdio.h>

int main() {
  int N;

  // Read the number of rooms
  scanf("%d", &N);

  // Initialize the levels to 1
  for (int i = 1; i < N; i++) {
    for (int j = i + 1; j <= N; j++) {
      printf("1 ");
    }
    printf("\n");
  }

  return 0;
}