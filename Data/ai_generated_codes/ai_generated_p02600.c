#include <stdio.h>

int main() {
  // Declare variable to store M-kun's highest rating.
  int X;

  // Read the highest rating from the input.
  scanf("%d", &X);

  // Determine the kyu based on the rating.
  if (X >= 400 && X <= 599) {
    printf("8\n"); // 8-kyu
  } else if (X >= 600 && X <= 799) {
    printf("7\n"); // 7-kyu
  } else if (X >= 800 && X <= 999) {
    printf("6\n"); // 6-kyu
  } else if (X >= 1000 && X <= 1199) {
    printf("5\n"); // 5-kyu
  } else if (X >= 1200 && X <= 1399) {
    printf("4\n"); // 4-kyu
  } else if (X >= 1400 && X <= 1599) {
    printf("3\n"); // 3-kyu
  } else if (X >= 1600 && X <= 1799) {
    printf("2\n"); // 2-kyu
  } else if (X >= 1800 && X <= 1999) {
    printf("1\n"); // 1-kyu
  }

  return 0;
}