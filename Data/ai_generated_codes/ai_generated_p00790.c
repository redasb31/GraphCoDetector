#include <stdio.h>
#include <string.h>

int main() {
  int num_commands, i;
  char command[10];
  int top_face = 1; // Initial top face is 1
  int north_face = 2; // Initial north face is 2
  int west_face = 3; // Initial west face is 3

  // Loop through each game
  while (1) {
    scanf("%d", &num_commands);
    // End of input
    if (num_commands == 0) {
      break;
    }

    // Process commands for the current game
    for (i = 0; i < num_commands; i++) {
      scanf("%s", command);

      if (strcmp(command, "north") == 0) {
        // Rotate around north-bottom edge
        int temp = top_face;
        top_face = north_face;
        north_face = 7 - temp;
      } else if (strcmp(command, "east") == 0) {
        // Rotate around east-bottom edge
        int temp = top_face;
        top_face = west_face;
        west_face = 7 - temp;
      } else if (strcmp(command, "south") == 0) {
        // Rotate around south-bottom edge
        int temp = top_face;
        top_face = 7 - north_face;
        north_face = temp;
      } else if (strcmp(command, "west") == 0) {
        // Rotate around west-bottom edge
        int temp = top_face;
        top_face = 7 - west_face;
        west_face = temp;
      }
    }

    // Print the final top face
    printf("%d\n", top_face);
  }
  return 0;
}