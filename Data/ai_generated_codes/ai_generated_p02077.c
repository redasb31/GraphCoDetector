#include <stdio.h>
#include <string.h>

#define MAX_SIZE 500

int main() {
  // Input variables
  int N, M, K, L;
  char bomb_pattern[MAX_SIZE][MAX_SIZE];
  char movement_pattern[MAX_SIZE];

  // Input reading
  scanf("%d %d %d %d", &N, &M, &K, &L);

  // Read the bombing pattern
  for (int i = 0; i < N; i++) {
    scanf("%s", bomb_pattern[i]);
  }

  // Read the movement pattern
  scanf("%s", movement_pattern);

  // Initialize damage grid
  int damage_grid[MAX_SIZE][MAX_SIZE] = {0};

  // Bomber position
  int br = 1, bc = 1;

  // Iterate through the movement pattern
  for (int i = 0; i < L; i++) {
    // Apply movement
    switch (movement_pattern[i]) {
      case 'U':
        br--;
        break;
      case 'D':
        br++;
        break;
      case 'L':
        bc--;
        break;
      case 'R':
        bc++;
        break;
    }

    // Update damage grid based on bombing pattern
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        if (bomb_pattern[j][k] == 'X') {
          damage_grid[br + j][bc + k]++;
        }
      }
    }
  }

  // Count damaged cells
  int damaged_cells = 0;
  for (int i = 1; i <= M; i++) {
    for (int j = 1; j <= M; j++) {
      if (damage_grid[i][j] >= K) {
        damaged_cells++;
      }
    }
  }

  // Output the result
  printf("%d\n", damaged_cells);

  return 0;
}