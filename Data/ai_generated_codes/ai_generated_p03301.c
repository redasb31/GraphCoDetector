#include <stdio.h>

int main() {
  // N: Number of boxes
  int N;
  // a: Array storing the number of manju in each box
  int a[300000];
  // Sugim's manju count
  int sugim_manju = 0;
  // Sigma's manju count
  int sigma_manju = 0;
  // Last chosen box index (for Sugim's first move)
  int last_chosen = -1;

  // Input the number of boxes
  scanf("%d", &N);

  // Input the number of manju in each box
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  // Game loop
  for (int i = 0; i < N; i++) {
    // Sugim's turn
    if (i % 2 == 0) {
      // Find a valid box for Sugim
      if (last_chosen == -1) {
        // Sugim's first move: choose any box
        for (int j = 0; j < N; j++) {
          if (a[j] != 0) {
            last_chosen = j;
            sugim_manju += a[j];
            a[j] = 0;
            break;
          }
        }
      } else {
        // Sugim's subsequent moves: choose a box adjacent to the last chosen
        if (last_chosen > 0 && a[last_chosen - 1] != 0) {
          last_chosen--;
          sugim_manju += a[last_chosen];
          a[last_chosen] = 0;
        } else if (last_chosen < N - 1 && a[last_chosen + 1] != 0) {
          last_chosen++;
          sugim_manju += a[last_chosen];
          a[last_chosen] = 0;
        }
      }
    } else {
      // Sigma's turn
      // Find a valid box for Sigma (same logic as Sugim)
      if (last_chosen > 0 && a[last_chosen - 1] != 0) {
        last_chosen--;
        sigma_manju += a[last_chosen];
        a[last_chosen] = 0;
      } else if (last_chosen < N - 1 && a[last_chosen + 1] != 0) {
        last_chosen++;
        sigma_manju += a[last_chosen];
        a[last_chosen] = 0;
      }
    }
  }

  // Output the number of manju for each player
  printf("%d %d\n", sugim_manju, sigma_manju);

  return 0;
}