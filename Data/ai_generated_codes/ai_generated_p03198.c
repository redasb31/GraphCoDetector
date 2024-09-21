#include <stdio.h>
#include <stdlib.h>

// Function to calculate the minimum operations required to make the array sorted in ascending order.
// Returns -1 if it's impossible to sort the array.
int minOperations(int *arr, int n) {
    int operations = 0;
    int i;

    // Iterate through the array from the end
    for (i = n - 1; i > 0; i--) {
        // If the current element is less than the previous element
        if (arr[i] < arr[i - 1]) {
            // Calculate the number of operations needed to make the current element greater than or equal to the previous element
            int diff = abs(arr[i - 1] - arr[i]) + 1;

            // If the current element is negative, we need to multiply it by -2 until it becomes positive.
            if (arr[i] < 0) {
                operations += (diff / 2) + (diff % 2); // Add the number of operations needed to make the element positive
            } else {
                operations += diff; // Add the number of operations needed to make the element greater than or equal to the previous element
            }
            // Update the current element after applying the operations
            arr[i] = arr[i - 1] + (diff % 2 ? diff - 1 : diff);
        } else if (arr[i] == arr[i - 1]) {
            // If the current element is equal to the previous element, we can simply skip it
            continue;
        } else {
            // If the current element is greater than the previous element, we need to check if it's possible to sort the array
            return -1; // It's impossible to sort the array in this case
        }
    }

    return operations;
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(sizeof(int) * n);

    // Read the array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate the minimum operations required
    int operations = minOperations(arr, n);

    // Print the result
    printf("%d\n", operations);

    free(arr);

    return 0;
}