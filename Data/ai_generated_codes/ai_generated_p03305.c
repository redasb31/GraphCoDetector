#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 100000
#define MAX_M 100000
#define INF (LLONG_MAX / 2)

typedef long long ll;

// Edge structure for the graph
typedef struct Edge {
    int to;
    ll a;
    ll b;
} Edge;

// Adjacency list representation of the graph
Edge graph[MAX_M][2];
int head[MAX_N + 1];
int edge_count;

// Distance table for yen
ll dist_yen[MAX_N + 1];
// Distance table for snuuk
ll dist_snuuk[MAX_N + 1];

// Function to add an edge to the graph
void add_edge(int u, int v, ll a, ll b) {
    graph[edge_count][0].to = v;
    graph[edge_count][0].a = a;
    graph[edge_count][0].b = b;
    head[u] = edge_count++;
    graph[edge_count][0].to = u;
    graph[edge_count][0].a = a;
    graph[edge_count][0].b = b;
    head[v] = edge_count++;
}

// Function to perform Dijkstra's algorithm for yen
void dijkstra_yen(int start) {
    // Initialize distance table for yen
    for (int i = 1; i <= MAX_N; ++i) {
        dist_yen[i] = INF;
    }
    dist_yen[start] = 0;

    // Priority queue to store nodes
    int *queue = (int*) malloc(sizeof(int) * (MAX_N + 1));
    int queue_head = 0;
    int queue_tail = 0;
    queue[queue_tail++] = start;

    while (queue_head < queue_tail) {
        int u = queue[queue_head++];
        // Iterate through edges of the current node
        for (int i = head[u]; i < edge_count; i += 2) {
            Edge e = graph[i][0];
            // If the distance to the neighbor is smaller than the current distance
            if (dist_yen[e.to] > dist_yen[u] + e.a) {
                dist_yen[e.to] = dist_yen[u] + e.a;
                // Add the neighbor to the queue if it's not already there
                int j;
                for (j = 0; j < queue_tail; ++j) {
                    if (queue[j] == e.to) {
                        break;
                    }
                }
                if (j == queue_tail) {
                    queue[queue_tail++] = e.to;
                }
            }
        }
    }

    free(queue);
}

// Function to perform Dijkstra's algorithm for snuuk
void dijkstra_snuuk(int start) {
    // Initialize distance table for snuuk
    for (int i = 1; i <= MAX_N; ++i) {
        dist_snuuk[i] = INF;
    }
    dist_snuuk[start] = 0;

    // Priority queue to store nodes
    int *queue = (int*) malloc(sizeof(int) * (MAX_N + 1));
    int queue_head = 0;
    int queue_tail = 0;
    queue[queue_tail++] = start;

    while (queue_head < queue_tail) {
        int u = queue[queue_head++];
        // Iterate through edges of the current node
        for (int i = head[u]; i < edge_count; i += 2) {
            Edge e = graph[i][0];
            // If the distance to the neighbor is smaller than the current distance
            if (dist_snuuk[e.to] > dist_snuuk[u] + e.b) {
                dist_snuuk[e.to] = dist_snuuk[u] + e.b;
                // Add the neighbor to the queue if it's not already there
                int j;
                for (j = 0; j < queue_tail; ++j) {
                    if (queue[j] == e.to) {
                        break;
                    }
                }
                if (j == queue_tail) {
                    queue[queue_tail++] = e.to;
                }
            }
        }
    }

    free(queue);
}

int main() {
    int n, m, s, t;
    scanf("%d %d %d %d", &n, &m, &s, &t);
    // Initialize the graph
    edge_count = 0;
    for (int i = 0; i <= n; ++i) {
        head[i] = -1;
    }
    // Input edges and build the graph
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll a, b;
        scanf("%d %d %lld %lld", &u, &v, &a, &b);
        add_edge(u, v, a, b);
    }

    // Run Dijkstra's algorithm for yen and snuuk from the source city
    dijkstra_yen(s);
    dijkstra_snuuk(s);

    // Calculate the maximum amount of snuuk for each year
    for (int i = 0; i < n; ++i) {
        ll max_snuuk = 0;
        // Calculate the maximum amount of snuuk attainable by changing currency in each city
        for (int j = 1; j <= n; ++j) {
            // If the exchange office is open
            if (i < j) {
                // Calculate the amount of snuuk obtained by changing currency in the current city
                ll snuuk = dist_yen[j] + (1000000000000000 - dist_yen[j]) - dist_snuuk[j] + dist_snuuk[t];
                // Update the maximum amount of snuuk
                max_snuuk = max_snuuk > snuuk ? max_snuuk : snuuk;
            }
        }
        // Print the maximum amount of snuuk
        printf("%lld\n", max_snuuk);
    }
    return 0;
}