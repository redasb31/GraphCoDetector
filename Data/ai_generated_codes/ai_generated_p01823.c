#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 200
#define MAX_M 20000
#define MAX_P 1000
#define MAX_D 1000
#define MAX_V 1000

// Structure to represent a road
struct Road {
    int s, t; // endpoints of the road
    int d; // length of the road
    int v; // number of people on the road
};

// Structure to represent a node in the graph
struct Node {
    int id; // id of the node
    int dist; // distance from the source node
    int prev; // previous node in the shortest path
};

// Function to compare two nodes based on their distance
int compare(const void *a, const void *b) {
    return ((struct Node *)a)->dist - ((struct Node *)b)->dist;
}

// Function to find the shortest path from the source node to all other nodes
void dijkstra(int N, struct Road roads[MAX_M], int source, int dist[MAX_N], int prev[MAX_N]) {
    // Initialize distance and previous node arrays
    for (int i = 1; i <= N; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1;
    }

    // Initialize priority queue
    struct Node nodes[MAX_N];
    for (int i = 1; i <= N; i++) {
        nodes[i - 1].id = i;
        nodes[i - 1].dist = INT_MAX;
        nodes[i - 1].prev = -1;
    }
    nodes[source - 1].dist = 0;

    // Sort nodes by distance
    qsort(nodes, N, sizeof(struct Node), compare);

    // Process nodes in order of increasing distance
    for (int i = 0; i < N; i++) {
        int u = nodes[i].id;

        // Update distances of neighboring nodes
        for (int j = 0; j < M; j++) {
            if (roads[j].s == u) {
                int v = roads[j].t;
                if (dist[u] + roads[j].d < dist[v]) {
                    dist[v] = dist[u] + roads[j].d;
                    prev[v] = u;
                    // Re-sort the priority queue
                    qsort(nodes, N, sizeof(struct Node), compare);
                }
            } else if (roads[j].t == u) {
                int v = roads[j].s;
                if (dist[u] + roads[j].d < dist[v]) {
                    dist[v] = dist[u] + roads[j].d;
                    prev[v] = u;
                    // Re-sort the priority queue
                    qsort(nodes, N, sizeof(struct Node), compare);
                }
            }
        }
    }
}

// Function to calculate the impression degree of a path
double calculate_impression_degree(int N, struct Road roads[MAX_M], int path[MAX_N], int P) {
    double impression_degree = 0.0;
    int current_time = 0;
    int current_node = 1;
    int path_length = 0;
    int i = 0;
    // Iterate through the path
    while (current_time < P) {
        if (path[i] == current_node) {
            // Find the next node in the path
            i++;
            if (i == path_length) {
                i = 0; // Restart from the beginning of the path
            }
            // Find the road connecting the current node and the next node
            for (int j = 0; j < M; j++) {
                if ((roads[j].s == current_node && roads[j].t == path[i]) ||
                    (roads[j].s == path[i] && roads[j].t == current_node)) {
                    // Calculate the impression degree for the current road
                    impression_degree += ((double)roads[j].v * (double)roads[j].d) / (double)roads[j].d;
                    // Update the current time
                    current_time += roads[j].d;
                    // Update the current node
                    current_node = path[i];
                    break;
                }
            }
        } else {
            // Move to the next node
            for (int j = 0; j < M; j++) {
                if ((roads[j].s == current_node && roads[j].t == path[i]) ||
                    (roads[j].s == path[i] && roads[j].t == current_node)) {
                    // Update the current time
                    current_time += roads[j].d;
                    // Update the current node
                    current_node = path[i];
                    break;
                }
            }
        }
    }
    return impression_degree;
}

// Function to find the path with the maximum impression degree
double find_max_impression_degree(int N, struct Road roads[MAX_M], int P) {
    double max_impression_degree = 0.0;

    // Find the shortest paths from node 1 to all other nodes
    int dist[MAX_N];
    int prev[MAX_N];
    dijkstra(N, roads, 1, dist, prev);

    // Create a path array to store the path
    int path[MAX_N];
    int path_length = 0;

    // Iterate through all possible paths
    for (int i = 1; i <= N; i++) {
        // Find the path from node 1 to node i and back to node 1
        int current_node = i;
        while (current_node != 1) {
            path[path_length++] = current_node;
            current_node = prev[current_node];
        }
        // Add node 1 to the beginning of the path
        path[path_length++] = 1;
        // Reverse the path
        for (int j = 0; j < path_length / 2; j++) {
            int temp = path[j];
            path[j] = path[path_length - j - 1];
            path[path_length - j - 1] = temp;
        }

        // Calculate the impression degree of the current path
        double impression_degree = calculate_impression_degree(N, roads, path, P);

        // Update the maximum impression degree
        if (impression_degree > max_impression_degree) {
            max_impression_degree = impression_degree;
        }

        // Reset the path length
        path_length = 0;
    }

    return max_impression_degree;
}

int main() {
    int N, M, P;
    struct Road roads[MAX_M];

    // Read the input
    scanf("%d %d %d", &N, &M, &P);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d %d", &roads[i].s, &roads[i].t, &roads[i].d, &roads[i].v);
    }

    // Find the maximum impression degree
    double max_impression_degree = find_max_impression_degree(N, roads, P);

    // Print the output
    printf("%.10lf\n", max_impression_degree);

    return 0;
}