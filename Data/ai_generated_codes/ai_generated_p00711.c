#include <stdio.h>

// Function to check if a tile is valid and within bounds
int isValid(int x, int y, int w, int h, char grid[20][20]) {
  return (x >= 0 && x < w && y >= 0 && y < h && grid[y][x] != '#');
}

// Function to perform a depth-first search (DFS)
int dfs(int x, int y, int w, int h, char grid[20][20], int visited[20][20]) {
  // Mark the current tile as visited
  visited[y][x] = 1;

  // Initialize count of reachable tiles to 1 (for the current tile)
  int count = 1;

  // Explore all four adjacent tiles
  int dx[] = {0, 0, 1, -1};
  int dy[] = {1, -1, 0, 0};
  for (int i = 0; i < 4; i++) {
    int newX = x + dx[i];
    int newY = y + dy[i];
    if (isValid(newX, newY, w, h, grid) && !visited[newY][newX]) {
      // Recursively explore unvisited adjacent tiles
      count += dfs(newX, newY, w, h, grid, visited);
    }
  }

  // Return the total count of reachable tiles
  return count;
}

int main() {
  int w, h;
  char grid[20][20];
  int visited[20][20]; // Array to keep track of visited tiles

  while (1) {
    // Read the dimensions of the room
    scanf("%d %d", &w, &h);
    if (w == 0 && h == 0) {
      break; // End of input
    }

    // Read the grid of tiles
    for (int i = 0; i < h; i++) {
      scanf("%s", grid[i]);
    }

    // Initialize visited array to 0 (not visited)
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        visited[i][j] = 0;
      }
    }

    // Find the starting position of the man
    int startX, startY;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (grid[i][j] == '@') {
          startX = j;
          startY = i;
        }
      }
    }

    // Perform DFS to count reachable tiles
    int count = dfs(startX, startY, w, h, grid, visited);

    // Print the count of reachable tiles
    printf("%d\n", count);
  }

  return 0;
}