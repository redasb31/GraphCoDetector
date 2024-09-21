#include <stdio.h>
#include <stdlib.h>

// Function to check if two numbers have a common prime factor
int hasCommonPrimeFactor(int a, int b) {
    // Check if both numbers are divisible by 2
    if (a % 2 == 0 && b % 2 == 0) {
        return 1;
    }

    // Check for other prime factors up to the square root of the smaller number
    int smaller = (a < b) ? a : b;
    for (int i = 3; i * i <= smaller; i += 2) {
        if (a % i == 0 && b % i == 0) {
            return 1;
        }
    }

    // If no common prime factor is found
    return 0;
}

// Function to check if the sequence is coprime-sortable
int isCoprimeSortable(int *arr, int n) {
    // Check if the sequence is already sorted
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }

    // Iterate through the sequence and check for swaps
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Swap if elements have a common prime factor
            if (hasCommonPrimeFactor(arr[i], arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                // Check if the sequence is sorted after swapping
                for (int k = 0; k < n - 1; k++) {
                    if (arr[k] > arr[k + 1]) {
                        return 0;
                    }
                }
            }
        }
    }

    // If all swaps are valid and the sequence is sorted
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Check if the sequence is coprime-sortable
    int isSortable = isCoprimeSortable(arr, n);

    // Output the result
    printf("%d\n", isSortable);

    free(arr);
    return 0;
}