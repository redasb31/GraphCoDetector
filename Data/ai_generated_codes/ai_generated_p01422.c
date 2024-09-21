#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to find the minimum of two doubles
double min(double a, double b) {
    return (a < b) ? a : b;
}

// Function to calculate the confusion ratio for a single coin
double confusionRatio(int a, int b) {
    return (double) abs(a - b) / a;
}

// Function to find the optimal values for the coins to minimize the maximum confusion ratio
double findOptimalValues(int *a, int n) {
    // Sort the coins in ascending order
    qsort(a, n, sizeof(int), (int(*)(const void*, const void*))  
            (int) (a - b));

    // Initialize the optimal values
    int *b = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }

    // Calculate the optimal values for each coin
    for (int i = 1; i < n; i++) {
        // The optimal value for the i-th coin is the smallest multiple of the (i-1)-th coin that is greater than or equal to the original value of the i-th coin
        b[i] = ceil((double) b[i] / b[i - 1]) * b[i - 1];
    }

    // Calculate the maximum confusion ratio
    double maxConfusionRatio = 0;
    for (int i = 0; i < n; i++) {
        maxConfusionRatio = max(maxConfusionRatio, confusionRatio(a[i], b[i]));
    }

    // Free the allocated memory
    free(b);

    // Return the minimum of the maximum confusion ratio
    return maxConfusionRatio;
}

int main() {
    int n;
    scanf("%d", &n);

    int *a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Calculate the minimum of the maximum confusion ratio
    double minMaxConfusionRatio = findOptimalValues(a, n);

    // Print the result
    printf("%.9lf\n", minMaxConfusionRatio);

    // Free the allocated memory
    free(a);

    return 0;
}