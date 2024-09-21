#include <stdio.h>

// Structure to represent a segment tree node
struct Node {
    int sum;
    int lazy;
};

// Function to create a new segment tree node
struct Node* newNode() {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->sum = 0;
    node->lazy = 0;
    return node;
}

// Function to build the segment tree
struct Node* buildTree(int* arr, int start, int end, int index) {
    // Create a new node
    struct Node* node = newNode();
    // If start == end, this is a leaf node
    if (start == end) {
        node->sum = arr[start];
        return node;
    }
    // Recursively build the left and right subtrees
    int mid = (start + end) / 2;
    node->left = buildTree(arr, start, mid, 2 * index + 1);
    node->right = buildTree(arr, mid + 1, end, 2 * index + 2);
    // Update the sum of the current node
    node->sum = node->left->sum + node->right->sum;
    return node;
}

// Function to propagate lazy updates
void propagate(struct Node* node, int start, int end) {
    // If there is a lazy update to be propagated
    if (node->lazy != 0) {
        // Update the sum of the current node
        node->sum += (end - start + 1) * node->lazy;
        // If this is not a leaf node
        if (start != end) {
            // Propagate the lazy update to the children
            node->left->lazy += node->lazy;
            node->right->lazy += node->lazy;
        }
        // Reset the lazy update
        node->lazy = 0;
    }
}

// Function to update the range [s, t] to value x
void update(struct Node* node, int start, int end, int s, int t, int x) {
    // Propagate lazy updates
    propagate(node, start, end);
    // If the current segment is completely outside the range [s, t]
    if (s > end || t < start) {
        return;
    }
    // If the current segment is completely inside the range [s, t]
    if (start >= s && end <= t) {
        // Update the sum of the current node
        node->sum += (end - start + 1) * x;
        // If this is not a leaf node, propagate the lazy update to the children
        if (start != end) {
            node->lazy += x;
        }
        return;
    }
    // Recursively update the left and right subtrees
    int mid = (start + end) / 2;
    update(node->left, start, mid, s, t, x);
    update(node->right, mid + 1, end, s, t, x);
    // Update the sum of the current node
    node->sum = node->left->sum + node->right->sum;
}

// Function to query the sum of the range [s, t]
int getSum(struct Node* node, int start, int end, int s, int t) {
    // Propagate lazy updates
    propagate(node, start, end);
    // If the current segment is completely outside the range [s, t]
    if (s > end || t < start) {
        return 0;
    }
    // If the current segment is completely inside the range [s, t]
    if (start >= s && end <= t) {
        return node->sum;
    }
    // Recursively query the left and right subtrees
    int mid = (start + end) / 2;
    return getSum(node->left, start, mid, s, t) + getSum(node->right, mid + 1, end, s, t);
}

int main() {
    int n, q, i, type, s, t, x;
    scanf("%d %d", &n, &q);
    int arr[n];
    // Initialize the array with zeros
    for (i = 0; i < n; i++) {
        arr[i] = 0;
    }
    // Build the segment tree
    struct Node* root = buildTree(arr, 0, n - 1, 0);
    // Process queries
    for (i = 0; i < q; i++) {
        scanf("%d %d %d", &type, &s, &t);
        // Update query
        if (type == 0) {
            scanf("%d", &x);
            update(root, 0, n - 1, s, t, x);
        }
        // Get sum query
        else if (type == 1) {
            printf("%d\n", getSum(root, 0, n - 1, s, t));
        }
    }
    return 0;
}