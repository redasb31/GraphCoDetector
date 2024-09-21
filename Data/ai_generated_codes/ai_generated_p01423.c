#include <stdio.h>
#include <limits.h>

#define MAX_N 100
#define MAX_M 100

int main() {
  int n, m;
  int u, v, f;
  int graph[MAX_N + 1][MAX_N + 1]; // Adjacency matrix to store friendliness values
  int visited[MAX_N + 1]; // Array to keep track of visited nodes
  int max_satisfaction = 0; 

  // Initialize the graph with 0 friendliness
  for (int i = 1; i <= MAX_N; i++) {
    for (int j = 1; j <= MAX_N; j++) {
      graph[i][j] = 0;
    }
  }

  // Read input values
  scanf("%d %d", &n, &m);

  // Populate the graph with friendliness values
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &u, &v, &f);
    graph[u][v] = f;
    graph[v][u] = f; // Undirected graph
  }

  // Iterate through each rabbit (potential party guest)
  for (int i = 1; i <= n; i++) {
    int current_satisfaction = 0;
    int min_friendliness = INT_MAX; 
    // Reset visited array
    for (int j = 1; j <= n; j++) {
      visited[j] = 0;
    }

    // Iterate through each potential guest's friends
    for (int j = 1; j <= n; j++) {
      if (graph[i][j] > 0) {
        // If the potential guest is already visited, it means the friend is already included
        if (visited[j] == 0) {
          // Update min_friendliness if a new friend is found
          if (graph[i][j] < min_friendliness) {
            min_friendliness = graph[i][j];
          }
          visited[j] = 1; // Mark the friend as visited
          current_satisfaction += min_friendliness; // Add the minimum friendliness to the satisfaction score
        }
      }
    }

    // Update max_satisfaction if the current satisfaction is higher
    if (current_satisfaction > max_satisfaction) {
      max_satisfaction = current_satisfaction;
    }
  }

  printf("%d\n", max_satisfaction); // Print the maximum possible satisfaction score
  return 0;
}