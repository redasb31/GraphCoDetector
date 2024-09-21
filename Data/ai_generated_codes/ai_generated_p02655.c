#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 100000
#define MAX_M 100000

// Structure to represent a ball
typedef struct {
  int box; // Current box number
  int target_box; // Target box number
  int moves_left; // Remaining moves allowed
} Ball;

// Function to find the minimum number of operations required
// to move all balls to their target boxes
int min_operations(int n, int m, Ball *balls) {
  // Create a graph to represent the boxes and their connections
  int graph[MAX_N + 1][MAX_N + 1] = {0}; 

  // Initialize the graph based on the balls' current and target boxes
  for (int i = 1; i <= m; i++) {
    graph[balls[i].box][balls[i].target_box]++;
  }

  // Perform a Depth-First Search (DFS) from each box
  int visited[MAX_N + 1] = {0}; // Array to track visited boxes
  int operations = 0;

  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      // Perform DFS from box i
      int current_operations = 0;
      current_operations = dfs(graph, visited, i, balls, current_operations);
      if (current_operations == -1) {
        // If any DFS returns -1, it means the objective is unachievable
        return -1;
      }
      operations += current_operations;
    }
  }

  // Return the total number of operations
  return operations;
}

// Depth-First Search function to move balls within a connected component
int dfs(int graph[][MAX_N + 1], int visited[], int box, Ball *balls, int operations) {
  visited[box] = 1;

  // Iterate through all the target boxes connected to the current box
  for (int target_box = 1; target_box <= MAX_N; target_box++) {
    if (graph[box][target_box] > 0) {
      // Find the corresponding ball for the target box
      int ball_index = -1;
      for (int i = 1; i <= MAX_M; i++) {
        if (balls[i].target_box == target_box && balls[i].box == box) {
          ball_index = i;
          break;
        }
      }

      // If a ball is found, move it to the target box
      if (ball_index != -1) {
        if (balls[ball_index].moves_left == 0) {
          // If the ball has no moves left, the objective is unachievable
          return -1;
        }
        // Move the ball and update its moves left
        balls[ball_index].box = target_box;
        balls[ball_index].moves_left--;
        operations++;
        // Recursively call DFS for the target box
        operations = dfs(graph, visited, target_box, balls, operations);
        // If any DFS returns -1, it means the objective is unachievable
        if (operations == -1) {
          return -1;
        }
      }
    }
  }

  // Return the total number of operations for this connected component
  return operations;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  Ball balls[MAX_M + 1];
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %d", &balls[i].box, &balls[i].target_box, &balls[i].moves_left);
  }

  int operations = min_operations(n, m, balls);

  printf("%d\n", operations);

  return 0;
}