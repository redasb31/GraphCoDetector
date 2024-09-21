#include <stdio.h>

int main() {
  int N, Q; // Number of apple species and instructions
  scanf("%d", &N); // Read the number of apple species

  // Declare an array to store the capacity of each box
  int c[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &c[i]); // Read the capacity of each box
  }

  scanf("%d", &Q); // Read the number of instructions

  // Declare an array to store the number of apples in each box
  int apples[N] = {0}; 

  // Loop through each instruction
  for (int i = 0; i < Q; i++) {
    int t, x, d;
    scanf("%d %d %d", &t, &x, &d); // Read the instruction type, apple species, and number of apples

    // Handle "harvest apples" instruction
    if (t == 1) {
      // Check if the amount of apples exceeds the capacity of the box
      if (apples[x - 1] + d > c[x - 1]) { 
        printf("%d\n", x); // Output the index of the apple species
        return 0; // Exit the program
      } else {
        apples[x - 1] += d; // Add the apples to the box
      }
    } 
    // Handle "ship apples" instruction
    else if (t == 2) {
      // Check if there are not enough apples to ship
      if (apples[x - 1] < d) {
        printf("%d\n", x); // Output the index of the apple species
        return 0; // Exit the program
      } else {
        apples[x - 1] -= d; // Remove the apples from the box
      }
    }
  }

  printf("0\n"); // Output 0 if no impossible instruction found
  return 0;
}