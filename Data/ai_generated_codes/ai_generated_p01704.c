#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to store information about each flower
typedef struct {
  int vw; // Water effect
  int pf; // Fertilizer cost
  int vf; // Fertilizer effect
  int th; // Threshold for flowering
} Flower;

// Function to calculate the minimum cost
double minCost(int N, int pw, Flower *flowers) {
  // Initialize the cost to a very large value
  double cost = 1e9;

  // Iterate over all possible water amounts
  for (double W = 0; W <= 1000; W += 0.01) {
    // Calculate the current cost
    double currentCost = W * pw;

    // Iterate over each flower
    for (int i = 0; i < N; i++) {
      // Calculate the amount of fertilizer needed
      double F = (flowers[i].th - W * flowers[i].vw) / (double) flowers[i].vf;

      // If fertilizer amount is negative, it means this flower cannot be bloomed
      if (F < 0) {
        currentCost = 1e9;
        break;
      }

      // Add the cost of fertilizer
      currentCost += F * flowers[i].pf;
    }

    // Update the minimum cost
    cost = fmin(cost, currentCost);
  }

  // Return the minimum cost
  return cost;
}

int main() {
  int N, pw;
  while (1) {
    // Read the number of flowers
    scanf("%d", &N);

    // End of input
    if (N == 0) {
      break;
    }

    // Read the cost of watering
    scanf("%d", &pw);

    // Allocate memory for flowers
    Flower *flowers = (Flower *) malloc(N * sizeof(Flower));

    // Read flower information
    for (int i = 0; i < N; i++) {
      scanf("%d %d %d %d", &flowers[i].vw, &flowers[i].pf, &flowers[i].vf, &flowers[i].th);
    }

    // Calculate and print the minimum cost
    printf("%.4lf\n", minCost(N, pw, flowers));

    // Free the allocated memory
    free(flowers);
  }

  return 0;
}