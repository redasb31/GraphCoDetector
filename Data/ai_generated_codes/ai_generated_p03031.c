#include <stdio.h>

// Function to calculate the number of combinations of switches that light all bulbs
int count_combinations(int N, int M, int k[], int s[][10], int p[]) {
  int combinations = 0;  // Initialize the count of combinations
  int state[10];          // Array to store the state of each switch (0 for off, 1 for on)

  // Iterate through all possible combinations of switch states
  for (int i = 0; i < (1 << N); i++) {
    // Set the state of each switch based on the current combination
    for (int j = 0; j < N; j++) {
      state[j] = (i >> j) & 1; // Extract the j-th bit of i
    }

    // Check if all bulbs are lighted
    int all_lighted = 1; // Assume all bulbs are lighted initially
    for (int j = 0; j < M; j++) {
      int on_count = 0; // Count the number of "on" switches connected to bulb j
      for (int l = 0; l < k[j]; l++) {
        if (state[s[j][l] - 1] == 1) { // Check if the switch connected to bulb j is "on"
          on_count++;
        }
      }

      // Check if the bulb is lighted according to its condition
      if ((on_count % 2) != p[j]) {
        all_lighted = 0; // If any bulb is not lighted, set all_lighted to 0
        break;
      }
    }

    // If all bulbs are lighted, increment the count of combinations
    if (all_lighted) {
      combinations++;
    }
  }

  return combinations;
}

int main() {
  int N, M;
  scanf("%d %d", &N, &M);

  int k[10];
  int s[10][10];
  int p[10];

  // Read input for each bulb
  for (int i = 0; i < M; i++) {
    scanf("%d", &k[i]);
    for (int j = 0; j < k[i]; j++) {
      scanf("%d", &s[i][j]);
    }
    scanf("%d", &p[i]);
  }

  // Calculate and print the number of combinations
  printf("%d\n", count_combinations(N, M, k, s, p));

  return 0;
}