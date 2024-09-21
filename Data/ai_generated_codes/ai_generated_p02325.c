#include <stdio.h>
#include <math.h>
#include <limits.h>

#define MAX_N 1000
#define INF (double)INT_MAX

// Structure to represent a point in 2D space
typedef struct {
    double x;
    double y;
} Point;

// Function to calculate the Euclidean distance between two points
double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Function to solve the Bitonic TSP using dynamic programming
double bitonicTSP(Point points[], int n) {
    // Initialize a 2D array to store the minimum distances
    double dp[MAX_N][MAX_N];

    // Initialize the base cases
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }

    // Calculate the distances for the left-to-right path
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            dp[i][j] = dp[i][j - 1] + distance(points[j - 1], points[j]);
        }
    }

    // Calculate the distances for the right-to-left path
    for (int i = n - 1; i > 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            dp[i][j] = dp[i][j + 1] + distance(points[j + 1], points[j]);
        }
    }

    // Find the minimum distance for the entire tour
    double min_distance = INF;
    for (int i = 0; i < n; i++) {
        min_distance = fmin(min_distance, dp[0][i] + dp[n - 1][i]);
    }

    // Return the minimum distance
    return min_distance;
}

int main() {
    int n;
    scanf("%d", &n);

    // Read the input points
    Point points[MAX_N];
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    // Solve the Bitonic TSP and print the result
    double shortest_tour_distance = bitonicTSP(points, n);
    printf("%.8lf\n", shortest_tour_distance);

    return 0;
}