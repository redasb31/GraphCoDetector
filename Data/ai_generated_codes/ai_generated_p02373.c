#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100000

// Structure for a node in the tree
typedef struct Node {
    int id;
    int num_children;
    int children[MAX_NODES];
} Node;

// Structure for a linked list to store the path from root to a node
typedef struct Path {
    int node_id;
    struct Path *next;
} Path;

// Function to create a new node
Node *create_node(int id) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->id = id;
    node->num_children = 0;
    return node;
}

// Function to create a new path element
Path *create_path(int node_id) {
    Path *path = (Path *)malloc(sizeof(Path));
    path->node_id = node_id;
    path->next = NULL;
    return path;
}

// Function to insert a child to a node
void insert_child(Node *parent, int child_id) {
    parent->children[parent->num_children++] = child_id;
}

// Function to find the LCA of two nodes
int find_lca(Node *tree[], Path *path1, Path *path2) {
    int lca = -1;
    while (path1 != NULL && path2 != NULL) {
        if (path1->node_id == path2->node_id) {
            lca = path1->node_id;
            path1 = path1->next;
            path2 = path2->next;
        } else {
            path1 = path1->next;
            path2 = path2->next;
        }
    }
    return lca;
}

// Function to find the path from root to a given node
Path *find_path(Node *tree[], int node_id) {
    Path *path = NULL;
    int current_node = node_id;
    while (current_node != -1) {
        Path *new_path = create_path(current_node);
        new_path->next = path;
        path = new_path;
        current_node = tree[current_node]->id;
    }
    return path;
}

int main() {
    int n, q, u, v;
    Node *tree[MAX_NODES];
    // Read the number of nodes
    scanf("%d", &n);

    // Initialize the tree
    for (int i = 0; i < n; i++) {
        tree[i] = create_node(i);
    }

    // Read the tree structure
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int child;
            scanf("%d", &child);
            insert_child(tree[i], child);
        }
    }

    // Read the number of queries
    scanf("%d", &q);

    // Process each query
    for (int i = 0; i < q; i++) {
        // Read the nodes for the query
        scanf("%d %d", &u, &v);

        // Find the paths from root to the two nodes
        Path *path1 = find_path(tree, u);
        Path *path2 = find_path(tree, v);

        // Find the LCA of the two nodes
        int lca = find_lca(tree, path1, path2);

        // Print the LCA
        printf("%d\n", lca);

        // Free the paths
        while (path1 != NULL) {
            Path *temp = path1;
            path1 = path1->next;
            free(temp);
        }
        while (path2 != NULL) {
            Path *temp = path2;
            path2 = path2->next;
            free(temp);
        }
    }

    // Free the tree
    for (int i = 0; i < n; i++) {
        free(tree[i]);
    }

    return 0;
}