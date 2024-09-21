#include <stdio.h>
#include <limits.h>

#define MAX_N 200000

int main() {
  int N, X;
  int x[MAX_N];

  // Read input
  scanf("%d %d", &N, &X);
  for (int i = 0; i < N; i++) {
    scanf("%d", &x[i]);
  }

  // Calculate the minimum energy
  long long energy = 0;
  int current_position = 0;
  int trash_count = 0;

  for (int i = 0; i < N; i++) {
    // Travel to the next piece of trash
    energy += (trash_count + 1) * (trash_count + 1) * (x[i] - current_position); 
    current_position = x[i];

    // Pick up the trash
    energy += X;
    trash_count++;

    // Travel back to the bin if there are trash to be deposited
    if (trash_count > 0) {
      energy += (trash_count + 1) * (trash_count + 1) * current_position;
      current_position = 0;

      // Deposit the trash
      energy += X;
      trash_count = 0;
    }
  }

  // If there are remaining trash to be deposited
  if (trash_count > 0) {
    energy += (trash_count + 1) * (trash_count + 1) * current_position;
    energy += X;
  }

  // Print the answer
  printf("%lld\n", energy);

  return 0;
}