#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define MAX_M 200000

// Structure to represent an edge in the graph
typedef struct Edge {
    int u, v;
} Edge;

// Structure to represent a node in the graph
typedef struct Node {
    int contribution;
    int salary;
    int visited;
    int index;
    Edge* edges;
    int num_edges;
} Node;

// Function to compare two nodes based on their contribution degrees
int compare_nodes(const void* a, const void* b) {
    Node* node_a = (Node*)a;
    Node* node_b = (Node*)b;
    return node_a->contribution - node_b->contribution;
}

// Function to initialize a node
Node* init_node(int contribution, int index) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->contribution = contribution;
    node->salary = 0;
    node->visited = 0;
    node->index = index;
    node->edges = NULL;
    node->num_edges = 0;
    return node;
}

// Function to add an edge to a node
void add_edge(Node* node, int u, int v) {
    node->num_edges++;
    node->edges = (Edge*)realloc(node->edges, node->num_edges * sizeof(Edge));
    node->edges[node->num_edges - 1].u = u;
    node->edges[node->num_edges - 1].v = v;
}

// Function to perform Depth First Search (DFS) to calculate the salaries
void dfs(Node* nodes, int current, int salary) {
    nodes[current].salary = salary;
    nodes[current].visited = 1;

    for (int i = 0; i < nodes[current].num_edges; i++) {
        int neighbor = nodes[current].edges[i].v;
        if (!nodes[neighbor].visited) {
            if (nodes[current].contribution < nodes[neighbor].contribution) {
                dfs(nodes, neighbor, salary + 1);
            } else {
                dfs(nodes, neighbor, salary);
            }
        }
    }
}

int main() {
    int N, M;
    int c[MAX_N];
    Edge edges[MAX_M];
    Node nodes[MAX_N];

    // Read the input
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &c[i]);
        nodes[i] = *init_node(c[i], i);
    }

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &edges[i].u, &edges[i].v);
        add_edge(&nodes[edges[i].u - 1], edges[i].u, edges[i].v);
        add_edge(&nodes[edges[i].v - 1], edges[i].v, edges[i].u);
    }

    // Sort the nodes based on their contribution degrees
    qsort(nodes, N, sizeof(Node), compare_nodes);

    // Perform DFS to calculate the salaries
    for (int i = 0; i < N; i++) {
        if (!nodes[i].visited) {
            dfs(nodes, i, 1);
        }
    }

    // Calculate and print the total salary
    int total_salary = 0;
    for (int i = 0; i < N; i++) {
        total_salary += nodes[i].salary;
    }

    printf("%d\n", total_salary);

    // Free the allocated memory
    for (int i = 0; i < N; i++) {
        free(nodes[i].edges);
        free(&nodes[i]);
    }

    return 0;
}