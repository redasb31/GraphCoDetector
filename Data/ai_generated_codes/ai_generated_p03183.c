#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000
#define MAX_W 10000
#define MAX_S 10000
#define MAX_V 1000000000

typedef struct {
  int w; // weight
  int s; // solidness
  int v; // value
} Block;

// Function to compare blocks based on their weight (for sorting)
int compare_blocks(const void *a, const void *b) {
  Block *block_a = (Block *)a;
  Block *block_b = (Block *)b;
  return block_a->w - block_b->w;
}

// Function to calculate the maximum value of a tower
int max_tower_value(Block blocks[], int n) {
  // Sort the blocks by weight in ascending order
  qsort(blocks, n, sizeof(Block), compare_blocks);

  // Create a DP table to store the maximum value of a tower ending at each block
  int dp[MAX_N + 1] = {0};

  // Iterate through each block
  for (int i = 1; i <= n; i++) {
    // Initialize the maximum value of a tower ending at block i to its own value
    dp[i] = blocks[i - 1].v;

    // Iterate through previous blocks to see if they can be stacked above block i
    for (int j = i - 1; j >= 1; j--) {
      // If the total weight of blocks above block i (from block j to block i - 1) 
      // does not exceed the solidness of block j, then we can stack them
      if (blocks[i - 1].w + (blocks[j - 1].w - blocks[i - 1].w) <= blocks[j - 1].s) {
        // Update the maximum value of a tower ending at block i
        dp[i] = (dp[i] > dp[j] + blocks[i - 1].v) ? dp[i] : (dp[j] + blocks[i - 1].v);
      }
    }
  }

  // The maximum value of the tower is the maximum value in the DP table
  return dp[n];
}

int main() {
  int n;
  scanf("%d", &n);

  // Array to store the blocks
  Block blocks[MAX_N];

  // Read the block information
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &blocks[i].w, &blocks[i].s, &blocks[i].v);
  }

  // Calculate and print the maximum tower value
  printf("%d\n", max_tower_value(blocks, n));

  return 0;
}