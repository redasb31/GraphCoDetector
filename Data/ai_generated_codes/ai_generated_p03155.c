#include <stdio.h>

int main() {
  // N: size of the bulletin board (N x N)
  // H: height of the notice
  // W: width of the notice
  int N, H, W;

  // Read input from the user
  scanf("%d", &N);
  scanf("%d", &H);
  scanf("%d", &W);

  // Calculate the number of possible placements
  // The notice can be placed in (N - H + 1) different positions in each row
  // and (N - W + 1) different positions in each column
  int placements = (N - H + 1) * (N - W + 1);

  // Print the result
  printf("%d\n", placements);

  return 0;
}