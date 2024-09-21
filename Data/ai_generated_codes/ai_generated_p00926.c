#include <stdio.h>
#include <stdlib.h>

// Structure to represent a shop
typedef struct Shop {
  int id; // Shop ID
  int position; // Position of the shop
  int visited; // Flag to indicate if the shop has been visited
} Shop;

// Function to compare two shops based on their positions
int compareShops(const void *a, const void *b) {
  Shop *shopA = (Shop *)a;
  Shop *shopB = (Shop *)b;
  return shopA->position - shopB->position;
}

// Function to calculate the minimum walking distance
int calculateWalkingDistance(Shop *shops, int N, int m, int **restrictions) {
  int distance = 0; // Total walking distance
  int currentPosition = 1; // Current position
  int nextShop = 1; // Index of the next shop to visit

  // Sort shops based on their positions
  qsort(shops, N, sizeof(Shop), compareShops);

  // Mark the entrance as visited
  shops[0].visited = 1;

  // Iterate through the shops
  for (int i = 1; i <= N; i++) {
    // Find the next shop to visit based on restrictions
    while (nextShop <= N && shops[nextShop].visited == 1) {
      nextShop++;
    }

    // Check if there are restrictions
    if (m > 0) {
      // Check if there is a restriction for the current shop
      for (int j = 0; j < m; j++) {
        // If the current shop needs to be visited after a specific shop
        if (restrictions[j][1] == shops[i].id && shops[restrictions[j][0] - 1].visited == 0) {
          // Go back to the restricted shop
          currentPosition = shops[restrictions[j][0] - 1].position;
          shops[restrictions[j][0] - 1].visited = 1;
          break;
        }
      }
    }

    // Calculate the walking distance to the next shop
    distance += abs(currentPosition - shops[i].position);
    currentPosition = shops[i].position;
    shops[i].visited = 1;

    // Update the index of the next shop to visit
    nextShop = i + 1;
  }

  // Calculate the walking distance from the last shop to the exit
  distance += N + 1 - shops[N - 1].position;

  return distance;
}

int main() {
  int N, m; // Number of shops and restrictions
  int **restrictions; // Array to store restrictions

  // Read input
  scanf("%d %d", &N, &m);

  // Allocate memory for restrictions
  restrictions = (int **)malloc(m * sizeof(int *));
  for (int i = 0; i < m; i++) {
    restrictions[i] = (int *)malloc(2 * sizeof(int));
  }

  // Read restrictions
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &restrictions[i][0], &restrictions[i][1]);
  }

  // Create an array of shops
  Shop *shops = (Shop *)malloc(N * sizeof(Shop));

  // Initialize shops
  for (int i = 0; i < N; i++) {
    shops[i].id = i + 1;
    shops[i].position = i + 1;
    shops[i].visited = 0;
  }

  // Calculate and print the minimum walking distance
  int distance = calculateWalkingDistance(shops, N, m, restrictions);
  printf("%d\n", distance);

  // Free allocated memory
  free(shops);
  for (int i = 0; i < m; i++) {
    free(restrictions[i]);
  }
  free(restrictions);

  return 0;
}