#include <stdio.h>

// Function to add x to the element at index i in the array
void add(int arr[], int i, int x, int n) {
    // Check if the index is within the bounds of the array
    if (i >= 1 && i <= n) {
        arr[i - 1] += x; // Adjust index for 0-based indexing
    }
}

// Function to calculate the sum of elements from index s to t (inclusive)
int getSum(int arr[], int s, int t, int n) {
    // Check if the indices are within the bounds of the array
    if (s >= 1 && s <= n && t >= 1 && t <= n) {
        int sum = 0;
        // Calculate the sum from index s to t (inclusive)
        for (int i = s - 1; i <= t - 1; i++) {
            sum += arr[i]; // Adjust index for 0-based indexing
        }
        return sum;
    }
    return -1; // Return -1 if the indices are invalid
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q); // Read the size of the array and number of queries

    // Create an array of size n initialized with 0s
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = 0;
    }

    // Process each query
    for (int i = 0; i < q; i++) {
        int com, x, y;
        scanf("%d %d %d", &com, &x, &y);

        // Handle add query
        if (com == 0) {
            add(arr, x, y, n);
        }
        // Handle getSum query
        else if (com == 1) {
            int sum = getSum(arr, x, y, n);
            if (sum != -1) {
                printf("%d\n", sum);
            }
        }
    }

    return 0;
}