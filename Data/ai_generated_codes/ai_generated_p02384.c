#include <stdio.h>

int main() {
  // Array to store the integers assigned to the faces of the dice
  int faces[6];

  // Read the integers assigned to the faces
  for (int i = 0; i < 6; i++) {
    scanf("%d", &faces[i]);
  }

  // Read the number of questions
  int q;
  scanf("%d", &q);

  // Process each question
  for (int i = 0; i < q; i++) {
    // Read the top and front face integers
    int top, front;
    scanf("%d %d", &top, &front);

    // Find the indices of the top and front faces in the 'faces' array
    int top_index, front_index;
    for (int j = 0; j < 6; j++) {
      if (faces[j] == top) {
        top_index = j;
      }
      if (faces[j] == front) {
        front_index = j;
      }
    }

    // Calculate the index of the right side face based on the top and front face indices
    int right_index = (top_index + front_index) % 6;

    // Print the integer on the right side face
    printf("%d\n", faces[right_index]);
  }

  return 0;
}