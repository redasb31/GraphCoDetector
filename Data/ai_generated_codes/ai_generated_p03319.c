#include <stdio.h>
#include <stdlib.h>

// Function to calculate the minimum number of operations required to make all elements equal
int min_operations(int n, int k, int *a) {
    // Initialize the number of operations to 0
    int operations = 0;

    // Iterate over the sequence in groups of K elements
    for (int i = 0; i < n; i += k) {
        // Find the minimum element in the current group
        int min_element = a[i];
        for (int j = i + 1; j < i + k && j < n; j++) {
            if (a[j] < min_element) {
                min_element = a[j];
            }
        }

        // Count the number of elements in the group that are not equal to the minimum element
        int count = 0;
        for (int j = i; j < i + k && j < n; j++) {
            if (a[j] != min_element) {
                count++;
            }
        }

        // Update the number of operations
        operations += count;
    }

    // Return the minimum number of operations
    return operations;
}

int main() {
    // Input the values of N and K
    int n, k;
    scanf("%d %d", &n, &k);

    // Allocate memory for the sequence A
    int *a = (int *) malloc(n * sizeof(int));

    // Input the sequence A
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Calculate and print the minimum number of operations
    printf("%d\n", min_operations(n, k, a));

    // Free the allocated memory
    free(a);

    return 0;
}