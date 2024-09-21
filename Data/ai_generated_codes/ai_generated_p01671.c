#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define MAX_M 200000
#define INF 1000000000

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX_M];
int parent[MAX_N];

int find(int x) {
    if (parent[x] == x) {
        return x;
    } else {
        return parent[x] = find(parent[x]);
    }
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        parent[x] = y;
    }
}

int kruskal(int n, int m, int skip) {
    int i, j, cost = 0, count = 0;
    for (i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    // Sort edges in ascending order of weight
    for (i = 0; i < m; ++i) {
        for (j = i + 1; j < m; ++j) {
            if (edges[i].w > edges[j].w) {
                Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }

    // Iterate through the sorted edges
    for (i = 0; i < m; ++i) {
        if (i == skip) {
            continue;
        }

        int u = edges[i].u;
        int v = edges[i].v;

        // If the edge does not create a cycle, add it to the MST
        if (find(u) != find(v)) {
            unite(u, v);
            cost += edges[i].w;
            count++;
        }

        // If all nodes are connected, the MST is complete
        if (count == n - 1) {
            break;
        }
    }

    // If all nodes are not connected, there is no MST
    if (count != n - 1) {
        return -1;
    }

    return cost;
}

int main() {
    int n, m, i;
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; ++i) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    // Calculate the cost of the MST for each edge removal
    for (i = 0; i < m; ++i) {
        printf("%d\n", kruskal(n, m, i));
    }

    return 0;
}