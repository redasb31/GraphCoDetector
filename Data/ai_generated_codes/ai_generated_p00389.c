#include <stdio.h>

int main() {
  // N: Number of blocks
  // K: Strength of each block (maximum weight it can withstand)
  int N, K;
  scanf("%d %d", &N, &K);

  // stages: Number of stages in the tower
  int stages = 0;

  // blocks: Number of blocks used in the tower
  int blocks = 0;

  // current_weight: Weight on the current stage
  int current_weight = 0;

  // Iterate while we have blocks left
  while (blocks < N) {
    // Calculate the weight on the current stage
    current_weight = (N - blocks) / (stages + 1);

    // If the weight is within the block's strength, add a stage
    if (current_weight <= K) {
      stages++;
      blocks += stages + 1; // Increment blocks used for the new stage
    } else {
      // If weight exceeds strength, we can't add a new stage
      break;
    }
  }

  printf("%d\n", stages);

  return 0;
}