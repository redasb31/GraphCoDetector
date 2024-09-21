#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to calculate the inversion count of an array
long long mergeSort(int arr[], int temp[], int left, int right) {
    long long inv_count = 0;

    if (left < right) {
        int mid = (left + right) / 2;

        // Recursively sort the two halves
        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);

        // Merge the sorted halves
        inv_count += merge(arr, temp, left, mid, right);
    }

    return inv_count;
}

// Function to merge two sorted subarrays into one sorted array
long long merge(int arr[], int temp[], int left, int mid, int right) {
    long long inv_count = 0;
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1); // Inversion count calculation
        }
    }

    // Copy the remaining elements from the left subarray
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy the remaining elements from the right subarray
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy the merged array back to the original array
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

// Function to perform swap operation on the array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);

    int *A = (int *)malloc(sizeof(int) * N);
    int *temp = (int *)malloc(sizeof(int) * N);

    // Read the input sequence
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Read the operation sequence
    int X[Q], Y[Q];
    for (int i = 0; i < Q; i++) {
        scanf("%d %d", &X[i], &Y[i]);
    }

    // Calculate the sum of inversion counts
    long long total_inversions = 0;
    for (int i = 0; i < (1 << Q); i++) {
        // Apply operations based on the current bit pattern
        for (int j = 0; j < Q; j++) {
            if ((i >> j) & 1) {
                swap(&A[X[j] - 1], &A[Y[j] - 1]);
            }
        }

        // Calculate the inversion count for the current sequence
        total_inversions = (total_inversions + mergeSort(A, temp, 0, N - 1)) % MOD;

        // Reset the array for the next iteration
        for (int j = 0; j < N; j++) {
            A[j] = temp[j];
        }
    }

    printf("%lld\n", total_inversions);

    free(A);
    free(temp);
    return 0;
}