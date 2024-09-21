#include <stdio.h>
#include <stdlib.h>

// Structure to store dish information
typedef struct {
  int time;
  int deliciousness;
} Dish;

// Function to compare two dishes based on deliciousness (descending order)
int compareDishes(const void *a, const void *b) {
  Dish *dishA = (Dish *)a;
  Dish *dishB = (Dish *)b;
  return dishB->deliciousness - dishA->deliciousness;
}

int main() {
  int N, T;
  scanf("%d %d", &N, &T);

  // Allocate memory for dishes
  Dish *dishes = malloc(sizeof(Dish) * N);
  if (dishes == NULL) {
    fprintf(stderr, "Memory allocation failed!\n");
    return 1;
  }

  // Read dish information
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &dishes[i].time, &dishes[i].deliciousness);
  }

  // Sort dishes by deliciousness in descending order
  qsort(dishes, N, sizeof(Dish), compareDishes);

  // Calculate maximum happiness
  int happiness = 0;
  int timeRemaining = T - 30; // Subtract 30 seconds for the initial order

  // Iterate through dishes in decreasing order of deliciousness
  for (int i = 0; i < N; i++) {
    // Check if there's enough time to eat the current dish
    if (timeRemaining >= dishes[i].time) {
      happiness += dishes[i].deliciousness;
      timeRemaining -= dishes[i].time;
    } else {
      break; // No more dishes can be eaten
    }
  }

  // Print maximum happiness
  printf("%d\n", happiness);

  // Free allocated memory
  free(dishes);

  return 0;
}