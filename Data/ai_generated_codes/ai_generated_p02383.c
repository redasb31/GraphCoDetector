#include <stdio.h>
#include <string.h>

int main() {
  // Declare an array to store the values assigned to each face of the dice.
  int face_values[6];

  // Read the values assigned to each face from the input.
  for (int i = 0; i < 6; i++) {
    scanf("%d", &face_values[i]);
  }

  // Read the sequence of commands from the input.
  char commands[101];
  scanf("%s", commands);

  // Initialize the current top face of the dice.
  int top_face = 1; // Initially, face 1 is at the top.

  // Simulate the rolling of the dice based on the given commands.
  for (int i = 0; i < strlen(commands); i++) {
    switch (commands[i]) {
      // Roll the dice to the East (E) direction.
      case 'E':
        if (top_face == 1) {
          top_face = 4;
        } else if (top_face == 2) {
          top_face = 1;
        } else if (top_face == 3) {
          top_face = 6;
        } else if (top_face == 4) {
          top_face = 3;
        } else if (top_face == 5) {
          top_face = 2;
        } else if (top_face == 6) {
          top_face = 5;
        }
        break;

      // Roll the dice to the North (N) direction.
      case 'N':
        if (top_face == 1) {
          top_face = 2;
        } else if (top_face == 2) {
          top_face = 6;
        } else if (top_face == 3) {
          top_face = 1;
        } else if (top_face == 4) {
          top_face = 5;
        } else if (top_face == 5) {
          top_face = 4;
        } else if (top_face == 6) {
          top_face = 3;
        }
        break;

      // Roll the dice to the South (S) direction.
      case 'S':
        if (top_face == 1) {
          top_face = 3;
        } else if (top_face == 2) {
          top_face = 5;
        } else if (top_face == 3) {
          top_face = 1;
        } else if (top_face == 4) {
          top_face = 2;
        } else if (top_face == 5) {
          top_face = 6;
        } else if (top_face == 6) {
          top_face = 4;
        }
        break;

      // Roll the dice to the West (W) direction.
      case 'W':
        if (top_face == 1) {
          top_face = 5;
        } else if (top_face == 2) {
          top_face = 4;
        } else if (top_face == 3) {
          top_face = 2;
        } else if (top_face == 4) {
          top_face = 6;
        } else if (top_face == 5) {
          top_face = 1;
        } else if (top_face == 6) {
          top_face = 3;
        }
        break;
    }
  }

  // Print the integer on the top face after the simulation.
  printf("%d\n", face_values[top_face - 1]);

  return 0;
}