#include <stdio.h>
#include <string.h>

int main() {
  char s[8001]; // String to store the instructions
  int x, y; // Target coordinates
  int direction = 0; // 0: right, 1: up, 2: left, 3: down
  int cur_x = 0, cur_y = 0; // Current coordinates

  // Input the instruction sequence and target coordinates
  scanf("%s", s);
  scanf("%d %d", &x, &y);

  // Process the instructions
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] == 'F') {
      // Move in the current direction
      if (direction == 0) {
        cur_x++;
      } else if (direction == 1) {
        cur_y++;
      } else if (direction == 2) {
        cur_x--;
      } else {
        cur_y--;
      }
    } else if (s[i] == 'T') {
      // Turn 90 degrees
      direction = (direction + 1) % 4;
    }
  }

  // Check if the target coordinates are achievable
  if (cur_x == x && cur_y == y) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}