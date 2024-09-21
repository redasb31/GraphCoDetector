#include <stdio.h>
#include <string.h>

int main() {
  char s[8001];
  int x, y;
  scanf("%s", s);
  scanf("%d %d", &x, &y);

  // Initialize robot's position and direction
  int pos_x = 0, pos_y = 0;
  int dir = 0; // 0: East, 1: North, 2: West, 3: South

  // Process the instruction sequence
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] == 'F') {
      // Move forward based on current direction
      if (dir == 0) {
        pos_x++;
      } else if (dir == 1) {
        pos_y++;
      } else if (dir == 2) {
        pos_x--;
      } else if (dir == 3) {
        pos_y--;
      }
    } else if (s[i] == 'T') {
      // Turn 90 degrees clockwise
      dir = (dir + 1) % 4;
    }
  }

  // Check if the objective is achievable
  if (pos_x == x && pos_y == y) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}