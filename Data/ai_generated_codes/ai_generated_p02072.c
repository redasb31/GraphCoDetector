#include <stdio.h>
#include <math.h>

// Structure to represent a base
typedef struct {
    double x, y;
} Base;

// Function to calculate the distance between two points
double distance(Base a, Base b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Function to find the optimal headquarters location
double findOptimalHeadquarters(Base bases[], int N, int K) {
    // Sort the bases in ascending order of their x-coordinates
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (bases[i].x > bases[j].x) {
                Base temp = bases[i];
                bases[i] = bases[j];
                bases[j] = temp;
            }
        }
    }

    // Calculate the sum of distances for all possible headquarters locations
    double minSum = INFINITY;
    for (int i = 0; i <= N - K; i++) {
        double sum = 0;
        // Consider the K bases with the largest x-coordinates
        for (int j = i + K - 1; j < i + K; j++) {
            sum += distance(bases[j], bases[i]);
        }
        // Update the minimum sum
        minSum = fmin(minSum, sum);
    }

    return minSum;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    Base bases[N];
    for (int i = 0; i < N; i++) {
        scanf("%lf %lf", &bases[i].x, &bases[i].y);
    }

    double result = findOptimalHeadquarters(bases, N, K);
    printf("%.5lf\n", result);

    return 0;
}