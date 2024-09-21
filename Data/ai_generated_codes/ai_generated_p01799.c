#include <stdio.h>
#include <stdlib.h>

// Structure to represent a character with hit point and defense point
typedef struct {
  int hp;
  int dp;
} Character;

// Function to calculate the absolute difference of two integers
int abs(int a, int b) {
  return a > b ? a - b : b - a;
}

// Function to find the number of characters that can be the target
int countPossibleTargets(Character v[], int n, int C) {
  int count = 0;
  int minHp = v[0].hp;
  int minDp = v[0].dp;

  // Iterate through the characters
  for (int i = 1; i < n; i++) {
    // If the current character has a hit point within the difference threshold 'C' of the current minimum hit point
    if (abs(v[i].hp, minHp) <= C) {
      // If the current character has a lower hit point than the current minimum, update the minimum hit point and defense point
      if (v[i].hp < minHp) {
        minHp = v[i].hp;
        minDp = v[i].dp;
      }
      // If the current character has the same hit point as the current minimum but a lower defense point, update the minimum defense point
      else if (v[i].hp == minHp && v[i].dp < minDp) {
        minDp = v[i].dp;
      }
      // Increment the count as this character can be a potential target
      count++;
    }
  }

  return count;
}

int main() {
  int n, C;
  scanf("%d %d", &n, &C);

  Character v[n];

  // Read the hit point and defense point of each character
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &v[i].hp, &v[i].dp);
  }

  // Calculate and print the number of possible targets
  int result = countPossibleTargets(v, n, C);
  printf("%d\n", result);

  return 0;
}