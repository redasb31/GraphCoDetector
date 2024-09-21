#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x;
  int h;
} Monster;

// Function to compare the x coordinates of two monsters for sorting
int compare_monsters(const void *a, const void *b) {
  Monster *monster_a = (Monster *)a;
  Monster *monster_b = (Monster *)b;
  return monster_a->x - monster_b->x;
}

int main() {
  int N, D, A;
  scanf("%d %d %d", &N, &D, &A);

  // Allocate memory for N monsters
  Monster *monsters = malloc(sizeof(Monster) * N);

  // Read the coordinates and health of each monster
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &monsters[i].x, &monsters[i].h);
  }

  // Sort the monsters based on their x coordinates
  qsort(monsters, N, sizeof(Monster), compare_monsters);

  // Initialize the bomb count
  long long bomb_count = 0;
  int j = 0;

  // Iterate through the monsters
  for (int i = 0; i < N; i++) {
    // Find the farthest monster that can be affected by the current bomb
    while (j < N && monsters[j].x <= monsters[i].x + D) {
      j++;
    }
    // Calculate the number of bombs needed for the current monster
    bomb_count += (monsters[i].h + A - 1) / A;
    // Update the health of the affected monsters
    for (int k = i; k < j; k++) {
      monsters[k].h -= (monsters[i].h + A - 1) / A * A;
    }
  }

  // Print the minimum number of bombs
  printf("%lld\n", bomb_count);

  free(monsters);
  return 0;
}