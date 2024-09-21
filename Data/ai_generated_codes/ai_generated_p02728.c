#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

typedef struct Node {
    int val;
    int degree;
    struct Node *parent;
    struct Node *children[200000];
} Node;

Node *createNode(int val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->degree = 0;
    node->parent = NULL;
    for (int i = 0; i < 200000; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void addEdge(Node *node1, Node *node2) {
    node1->children[node1->degree] = node2;
    node1->degree++;
    node2->parent = node1;
}

long long int dfs(Node *node) {
    if (node->degree == 0) {
        return 1;
    }

    long long int result = 1;
    for (int i = 0; i < node->degree; i++) {
        result = (result * dfs(node->children[i])) % MOD;
    }

    return result;
}

int main() {
    int N;
    scanf("%d", &N);

    Node *nodes[200000];
    for (int i = 0; i < N; i++) {
        nodes[i] = createNode(i + 1);
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(nodes[a - 1], nodes[b - 1]);
        addEdge(nodes[b - 1], nodes[a - 1]);
    }

    for (int i = 0; i < N; i++) {
        long long int count = 1;
        // Remove the edge connecting the current node to its parent
        if (nodes[i]->parent != NULL) {
            for (int j = 0; j < nodes[i]->parent->degree; j++) {
                if (nodes[i]->parent->children[j] == nodes[i]) {
                    nodes[i]->parent->children[j] = nodes[i]->parent->children[nodes[i]->parent->degree - 1];
                    nodes[i]->parent->degree--;
                    break;
                }
            }
        }

        // Calculate the number of ways to number the vertices
        count = dfs(nodes[i]);

        // Restore the removed edge
        if (nodes[i]->parent != NULL) {
            nodes[i]->parent->children[nodes[i]->parent->degree] = nodes[i];
            nodes[i]->parent->degree++;
        }

        printf("%lld\n", count);
    }

    return 0;
}