#include <stdio.h>
#include <stdlib.h>

#define MAX_N 200000

// Structure to represent a node in the union-find data structure
typedef struct {
    int parent;
    int rank;
} Node;

// Function to initialize the union-find data structure
void init_union_find(Node *nodes, int n) {
    for (int i = 0; i <= n; ++i) {
        nodes[i].parent = i;
        nodes[i].rank = 0;
    }
}

// Function to find the root of the set containing a given node
int find(Node *nodes, int x) {
    if (nodes[x].parent != x) {
        nodes[x].parent = find(nodes, nodes[x].parent);
    }
    return nodes[x].parent;
}

// Function to merge two sets
void merge(Node *nodes, int x, int y) {
    int root_x = find(nodes, x);
    int root_y = find(nodes, y);

    if (root_x == root_y) {
        return;
    }

    if (nodes[root_x].rank < nodes[root_y].rank) {
        nodes[root_x].parent = root_y;
    } else if (nodes[root_x].rank > nodes[root_y].rank) {
        nodes[root_y].parent = root_x;
    } else {
        nodes[root_y].parent = root_x;
        nodes[root_x].rank++;
    }
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);

    // Create a union-find data structure to represent the grid
    Node *nodes = (Node *)malloc((N + 1) * sizeof(Node));
    init_union_find(nodes, N);

    // Initially, all black stones are connected
    for (int i = 2; i <= N - 1; ++i) {
        merge(nodes, i, i - 1);
    }

    // Process each query
    for (int i = 0; i < Q; ++i) {
        int type, x;
        scanf("%d %d", &type, &x);

        // Query type 1: Place a white stone on the top row
        if (type == 1) {
            // Merge the white stone with the black stone below it
            merge(nodes, x, N + x - 1);
        }

        // Query type 2: Place a white stone on the left column
        else if (type == 2) {
            // Merge the white stone with the black stone to the right of it
            merge(nodes, x, N + x - 1);
        }
    }

    // Count the number of black stones
    int black_stones = 0;
    for (int i = 2; i <= N - 1; ++i) {
        if (find(nodes, i) == i) {
            black_stones++;
        }
    }

    // Print the result
    printf("%lld\n", (long long)black_stones * (N - 2));

    free(nodes);

    return 0;
}