#include <stdio.h>
#include <limits.h>

// Function to find the smallest sub-array size (smallest window length) where the elements in the sub-array contains all integers in range [1, 2, ..., K].
int smallestWindow(int arr[], int n, int k) {
    // Create a frequency map to store the count of each element in the array.
    int freq[k + 1] = {0};

    // Initialize the start and end pointers of the window.
    int start = 0, end = 0;
    // Initialize the count of elements found in the window.
    int count = 0;

    // Initialize the minimum window size to infinity.
    int minWindow = INT_MAX;

    // Iterate through the array.
    while (end < n) {
        // If the current element is in the range [1, 2, ..., K], increment its count in the frequency map.
        if (arr[end] >= 1 && arr[end] <= k) {
            freq[arr[end]]++;
            // If the count of the current element is 1, it means we have found a new element in the window.
            if (freq[arr[end]] == 1) {
                count++;
            }
        }

        // While the window contains all the elements in the range [1, 2, ..., K], try to shrink the window from the left side.
        while (count == k) {
            // Update the minimum window size.
            minWindow = (end - start + 1) < minWindow ? (end - start + 1) : minWindow;

            // If the current element at the start pointer is in the range [1, 2, ..., K], decrement its count in the frequency map.
            if (arr[start] >= 1 && arr[start] <= k) {
                freq[arr[start]]--;
                // If the count of the current element becomes 0, it means we have removed an element from the window.
                if (freq[arr[start]] == 0) {
                    count--;
                }
            }
            // Move the start pointer to the right.
            start++;
        }

        // Move the end pointer to the right.
        end++;
    }

    // If no sub-array contains all the elements in the range [1, 2, ..., K], return 0.
    return minWindow == INT_MAX ? 0 : minWindow;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("%d\n", smallestWindow(arr, n, k));
    return 0;
}