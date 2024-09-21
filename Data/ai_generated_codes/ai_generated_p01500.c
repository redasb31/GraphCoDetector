#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 100
#define MAX_K 3

// Structure to represent a rock
typedef struct {
  int x;
  int y;
} Rock;

// Structure to represent a rabbit
typedef struct {
  int start;
  int dest;
  int visited;
  double distance;
} Rabbit;

// Function to calculate the distance between two rocks
double distance(Rock a, Rock b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Function to find the nearest rock within range R
int findNearestRock(Rock current, Rock rocks[], int n, double R, int visited[]) {
  int nearest = -1;
  double minDistance = R + 1;

  for (int i = 0; i < n; i++) {
    if (i != current.x && rocks[i].y >= current.y && visited[i] == 0 && distance(current, rocks[i]) <= R && distance(current, rocks[i]) < minDistance) {
      nearest = i;
      minDistance = distance(current, rocks[i]);
    }
  }

  return nearest;
}

// Function to calculate the total distance for all rabbits
double calculateDistance(Rabbit rabbits[], Rock rocks[], int n, double R) {
  double totalDistance = 0;
  int visited[MAX_N] = {0};

  for (int i = 0; i < MAX_K; i++) {
    if (rabbits[i].visited == 0) {
      int current = rabbits[i].start;
      int dest = rabbits[i].dest;
      visited[current] = 1;
      rabbits[i].distance = 0;

      while (current != dest) {
        int next = findNearestRock(rocks[current], rocks, n, R, visited);

        if (next == -1) {
          return -1; // Cannot reach destination
        }

        rabbits[i].distance += distance(rocks[current], rocks[next]);
        current = next;
        visited[current] = 1;
      }

      totalDistance += rabbits[i].distance;
    }
  }

  return totalDistance;
}

int main() {
  int N, K;
  double R;
  Rock rocks[MAX_N];
  Rabbit rabbits[MAX_K];

  // Input number of rocks, rabbits, and maximum leap distance
  scanf("%d %d %lf", &N, &K, &R);

  // Input starting and destination rocks for each rabbit
  for (int i = 0; i < K; i++) {
    scanf("%d", &rabbits[i].start);
    rabbits[i].start--; // Adjust index to 0-based
  }

  for (int i = 0; i < K; i++) {
    scanf("%d", &rabbits[i].dest);
    rabbits[i].dest--; // Adjust index to 0-based
  }

  // Input coordinates of rocks
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &rocks[i].x, &rocks[i].y);
  }

  // Calculate total distance and print the result
  double totalDistance = calculateDistance(rabbits, rocks, N, R);

  if (totalDistance >= 0) {
    printf("%.6lf\n", totalDistance);
  } else {
    printf("-1\n");
  }

  return 0;
}