#include <stdio.h>
#include <string.h>

#define MAX_N 100
#define MAX_M 100

char grid[MAX_N][MAX_M + 1];
char tile_config[MAX_N][MAX_M + 1];
int n, m;

// Function to check if a tile can be placed horizontally at (i, j)
int can_place_horizontal(int i, int j) {
  if (j + 1 >= m || grid[i][j] == '#' || grid[i][j + 1] == '#') {
    return 0;
  }
  return 1;
}

// Function to check if a tile can be placed vertically at (i, j)
int can_place_vertical(int i, int j) {
  if (i + 1 >= n || grid[i][j] == '#' || grid[i + 1][j] == '#') {
    return 0;
  }
  return 1;
}

// Function to place a tile horizontally at (i, j)
void place_horizontal(int i, int j) {
  tile_config[i][j] = '>';
  tile_config[i][j + 1] = '<';
}

// Function to place a tile vertically at (i, j)
void place_vertical(int i, int j) {
  tile_config[i][j] = 'v';
  tile_config[i + 1][j] = '^';
}

// Function to find the maximum number of tiles that can be placed
int max_tiles() {
  int max_tiles = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      // Try placing a tile horizontally
      if (can_place_horizontal(i, j)) {
        place_horizontal(i, j);
        max_tiles++;
        j++; // Skip the next cell as it's already covered
      }
      // Try placing a tile vertically
      else if (can_place_vertical(i, j)) {
        place_vertical(i, j);
        max_tiles++;
        i++; // Skip the next row as it's already covered
      }
    }
  }
  return max_tiles;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", grid[i]);
  }

  // Initialize the tile configuration to the original grid
  for (int i = 0; i < n; i++) {
    strcpy(tile_config[i], grid[i]);
  }

  int max_tiles_count = max_tiles();
  printf("%d\n", max_tiles_count);

  // Print the tile configuration
  for (int i = 0; i < n; i++) {
    printf("%s\n", tile_config[i]);
  }

  return 0;
}