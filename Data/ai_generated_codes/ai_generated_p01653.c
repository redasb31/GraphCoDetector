#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 1000
#define MAX_M 2000

// Structure to represent a bridge
struct Bridge {
    int a; // Island A
    int b; // Island B
    int w; // Length of the bridge (or 'x' for magical)
};

// Structure to represent a node in the graph
struct Node {
    int island; // Island number
    int distance; // Distance from the starting island
};

// Function to compare nodes based on their distance
int compareNodes(const void *a, const void *b) {
    return ((struct Node *)a)->distance - ((struct Node *)b)->distance;
}

// Function to perform Dijkstra's algorithm
int dijkstra(int n, struct Bridge bridges[], int num_bridges, int start, int end) {
    // Adjacency list to represent the graph
    int adj_list[MAX_N + 1][MAX_M];
    int num_edges[MAX_N + 1];
    for (int i = 1; i <= n; i++) {
        num_edges[i] = 0;
    }

    // Initialize the adjacency list
    for (int i = 0; i < num_bridges; i++) {
        if (bridges[i].w != 'x') { // Normal bridge
            adj_list[bridges[i].a][num_edges[bridges[i].a]] = bridges[i].b;
            adj_list[bridges[i].b][num_edges[bridges[i].b]] = bridges[i].a;
            num_edges[bridges[i].a]++;
            num_edges[bridges[i].b]++;
        }
    }

    // Initialize distances to infinity
    int distances[MAX_N + 1];
    for (int i = 1; i <= n; i++) {
        distances[i] = INT_MAX;
    }
    distances[start] = 0;

    // Priority queue to store nodes
    struct Node queue[MAX_N + 1];
    int queue_size = 0;
    queue[queue_size++] = (struct Node){start, 0};

    // While the priority queue is not empty
    while (queue_size > 0) {
        // Extract the node with the smallest distance
        qsort(queue, queue_size, sizeof(struct Node), compareNodes);
        struct Node current = queue[0];
        queue_size--;

        // If the current node is the destination, return the distance
        if (current.island == end) {
            return distances[end];
        }

        // Update distances of adjacent nodes
        for (int i = 0; i < num_edges[current.island]; i++) {
            int neighbor = adj_list[current.island][i];
            int distance = distances[current.island];

            // Find the length of the bridge connecting current and neighbor
            int bridge_length = 0;
            for (int j = 0; j < num_bridges; j++) {
                if ((bridges[j].a == current.island && bridges[j].b == neighbor) ||
                    (bridges[j].a == neighbor && bridges[j].b == current.island)) {
                    bridge_length = bridges[j].w;
                    break;
                }
            }

            // Update the distance if a shorter path is found
            if (distance + bridge_length < distances[neighbor]) {
                distances[neighbor] = distance + bridge_length;
                queue[queue_size++] = (struct Node){neighbor, distances[neighbor]};
            }
        }
    }

    // If the destination is not reachable, return -1
    return -1;
}

int main() {
    int n, m, s1, s2, t;
    struct Bridge bridges[MAX_M];
    int num_bridges = 0;

    while (1) {
        scanf("%d %d %d %d %d", &n, &m, &s1, &s2, &t);
        if (n == 0 && m == 0 && s1 == 0 && s2 == 0 && t == 0) {
            break;
        }

        // Read the bridge information
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &bridges[i].a, &bridges[i].b, &bridges[i].w);
            if (bridges[i].w == 'x') {
                num_bridges++;
            }
        }

        // Calculate the shortest distances from S1 and S2 to T
        int distance_s1 = dijkstra(n, bridges, m, s1, t);
        int distance_s2 = dijkstra(n, bridges, m, s2, t);

        // Find the minimum difference in shortest distances
        int min_diff = INT_MAX;
        for (int i = 0; i < num_bridges; i++) {
            // Assign a length to the magical bridge
            for (int length = 0; length <= 1000000000; length++) {
                bridges[i].w = length;

                // Calculate shortest distances again
                int new_distance_s1 = dijkstra(n, bridges, m, s1, t);
                int new_distance_s2 = dijkstra(n, bridges, m, s2, t);

                // Update the minimum difference
                if (new_distance_s1 != -1 && new_distance_s2 != -1 && abs(new_distance_s1 - new_distance_s2) < min_diff) {
                    min_diff = abs(new_distance_s1 - new_distance_s2);
                }
            }

            // Restore the magical bridge to 'x'
            bridges[i].w = 'x';
        }

        printf("%d\n", min_diff);
    }

    return 0;
}