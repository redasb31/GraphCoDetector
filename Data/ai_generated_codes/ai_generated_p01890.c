#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define MAX_G 10000
#define MAX_D 10000

typedef struct {
    int to;
    int distance;
    int next;
} Edge;

typedef struct {
    int head;
    int size;
    Edge *edges;
} Graph;

Graph graph;
int gas[MAX_N];
int visited[MAX_N];
int max_cities = 0;

void add_edge(int from, int to, int distance) {
    Edge *new_edge = (Edge *)malloc(sizeof(Edge));
    new_edge->to = to;
    new_edge->distance = distance;
    new_edge->next = graph.edges[from].next;
    graph.edges[from].next = graph.size;
    graph.edges[graph.size] = *new_edge;
    graph.size++;
}

void dfs(int current, int fuel, int cities) {
    visited[current] = 1;
    max_cities = cities > max_cities ? cities : max_cities;

    for (int i = graph.edges[current].next; i != -1; i = graph.edges[i].next) {
        int next = graph.edges[i].to;
        int distance = graph.edges[i].distance;

        if (visited[next] == 0 && fuel >= distance) {
            dfs(next, fuel - distance + gas[next], cities + 1);
        }
    }

    visited[current] = 0;
}

int main() {
    int n;
    scanf("%d", &n);

    // Initialize graph
    graph.head = 0;
    graph.size = 0;
    graph.edges = (Edge *)malloc(sizeof(Edge) * (n + 1));
    for (int i = 0; i <= n; i++) {
        graph.edges[i].next = -1;
    }

    // Input gas amount for each city
    for (int i = 1; i <= n; i++) {
        scanf("%d", &gas[i]);
    }

    // Input road information
    for (int i = 1; i < n; i++) {
        int a, b, d;
        scanf("%d %d %d", &a, &b, &d);
        add_edge(a, b, d);
        add_edge(b, a, d);
    }

    // Find the maximum number of cities reachable from each city
    for (int i = 1; i <= n; i++) {
        dfs(i, gas[i], 1);
    }

    printf("%d\n", max_cities);

    free(graph.edges);

    return 0;
}