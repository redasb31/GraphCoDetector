#include <stdio.h>
#include <stdlib.h>

// Function to find the smallest possible difference between the largest and smallest removed elements
int findMinDifference(int *A, int N, int K, int Q) {
    // Create a min-heap to store the minimum element of each subsequence of length K
    int *minHeap = (int *)malloc(sizeof(int) * (N - K + 1));
    for (int i = 0; i < N - K + 1; i++) {
        minHeap[i] = A[i];
        for (int j = 1; j < K; j++) {
            if (A[i + j] < minHeap[i]) {
                minHeap[i] = A[i + j];
            }
        }
    }

    // Sort the min-heap in ascending order
    qsort(minHeap, N - K + 1, sizeof(int), (int(*)(const void *, const void *))minHeapCompare);

    // Find the smallest and largest elements removed
    int minRemoved = minHeap[0];
    int maxRemoved = minHeap[Q - 1];

    // Free the allocated memory
    free(minHeap);

    // Return the difference between the largest and smallest removed elements
    return maxRemoved - minRemoved;
}

// Comparison function for the min-heap
int minHeapCompare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N, K, Q;
    scanf("%d %d %d", &N, &K, &Q);

    // Read the integer sequence A
    int *A = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Find the smallest possible difference
    int minDifference = findMinDifference(A, N, K, Q);

    // Print the result
    printf("%d\n", minDifference);

    // Free the allocated memory
    free(A);

    return 0;
}