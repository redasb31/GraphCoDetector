#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Read the number of balls of each color
  int N;
  scanf("%d", &N);

  // Create an array to store the colors of the balls
  char* colors = malloc(sizeof(char) * (2 * N + 1));
  if (colors == NULL) {
    fprintf(stderr, "Error: Could not allocate memory for colors array.\n");
    exit(1);
  }

  // Initialize the colors array with unknown colors
  for (int i = 0; i < 2 * N; i++) {
    colors[i] = '?';
  }

  // Set the last element to a null terminator for string operations
  colors[2 * N] = '\0';

  // Ask questions and deduce the colors of the balls
  int questionCount = 0;
  while (questionCount < 210) {
    // Choose N balls randomly
    int* chosenBalls = malloc(sizeof(int) * N);
    if (chosenBalls == NULL) {
      fprintf(stderr, "Error: Could not allocate memory for chosenBalls array.\n");
      free(colors);
      exit(1);
    }
    for (int i = 0; i < N; i++) {
      chosenBalls[i] = (rand() % (2 * N)) + 1;
      // Ensure no duplicate balls are chosen
      for (int j = 0; j < i; j++) {
        if (chosenBalls[i] == chosenBalls[j]) {
          i--;
          break;
        }
      }
    }

    // Ask the question
    printf("? ");
    for (int i = 0; i < N; i++) {
      printf("%d ", chosenBalls[i]);
    }
    printf("\n");
    fflush(stdout);

    // Read the response
    char response[10];
    scanf("%s", response);

    // Check for invalid response
    if (strcmp(response, "-1") == 0) {
      free(colors);
      free(chosenBalls);
      return 1;
    }

    // Deduce the colors of the balls based on the response
    if (strcmp(response, "Red") == 0) {
      for (int i = 0; i < N; i++) {
        int ballIndex = chosenBalls[i] - 1;
        if (colors[ballIndex] == '?') {
          colors[ballIndex] = 'R';
        } else if (colors[ballIndex] == 'B') {
          colors[ballIndex] = '?'; // Inconclusive
        }
      }
    } else if (strcmp(response, "Blue") == 0) {
      for (int i = 0; i < N; i++) {
        int ballIndex = chosenBalls[i] - 1;
        if (colors[ballIndex] == '?') {
          colors[ballIndex] = 'B';
        } else if (colors[ballIndex] == 'R') {
          colors[ballIndex] = '?'; // Inconclusive
        }
      }
    }

    // Check if all colors are known
    int allColorsKnown = 1;
    for (int i = 0; i < 2 * N; i++) {
      if (colors[i] == '?') {
        allColorsKnown = 0;
        break;
      }
    }

    // If all colors are known, print the answer
    if (allColorsKnown) {
      printf("! %s\n", colors);
      fflush(stdout);
      free(colors);
      free(chosenBalls);
      return 0;
    }

    free(chosenBalls);
    questionCount++;
  }

  // If all colors are not known after 210 questions, the program fails
  free(colors);
  return 1;
}