#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353

typedef struct {
    int x, y;
} Point;

int compare_x(const void *a, const void *b) {
    return ((Point *)a)->x - ((Point *)b)->x;
}

int compare_y(const void *a, const void *b) {
    return ((Point *)a)->y - ((Point *)b)->y;
}

long long count_subsets(int n) {
    // Calculate 2^n - 1 (number of non-empty subsets)
    long long count = 1;
    for (int i = 1; i <= n; i++) {
        count = (count * 2) % MOD;
    }
    return (count - 1) % MOD;
}

int main() {
    int n;
    scanf("%d", &n);

    Point *points = malloc(n * sizeof(Point));

    // Read input points
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    // Sort points by x-coordinate
    qsort(points, n, sizeof(Point), compare_x);

    long long total_sum = 0;

    // For each point, calculate the number of subsets it contributes to
    for (int i = 0; i < n; i++) {
        // Find the leftmost and rightmost points with the same y-coordinate
        int left = i, right = i;
        while (right < n && points[right].y == points[i].y) {
            right++;
        }

        // Calculate the number of subsets containing the current point
        long long subset_count = count_subsets(right - left);

        // Add the contribution of the current point to the total sum
        total_sum = (total_sum + subset_count * (right - left)) % MOD;
    }

    // Sort points by y-coordinate
    qsort(points, n, sizeof(Point), compare_y);

    // Repeat the process for y-coordinate
    for (int i = 0; i < n; i++) {
        int left = i, right = i;
        while (right < n && points[right].x == points[i].x) {
            right++;
        }

        long long subset_count = count_subsets(right - left);
        total_sum = (total_sum + subset_count * (right - left)) % MOD;
    }

    printf("%lld\n", total_sum);

    free(points);
    return 0;
}