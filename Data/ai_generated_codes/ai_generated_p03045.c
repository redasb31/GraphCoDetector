#include <stdio.h>
#include <stdlib.h>

// Structure to store the information about each card
typedef struct Card {
    int x;
    int y;
    int z;
} Card;

// Function to find the minimum cost to determine all card values
int findMinCost(Card *cards, int n, int m) {
    // Create a union-find data structure to track connected cards
    int *parent = (int *)malloc(sizeof(int) * (n + 1));
    int *rank = (int *)malloc(sizeof(int) * (n + 1));

    // Initialize the union-find data structure
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    // Connect cards based on the given information
    for (int i = 0; i < m; i++) {
        int x = cards[i].x;
        int y = cards[i].y;
        int z = cards[i].z;

        // If the sum of values on cards x and y is even, connect them in the union-find data structure
        if (z % 2 == 0) {
            union_find(x, y, parent, rank);
        }
    }

    // Count the number of connected components
    int num_components = 0;
    for (int i = 1; i <= n; i++) {
        if (parent[i] == i) {
            num_components++;
        }
    }

    // The minimum cost is the number of connected components minus 1
    int min_cost = num_components - 1;

    // Free the allocated memory
    free(parent);
    free(rank);

    return min_cost;
}

// Union-find function to connect two cards
void union_find(int x, int y, int *parent, int *rank) {
    int x_root = find_root(x, parent);
    int y_root = find_root(y, parent);

    // If x and y belong to different sets, connect them
    if (x_root != y_root) {
        if (rank[x_root] > rank[y_root]) {
            parent[y_root] = x_root;
        } else if (rank[x_root] < rank[y_root]) {
            parent[x_root] = y_root;
        } else {
            parent[y_root] = x_root;
            rank[x_root]++;
        }
    }
}

// Find the root of the set containing a given card
int find_root(int x, int *parent) {
    while (parent[x] != x) {
        x = parent[x];
    }
    return x;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Read the card information
    Card *cards = (Card *)malloc(sizeof(Card) * m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &cards[i].x, &cards[i].y, &cards[i].z);
    }

    // Find the minimum cost
    int min_cost = findMinCost(cards, n, m);

    // Print the minimum cost
    printf("%d\n", min_cost);

    // Free the allocated memory
    free(cards);

    return 0;
}