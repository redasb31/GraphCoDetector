#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000009

// Structure to represent a relationship between two students
typedef struct Relationship {
  int student1;
  int student2;
  int type; // 0 for good relationship, 1 for bad relationship
} Relationship;

// Function to calculate the number of possible team assignments
long long count_assignments(int n, Relationship *relationships, int m) {
  // Create an adjacency list to represent the relationships
  int **adj_list = (int **)malloc(sizeof(int *) * (3 * n + 1));
  for (int i = 1; i <= 3 * n; i++) {
    adj_list[i] = (int *)malloc(sizeof(int) * 10); // Assuming maximum degree is 10
    adj_list[i][0] = 0;
  }

  // Populate the adjacency list
  for (int i = 0; i < m; i++) {
    int u = relationships[i].student1;
    int v = relationships[i].student2;
    int type = relationships[i].type;

    // Add edge for good relationship (students must be in the same team)
    if (type == 0) {
      adj_list[u][++adj_list[u][0]] = v;
      adj_list[v][++adj_list[v][0]] = u;
    }
  }

  // Perform Depth First Search (DFS) to find connected components
  int visited[3 * n + 1] = {0};
  long long count = 1;
  for (int i = 1; i <= 3 * n; i++) {
    if (!visited[i]) {
      // Perform DFS starting from the current student
      int component_size = dfs(adj_list, i, visited);

      // Check if the component size is divisible by 3
      if (component_size % 3 != 0) {
        return 0; // Not possible to form valid teams
      }

      // Multiply count with the factorial of (component_size / 3)
      count = (count * factorial(component_size / 3)) % MOD;
    }
  }

  // Free the allocated memory
  for (int i = 1; i <= 3 * n; i++) {
    free(adj_list[i]);
  }
  free(adj_list);

  return count;
}

// Recursive function for Depth First Search (DFS)
int dfs(int **adj_list, int node, int *visited) {
  visited[node] = 1;
  int component_size = 1;
  for (int i = 1; i <= adj_list[node][0]; i++) {
    int neighbor = adj_list[node][i];
    if (!visited[neighbor]) {
      component_size += dfs(adj_list, neighbor, visited);
    }
  }
  return component_size;
}

// Function to calculate the factorial of a number
long long factorial(int n) {
  long long fact = 1;
  for (int i = 2; i <= n; i++) {
    fact = (fact * i) % MOD;
  }
  return fact;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  // Read the relationships
  Relationship *relationships = (Relationship *)malloc(sizeof(Relationship) * m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &relationships[i].student1, &relationships[i].student2, &relationships[i].type);
  }

  // Calculate the number of possible team assignments
  long long count = count_assignments(n, relationships, m);

  // Print the result
  printf("%lld\n", count);

  // Free the allocated memory
  free(relationships);

  return 0;
}