#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 200
#define MAX_EDGES (MAX_NODES - 1)

typedef struct {
    int x, y, z;
} Point;

typedef struct {
    int u, v;
} Edge;

typedef struct {
    Point points[MAX_NODES];
    Edge edges[MAX_EDGES];
    int num_nodes;
} Tree;

// Function to check if two trees are twins
int areTwins(Tree *tree1, Tree *tree2) {
    // If the number of nodes in the trees don't match, they cannot be twins
    if (tree1->num_nodes != tree2->num_nodes) {
        return 0;
    }

    // Create a mapping array to store the correspondence of nodes
    int mapping[MAX_NODES];
    for (int i = 0; i < tree1->num_nodes; i++) {
        mapping[i] = -1;
    }

    // Recursive function to find all possible mappings
    int num_mappings = findMappings(tree1, tree2, mapping, 0);

    return num_mappings;
}

// Recursive function to find all possible mappings
int findMappings(Tree *tree1, Tree *tree2, int mapping[], int node_index) {
    // Base case: all nodes have been mapped
    if (node_index == tree1->num_nodes) {
        return 1;
    }

    // Iterate over all unmapped nodes of the second tree
    int num_mappings = 0;
    for (int i = 0; i < tree2->num_nodes; i++) {
        // Check if this node is already mapped
        if (mapping[i] != -1) {
            continue;
        }

        // Try mapping the current node of the first tree to this node of the second tree
        mapping[i] = node_index;

        // Check if this mapping is valid (i.e., all edges connect corresponding nodes)
        if (isValidMapping(tree1, tree2, mapping)) {
            // Recursively find mappings for the remaining nodes
            num_mappings += findMappings(tree1, tree2, mapping, node_index + 1);
        }

        // Unmap this node for backtracking
        mapping[i] = -1;
    }

    return num_mappings;
}

// Function to check if a mapping is valid
int isValidMapping(Tree *tree1, Tree *tree2, int mapping[]) {
    // Iterate over all edges of the first tree
    for (int i = 0; i < tree1->num_nodes - 1; i++) {
        // Find the corresponding nodes in the second tree based on the mapping
        int u1 = tree1->edges[i].u;
        int v1 = tree1->edges[i].v;
        int u2 = mapping[u1 - 1];
        int v2 = mapping[v1 - 1];

        // Check if the corresponding edge exists in the second tree
        int found = 0;
        for (int j = 0; j < tree2->num_nodes - 1; j++) {
            if ((tree2->edges[j].u == u2 && tree2->edges[j].v == v2) ||
                (tree2->edges[j].u == v2 && tree2->edges[j].v == u2)) {
                found = 1;
                break;
            }
        }

        // If the corresponding edge does not exist, the mapping is invalid
        if (!found) {
            return 0;
        }
    }

    // All edges connect corresponding nodes, so the mapping is valid
    return 1;
}

int main() {
    Tree tree1, tree2;

    // Read the number of nodes
    int n;
    scanf("%d", &n);

    // Read the coordinates of the nodes of the first tree
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &tree1.points[i].x, &tree1.points[i].y, &tree1.points[i].z);
    }

    // Read the edges of the first tree
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &tree1.edges[i].u, &tree1.edges[i].v);
    }

    // Read the coordinates of the nodes of the second tree
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &tree2.points[i].x, &tree2.points[i].y, &tree2.points[i].z);
    }

    // Read the edges of the second tree
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &tree2.edges[i].u, &tree2.edges[i].v);
    }

    // Set the number of nodes for both trees
    tree1.num_nodes = n;
    tree2.num_nodes = n;

    // Check if the trees are twins
    int num_mappings = areTwins(&tree1, &tree2);

    // Print the number of mappings
    printf("%d\n", num_mappings);

    return 0;
}