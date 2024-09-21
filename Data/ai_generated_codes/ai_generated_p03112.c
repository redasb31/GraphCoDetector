#include <stdio.h>
#include <stdlib.h>

// Function to find the minimum distance to visit a shrine and a temple from a given point
int findMinDistance(long long int *shrines, int numShrines, long long int *temples, int numTemples, long long int start) {
  // Find the nearest shrine to the start point
  int i = 0;
  while (i < numShrines && shrines[i] < start) {
    i++;
  }
  long long int nearestShrine = i == 0 ? shrines[0] : shrines[i - 1];

  // Find the nearest temple to the start point
  int j = 0;
  while (j < numTemples && temples[j] < start) {
    j++;
  }
  long long int nearestTemple = j == 0 ? temples[0] : temples[j - 1];

  // Calculate the minimum distance to visit a shrine and a temple
  long long int distanceToShrine = abs(start - nearestShrine);
  long long int distanceToTemple = abs(start - nearestTemple);
  return distanceToShrine + distanceToTemple;
}

int main() {
  // Input the number of shrines, temples, and queries
  int numShrines, numTemples, numQueries;
  scanf("%d %d %d", &numShrines, &numTemples, &numQueries);

  // Allocate memory for the shrines and temples
  long long int *shrines = (long long int *)malloc(numShrines * sizeof(long long int));
  long long int *temples = (long long int *)malloc(numTemples * sizeof(long long int));

  // Input the shrine positions
  for (int i = 0; i < numShrines; i++) {
    scanf("%lld", &shrines[i]);
  }

  // Input the temple positions
  for (int i = 0; i < numTemples; i++) {
    scanf("%lld", &temples[i]);
  }

  // Input the query points
  long long int *queryPoints = (long long int *)malloc(numQueries * sizeof(long long int));
  for (int i = 0; i < numQueries; i++) {
    scanf("%lld", &queryPoints[i]);
  }

  // Process each query and output the minimum distance
  for (int i = 0; i < numQueries; i++) {
    printf("%lld\n", findMinDistance(shrines, numShrines, temples, numTemples, queryPoints[i]));
  }

  // Free the allocated memory
  free(shrines);
  free(temples);
  free(queryPoints);

  return 0;
}