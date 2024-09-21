#include <stdio.h>

// Define the maximum size of the array
#define MAX_N 100000

// Structure to represent a segment tree node
struct Node {
    int sum;
};

// Array to store the elements of the sequence
int a[MAX_N];

// Segment tree
struct Node tree[4 * MAX_N];

// Function to build the segment tree
void build(int node, int start, int end) {
    // If the segment is a single element
    if (start == end) {
        tree[node].sum = a[start];
        return;
    }

    // Calculate the middle index
    int mid = (start + end) / 2;

    // Recursively build the left and right subtrees
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);

    // Update the sum of the current node
    tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;
}

// Function to update the segment tree
void update(int node, int start, int end, int s, int t, int x) {
    // If the segment is outside the range to be updated
    if (start > t || end < s) {
        return;
    }

    // If the segment is completely within the range to be updated
    if (start >= s && end <= t) {
        tree[node].sum += (t - s + 1) * x;
        return;
    }

    // Calculate the middle index
    int mid = (start + end) / 2;

    // Recursively update the left and right subtrees
    update(2 * node, start, mid, s, t, x);
    update(2 * node + 1, mid + 1, end, s, t, x);

    // Update the sum of the current node
    tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;
}

// Function to query the segment tree
int query(int node, int start, int end, int s, int t) {
    // If the segment is outside the range to be queried
    if (start > t || end < s) {
        return 0;
    }

    // If the segment is completely within the range to be queried
    if (start >= s && end <= t) {
        return tree[node].sum;
    }

    // Calculate the middle index
    int mid = (start + end) / 2;

    // Recursively query the left and right subtrees
    return query(2 * node, start, mid, s, t) + query(2 * node + 1, mid + 1, end, s, t);
}

int main() {
    int n, q, type, s, t, x;

    // Read the input
    scanf("%d %d", &n, &q);

    // Build the segment tree
    build(1, 1, n);

    // Process each query
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d", &type, &s, &t);

        if (type == 0) {
            // Add operation
            scanf("%d", &x);
            update(1, 1, n, s, t, x);
        } else {
            // GetSum operation
            printf("%d\n", query(1, 1, n, s, t));
        }
    }

    return 0;
}