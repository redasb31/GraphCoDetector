#include <stdio.h>
#define MOD 998244353

// Structure to represent a segment tree node
struct Node {
    long long sum; // Sum of elements in the segment
    long long lazy; // Lazy propagation value
};

// Function to create a new segment tree node
struct Node newNode(long long sum, long long lazy) {
    struct Node node;
    node.sum = sum;
    node.lazy = lazy;
    return node;
}

// Function to build the segment tree
struct Node* build(long long *arr, int start, int end, struct Node *tree, int index) {
    if (start == end) {
        tree[index] = newNode(arr[start], 0);
        return &tree[index];
    }

    int mid = (start + end) / 2;
    tree[index] = newNode(0, 0);
    build(arr, start, mid, tree, 2 * index + 1);
    build(arr, mid + 1, end, tree, 2 * index + 2);
    tree[index].sum = (tree[2 * index + 1].sum + tree[2 * index + 2].sum) % MOD;
    return &tree[index];
}

// Function to update the lazy propagation value for a node
void propagate(struct Node *node, int start, int end) {
    if (node->lazy != 0) {
        node->sum = (node->lazy * ((end - start + 1) % MOD) + node->sum) % MOD;
        if (start != end) {
            node->left->lazy = ((node->left->lazy * node->lazy) % MOD + node->lazy) % MOD;
            node->right->lazy = ((node->right->lazy * node->lazy) % MOD + node->lazy) % MOD;
        }
        node->lazy = 0;
    }
}

// Function to update the segment tree for a given range
void update(struct Node *tree, int start, int end, int l, int r, long long b, long long c, int index) {
    propagate(&tree[index], start, end);

    if (start > r || end < l) {
        return;
    }

    if (start >= l && end <= r) {
        tree[index].lazy = ((tree[index].lazy * b) % MOD + c) % MOD;
        propagate(&tree[index], start, end);
        return;
    }

    int mid = (start + end) / 2;
    update(tree, start, mid, l, r, b, c, 2 * index + 1);
    update(tree, mid + 1, end, l, r, b, c, 2 * index + 2);
    tree[index].sum = (tree[2 * index + 1].sum + tree[2 * index + 2].sum) % MOD;
}

// Function to query the sum of elements in a given range
long long query(struct Node *tree, int start, int end, int l, int r, int index) {
    propagate(&tree[index], start, end);

    if (start > r || end < l) {
        return 0;
    }

    if (start >= l && end <= r) {
        return tree[index].sum;
    }

    int mid = (start + end) / 2;
    return (query(tree, start, mid, l, r, 2 * index + 1) + query(tree, mid + 1, end, l, r, 2 * index + 2)) % MOD;
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);

    long long arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }

    // Allocate memory for the segment tree
    int treeSize = 4 * N;
    struct Node *tree = (struct Node *)malloc(treeSize * sizeof(struct Node));

    // Build the segment tree
    build(arr, 0, N - 1, tree, 0);

    // Process queries
    for (int i = 0; i < Q; i++) {
        int type, l, r, b, c;
        scanf("%d %d %d", &type, &l, &r);

        if (type == 0) {
            scanf("%d %d", &b, &c);
            update(tree, 0, N - 1, l, r - 1, b, c, 0);
        } else {
            long long ans = query(tree, 0, N - 1, l, r - 1, 0);
            printf("%lld\n", ans);
        }
    }

    free(tree);

    return 0;
}