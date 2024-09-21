#include <stdio.h>
#include <stdlib.h>

// Function to find the median of a sorted array
int find_median(int *arr, int n) {
    // If the array has an odd number of elements, return the middle element
    if (n % 2 != 0) {
        return arr[n / 2];
    }
    // If the array has an even number of elements, return the average of the two middle elements
    else {
        return (arr[n / 2 - 1] + arr[n / 2]) / 2;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    // Allocate memory for the array
    int *a = (int *)malloc(sizeof(int) * n);

    // Read the array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Calculate the median of each subsequence
    int *m = (int *)malloc(sizeof(int) * (n * (n + 1) / 2));
    int m_index = 0;
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            // Create a new array to store the subsequence
            int *subsequence = (int *)malloc(sizeof(int) * (r - l + 1));
            // Copy the subsequence from the original array
            for (int i = l; i <= r; i++) {
                subsequence[i - l] = a[i];
            }
            // Sort the subsequence in ascending order
            qsort(subsequence, r - l + 1, sizeof(int), compare);
            // Find the median of the subsequence and store it in the 'm' array
            m[m_index++] = find_median(subsequence, r - l + 1);
            // Free the memory allocated for the subsequence
            free(subsequence);
        }
    }

    // Sort the 'm' array in ascending order
    qsort(m, (n * (n + 1) / 2), sizeof(int), compare);

    // Find the median of the 'm' array
    int median = find_median(m, (n * (n + 1) / 2));

    // Print the median
    printf("%d\n", median);

    // Free the memory allocated for the arrays
    free(a);
    free(m);

    return 0;
}

// Function to compare two integers for qsort()
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}