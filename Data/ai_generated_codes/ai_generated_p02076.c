#include <stdio.h>
#include <stdlib.h>

// Structure to represent a rook
typedef struct {
    int x;
    int y;
} Rook;

// Function to calculate the minimum number of captured rooks
int minCapturedRooks(Rook *rooks, int n, int m) {
    // Sort rooks by their x-coordinate
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if (rooks[i].x > rooks[j].x) {
                Rook temp = rooks[i];
                rooks[i] = rooks[j];
                rooks[j] = temp;
            }
        }
    }

    // Calculate the minimum number of captured rooks
    int minCaptured = 0;
    int lastY = 0;
    for (int i = 0; i < m; i++) {
        if (rooks[i].y > lastY) {
            minCaptured++;
            lastY = rooks[i].y;
        }
    }

    return minCaptured;
}

// Function to calculate the maximum number of captured rooks
int maxCapturedRooks(Rook *rooks, int n, int m) {
    // Sort rooks by their y-coordinate
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if (rooks[i].y > rooks[j].y) {
                Rook temp = rooks[i];
                rooks[i] = rooks[j];
                rooks[j] = temp;
            }
        }
    }

    // Calculate the maximum number of captured rooks
    int maxCaptured = 0;
    int lastX = 0;
    for (int i = 0; i < m; i++) {
        if (rooks[i].x > lastX) {
            maxCaptured++;
            lastX = rooks[i].x;
        }
    }

    return maxCaptured;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Allocate memory for the rooks
    Rook *rooks = (Rook *)malloc(sizeof(Rook) * m);

    // Read the rook positions
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &rooks[i].x, &rooks[i].y);
    }

    // Calculate the minimum and maximum number of captured rooks
    int minCaptured = minCapturedRooks(rooks, n, m);
    int maxCaptured = maxCapturedRooks(rooks, n, m);

    // Print the results
    printf("%d %d\n", minCaptured, maxCaptured);

    // Free the allocated memory
    free(rooks);

    return 0;
}