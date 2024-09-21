#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353

typedef struct Robot {
  long long x;
  long long d;
} Robot;

// Function to compare robots based on their position
int compare_robots(const void *a, const void *b) {
  Robot *robot_a = (Robot *)a;
  Robot *robot_b = (Robot *)b;
  return robot_a->x - robot_b->x;
}

// Function to calculate the number of possible sets of robots remaining
long long count_subsets(Robot *robots, int n) {
  // Sort the robots based on their position
  qsort(robots, n, sizeof(Robot), compare_robots);

  // Initialize the count of possible subsets
  long long count = 1;

  // Iterate over the robots
  for (int i = 0; i < n; i++) {
    // Check if the current robot can reach any other robot
    int reachable = 0;
    for (int j = i + 1; j < n; j++) {
      if (robots[j].x < robots[i].x + robots[i].d) {
        reachable = 1;
        break;
      }
    }
    // If the current robot can reach another robot, there are two possibilities:
    // 1. The current robot is activated, and then the other robot.
    // 2. The current robot is not activated.
    if (reachable) {
      count = (count * 2) % MOD;
    }
  }

  // Return the count of possible subsets
  return count;
}

int main() {
  int n;
  scanf("%d", &n);

  // Allocate memory for the robots
  Robot *robots = (Robot *)malloc(n * sizeof(Robot));

  // Read the robots' positions and distances
  for (int i = 0; i < n; i++) {
    scanf("%lld %lld", &robots[i].x, &robots[i].d);
  }

  // Calculate the number of possible subsets
  long long count = count_subsets(robots, n);

  // Print the count
  printf("%lld\n", count);

  // Free the allocated memory
  free(robots);

  return 0;
}