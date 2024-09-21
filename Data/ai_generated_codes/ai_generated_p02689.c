#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define MAX_M 100000

// Structure to represent a road
typedef struct {
    int a;
    int b;
} Road;

// Function to check if an observatory is good
int is_good(int n, int m, int h[], Road roads[], int obs) {
    // Check if the observatory can reach any other observatory
    for (int i = 0; i < m; i++) {
        if (roads[i].a == obs || roads[i].b == obs) {
            // Find the other observatory connected to the current observatory
            int other_obs = (roads[i].a == obs) ? roads[i].b : roads[i].a;

            // If the elevation of the current observatory is not higher than the other observatory, it's not good
            if (h[obs] <= h[other_obs]) {
                return 0;
            }
        }
    }

    // If no other observatory can be reached from the current observatory, it's good
    return 1;
}

int main() {
    int n, m;
    int h[MAX_N];
    Road roads[MAX_M];
    int good_observatories = 0;

    // Read input
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &roads[i].a, &roads[i].b);
    }

    // Check each observatory if it's good
    for (int i = 0; i < n; i++) {
        if (is_good(n, m, h, roads, i)) {
            good_observatories++;
        }
    }

    // Print the number of good observatories
    printf("%d\n", good_observatories);

    return 0;
}