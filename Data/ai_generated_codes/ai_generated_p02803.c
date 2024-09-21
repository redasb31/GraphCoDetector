#include <stdio.h>
#include <stdlib.h>

#define MAX_H 20
#define MAX_W 20

int main() {
  int H, W;
  char maze[MAX_H][MAX_W];
  // Get the dimensions of the maze
  scanf("%d %d", &H, &W);
  // Read the maze input
  for (int i = 0; i < H; i++) {
    scanf("%s", maze[i]);
  }

  // Find the maximum distance between two road squares
  int max_distance = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (maze[i][j] == '.') {
        // Calculate the Manhattan distance to each other road square
        for (int k = 0; k < H; k++) {
          for (int l = 0; l < W; l++) {
            if (maze[k][l] == '.' && (i != k || j != l)) {
              int distance = abs(i - k) + abs(j - l);
              // Update the maximum distance
              max_distance = (distance > max_distance) ? distance : max_distance;
            }
          }
        }
      }
    }
  }
  // Print the maximum distance (number of moves)
  printf("%d\n", max_distance);
  return 0;
}