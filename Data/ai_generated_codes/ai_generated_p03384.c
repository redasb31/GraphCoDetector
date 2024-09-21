#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

// Structure to represent a node in the tree
typedef struct Node {
    int parent;
    int depth;
    int visited;
    int index; // Index of the node in the permutation
    int degree; // Number of children
    int children[MAX_N];
} Node;

// Structure to represent an edge in the tree
typedef struct Edge {
    int u;
    int v;
} Edge;

// Function to compare two nodes by their index
int compare_nodes(const void *a, const void *b) {
    Node *node1 = (Node *)a;
    Node *node2 = (Node *)b;
    return node1->index - node2->index;
}

// Function to find the parent of a given node
int find_parent(Node *nodes, int node_index) {
    if (nodes[node_index].parent == node_index) {
        return node_index;
    }
    return find_parent(nodes, nodes[node_index].parent);
}

// Function to connect two nodes in the tree
void connect_nodes(Node *nodes, int u, int v) {
    // Find the root of each node
    int root_u = find_parent(nodes, u);
    int root_v = find_parent(nodes, v);

    // Connect the nodes to the root of the tree
    nodes[u].parent = root_v;
    nodes[v].parent = root_v;
}

// Function to perform a Depth First Search (DFS) on the tree
void dfs(Node *nodes, int node_index, int depth) {
    nodes[node_index].depth = depth;
    nodes[node_index].visited = 1;

    // Iterate through the children of the node
    for (int i = 0; i < nodes[node_index].degree; i++) {
        int child_index = nodes[node_index].children[i];

        // If the child is not visited, perform DFS
        if (!nodes[child_index].visited) {
            dfs(nodes, child_index, depth + 1);
        }
    }
}

// Function to check if two trees are isomorphic
int is_isomorphic(Node *tree1, Node *tree2, int n) {
    // Sort the children of each node in ascending order
    for (int i = 1; i <= n; i++) {
        qsort(tree1[i].children, tree1[i].degree, sizeof(int), compare_nodes);
        qsort(tree2[i].children, tree2[i].degree, sizeof(int), compare_nodes);
    }

    // Check if the depth and degree of each node are equal
    for (int i = 1; i <= n; i++) {
        if (tree1[i].depth != tree2[i].depth || tree1[i].degree != tree2[i].degree) {
            return 0;
        }
        // Check if the children of each node are the same
        for (int j = 0; j < tree1[i].degree; j++) {
            if (tree1[i].children[j] != tree2[i].children[j]) {
                return 0;
            }
        }
    }

    // If all checks pass, the trees are isomorphic
    return 1;
}

// Function to generate a permutation for a given tree
int generate_permutation(Node *nodes, int *permutation, int n, int current_node, int index) {
    // If the current node is the root
    if (nodes[current_node].parent == current_node) {
        // Set the index of the root node to 1
        permutation[index] = current_node;
        index++;

        // Recursively generate permutation for the children of the root
        for (int i = 0; i < nodes[current_node].degree; i++) {
            index = generate_permutation(nodes, permutation, n, nodes[current_node].children[i], index);
        }
    } else {
        // Set the index of the current node based on its parent's index
        int parent_index = permutation[nodes[current_node].parent - 1];
        permutation[parent_index - 1] = current_node;
        index++;
    }

    return index;
}

int main() {
    int n;
    scanf("%d", &n);

    // Create arrays for nodes and edges
    Node nodes[MAX_N + 1];
    Edge edges[MAX_N];

    // Initialize nodes array
    for (int i = 1; i <= n; i++) {
        nodes[i].parent = i;
        nodes[i].index = i;
        nodes[i].degree = 0;
    }

    // Read the edges of the tree
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &edges[i].u, &edges[i].v);

        // Connect the nodes in the tree
        connect_nodes(nodes, edges[i].u, edges[i].v);

        // Increase the degree of the parent node
        nodes[find_parent(nodes, edges[i].u)].degree++;
    }

    // Find the root of the tree
    int root = 1;
    while (nodes[root].parent != root) {
        root = nodes[root].parent;
    }

    // Perform DFS to determine the depth of each node
    dfs(nodes, root, 0);

    // Create a new tree to store the generated permutation
    Node generated_tree[MAX_N + 1];
    memcpy(generated_tree, nodes, sizeof(Node) * (n + 1));

    // Generate a permutation
    int permutation[MAX_N];
    int index = 1;
    generate_permutation(generated_tree, permutation, n, root, index);

    // Check if the generated tree is isomorphic to the original tree
    if (is_isomorphic(nodes, generated_tree, n)) {
        // Print the permutation
        for (int i = 0; i < n; i++) {
            printf("%d ", permutation[i]);
        }
    } else {
        printf("-1\n");
    }

    return 0;
}