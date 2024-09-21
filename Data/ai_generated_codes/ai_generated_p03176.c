#include <stdio.h>
#include <stdlib.h>

// Structure to store flower information
typedef struct {
  int height;
  int beauty;
} Flower;

// Function to compare heights of two flowers for sorting
int compare_height(const void *a, const void *b) {
  Flower *flower_a = (Flower *)a;
  Flower *flower_b = (Flower *)b;
  return flower_a->height - flower_b->height;
}

int main() {
  int N; // Number of flowers
  scanf("%d", &N);

  // Allocate memory for flowers
  Flower *flowers = (Flower *)malloc(sizeof(Flower) * N);

  // Read flower information
  for (int i = 0; i < N; i++) {
    scanf("%d", &flowers[i].height);
  }
  for (int i = 0; i < N; i++) {
    scanf("%d", &flowers[i].beauty);
  }

  // Sort flowers by height
  qsort(flowers, N, sizeof(Flower), compare_height);

  // Calculate maximum beauty sum
  long long max_beauty = 0; // Use long long to avoid overflow
  int prev_height = 0; // Keep track of the previous flower's height
  for (int i = 0; i < N; i++) {
    // If the current flower's height is greater than the previous one, 
    // it can be included in the increasing sequence
    if (flowers[i].height > prev_height) {
      max_beauty += flowers[i].beauty;
      prev_height = flowers[i].height;
    }
  }

  // Print the result
  printf("%lld\n", max_beauty);

  // Free allocated memory
  free(flowers);

  return 0;
}