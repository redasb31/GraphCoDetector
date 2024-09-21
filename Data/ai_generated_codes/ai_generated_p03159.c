#include <stdio.h>
#include <stdlib.h>

#define MAX_N 5000

// Structure to represent a device
typedef struct {
  int id;  // Device ID
  int power; // Power (positive for battery, negative for computer)
} Device;

// Structure to represent an edge in the graph
typedef struct {
  int u; // Source device ID
  int v; // Destination device ID
} Edge;

// Function to create a new device
Device *createDevice(int id, int power) {
  Device *device = (Device *)malloc(sizeof(Device));
  device->id = id;
  device->power = power;
  return device;
}

// Function to create a new edge
Edge *createEdge(int u, int v) {
  Edge *edge = (Edge *)malloc(sizeof(Edge));
  edge->u = u;
  edge->v = v;
  return edge;
}

// Function to perform Depth First Search (DFS) to find connected components
void dfs(int current, Device **devices, int **adj_matrix, int *visited, int *component_power) {
  visited[current] = 1;
  *component_power += devices[current]->power;

  for (int i = 1; i <= MAX_N; i++) {
    if (adj_matrix[current][i] && !visited[i]) {
      dfs(i, devices, adj_matrix, visited, component_power);
    }
  }
}

// Function to count the number of cables to disconnect
int countCablesToDisconnect(Device **devices, int n, Edge **edges, int m) {
  int **adj_matrix = (int **)malloc((MAX_N + 1) * sizeof(int *));
  for (int i = 0; i <= MAX_N; i++) {
    adj_matrix[i] = (int *)calloc((MAX_N + 1), sizeof(int));
  }

  // Create adjacency matrix from edges
  for (int i = 0; i < m; i++) {
    adj_matrix[edges[i]->u][edges[i]->v] = 1;
    adj_matrix[edges[i]->v][edges[i]->u] = 1;
  }

  int cables_to_disconnect = 0;
  int *visited = (int *)calloc((MAX_N + 1), sizeof(int));
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      int component_power = 0;
      dfs(i, devices, adj_matrix, visited, &component_power);

      // Check if the component is disabled
      if (component_power > 0 || component_power < 0) {
        cables_to_disconnect += 1;  // Disconnect one cable to isolate the component
      }
    }
  }

  free(visited);
  for (int i = 0; i <= MAX_N; i++) {
    free(adj_matrix[i]);
  }
  free(adj_matrix);

  return cables_to_disconnect - 1; // Subtract 1 to account for the initial connected component
}

int main() {
  int n, m;
  scanf("%d", &n);

  // Allocate memory for devices and edges
  Device **devices = (Device **)malloc((n + 1) * sizeof(Device *));
  Edge **edges = (Edge **)malloc((n - 1) * sizeof(Edge *));

  // Read device power values
  for (int i = 1; i <= n; i++) {
    int power;
    scanf("%d", &power);
    devices[i] = createDevice(i, power);
  }

  // Read edges connecting devices
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edges[i] = createEdge(u, v);
  }

  // Count the minimum number of cables to disconnect
  int cables_to_disconnect = countCablesToDisconnect(devices, n, edges, n - 1);
  printf("%d\n", cables_to_disconnect);

  // Free allocated memory
  for (int i = 1; i <= n; i++) {
    free(devices[i]);
  }
  free(devices);
  for (int i = 0; i < n - 1; i++) {
    free(edges[i]);
  }
  free(edges);

  return 0;
}