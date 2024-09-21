#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum possible value of the final element
int max_final_element(int *arr, int n) {
    // If the sequence has only one element, return that element
    if (n == 1) {
        return arr[0];
    }

    // If the sequence has two elements, return the sum of those elements
    if (n == 2) {
        return arr[0] + arr[1];
    }

    // Create a new array to store the maximum possible values of the final element for all subarrays
    int *max_values = (int *)malloc(sizeof(int) * n);

    // Initialize the first two elements of the max_values array
    max_values[0] = arr[0];
    max_values[1] = arr[0] + arr[1];

    // Iterate over the remaining elements of the array
    for (int i = 2; i < n; i++) {
        // Calculate the maximum possible value of the final element for the current subarray
        max_values[i] = max(max_values[i - 1], max_values[i - 2] + arr[i]);
    }

    // Return the maximum possible value of the final element for the entire array
    int max_value = max_values[n - 1];

    // Free the memory allocated for the max_values array
    free(max_values);

    return max_value;
}

// Function to find the operations to achieve the maximum value
void find_operations(int *arr, int n, int max_value) {
    // Create a new array to store the operations
    int *operations = (int *)malloc(sizeof(int) * (n - 1));

    // Initialize the number of operations to 0
    int num_operations = 0;

    // Iterate over the array from the end
    for (int i = n - 1; i >= 2; i--) {
        // If the maximum value is equal to the maximum possible value of the final element for the subarray ending at i
        if (max_value == max_values[i]) {
            // Add the operation to the operations array
            operations[num_operations++] = i;

            // Update the maximum value
            max_value = max_values[i - 2];
        }
    }

    // Add the remaining operations to the operations array
    operations[num_operations++] = 1;
    operations[num_operations++] = 2;

    // Print the number of operations
    printf("%d\n", num_operations);

    // Print the operations in reverse order
    for (int i = num_operations - 1; i >= 0; i--) {
        printf("%d\n", operations[i]);
    }

    // Free the memory allocated for the operations array
    free(operations);
}

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find the maximum possible value of the final element
    int max_value = max_final_element(arr, n);

    // Print the maximum possible value
    printf("%d\n", max_value);

    // Find the operations to achieve the maximum value
    find_operations(arr, n, max_value);

    // Free the memory allocated for the array
    free(arr);

    return 0;
}