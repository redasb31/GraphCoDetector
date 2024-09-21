#include <stdio.h>
#include <string.h>

// Function to rotate a layout string by one position
void rotate(char *layout, int len) {
  char temp = layout[len - 1];
  for (int i = len - 1; i > 0; i--) {
    layout[i] = layout[i - 1];
  }
  layout[0] = temp;
}

// Function to check if two layouts are equivalent
int isEquivalent(char *layout1, char *layout2) {
  int len1 = strlen(layout1);
  int len2 = strlen(layout2);

  // If lengths are different, they are not equivalent
  if (len1 != len2) {
    return 0;
  }

  // Check for equivalence by rotating layout1 and comparing with layout2
  for (int i = 0; i < len1; i++) {
    if (strcmp(layout1, layout2) == 0) {
      return 1;
    }
    rotate(layout1, len1);
  }
  return 0;
}

int main() {
  int numPairs;
  scanf("%d", &numPairs);

  char layout1[101];
  char layout2[101];

  for (int i = 0; i < numPairs; i++) {
    scanf("%s", layout1);
    scanf("%s", layout2);
    scanf("%*s"); // Read the hyphen

    if (isEquivalent(layout1, layout2)) {
      printf("true\n");
    } else {
      printf("false\n");
    }
  }

  return 0;
}