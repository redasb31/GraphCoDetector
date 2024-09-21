#include <stdio.h>

// Function to calculate the number of valid windows for a given query
int count_windows(int *arr, int n, long long x) {
    int l = 0, r = 0;  // Initialize left and right pointers
    long long sum = 0;  // Initialize sum of elements in the window
    int count = 0;  // Initialize count of valid windows

    // Iterate through the array using two pointers
    while (r < n) {
        // Add the current element to the sum
        sum += arr[r];

        // While the sum is greater than the query value, 
        // shrink the window from the left
        while (sum > x && l <= r) {
            sum -= arr[l];
            l++;
        }

        // Count the number of valid windows ending at the current right pointer
        count += (r - l + 1);

        // Move the right pointer to the next element
        r++;
    }

    return count;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int arr[n];  // Array to store the input elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long queries[q];  // Array to store the queries
    for (int i = 0; i < q; i++) {
        scanf("%lld", &queries[i]);
    }

    // Process each query and print the count of valid windows
    for (int i = 0; i < q; i++) {
        printf("%d\n", count_windows(arr, n, queries[i]));
    }

    return 0;
}