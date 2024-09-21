#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declare variables to store the costs of each task
  int A[3];

  // Read the costs of the tasks from standard input
  scanf("%d %d %d", &A[0], &A[1], &A[2]);

  // Calculate the minimum cost
  // The minimum cost is either:
  // 1. Completing the tasks in the order 1, 2, 3
  // 2. Completing the tasks in the order 1, 3, 2
  // 3. Completing the tasks in the order 2, 1, 3
  // 4. Completing the tasks in the order 2, 3, 1
  // 5. Completing the tasks in the order 3, 1, 2
  // 6. Completing the tasks in the order 3, 2, 1
  int min_cost = abs(A[1] - A[0]) + abs(A[2] - A[1]); // Cost of completing tasks in order 1, 2, 3
  min_cost = (min_cost < abs(A[2] - A[0]) + abs(A[1] - A[2])) ? min_cost : abs(A[2] - A[0]) + abs(A[1] - A[2]); // Cost of completing tasks in order 1, 3, 2
  min_cost = (min_cost < abs(A[0] - A[1]) + abs(A[2] - A[0])) ? min_cost : abs(A[0] - A[1]) + abs(A[2] - A[0]); // Cost of completing tasks in order 2, 1, 3
  min_cost = (min_cost < abs(A[0] - A[1]) + abs(A[1] - A[2])) ? min_cost : abs(A[0] - A[1]) + abs(A[1] - A[2]); // Cost of completing tasks in order 2, 3, 1
  min_cost = (min_cost < abs(A[1] - A[2]) + abs(A[0] - A[1])) ? min_cost : abs(A[1] - A[2]) + abs(A[0] - A[1]); // Cost of completing tasks in order 3, 1, 2
  min_cost = (min_cost < abs(A[1] - A[2]) + abs(A[2] - A[0])) ? min_cost : abs(A[1] - A[2]) + abs(A[2] - A[0]); // Cost of completing tasks in order 3, 2, 1

  // Print the minimum cost
  printf("%d\n", min_cost);

  return 0;
}