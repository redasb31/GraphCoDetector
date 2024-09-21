#include <stdio.h>
#include <stdlib.h>

// Function to calculate the maximum points achievable
int maxPoints(int *arr, int n) {
    // Create a frequency array to store the count of each number
    int *freq = (int *)calloc(n + 1, sizeof(int));

    // Calculate the frequency of each number in the array
    for (int i = 0; i < 3 * n; i++) {
        freq[arr[i]]++;
    }

    // Initialize the maximum points to 0
    int max_points = 0;

    // Iterate over the frequency array to calculate the maximum points
    for (int i = 1; i <= n; i++) {
        // If the frequency of the current number is greater than or equal to 3, 
        // then we can gain 1 point for every 3 occurrences of that number
        max_points += freq[i] / 3;
    }

    // Free the frequency array
    free(freq);

    // Return the maximum points
    return max_points;
}

int main() {
    // Declare variables for the number of cards and the array of integers
    int n;
    int *arr;

    // Read the number of cards
    scanf("%d", &n);

    // Allocate memory for the array of integers
    arr = (int *)malloc(3 * n * sizeof(int));

    // Read the integers from the input
    for (int i = 0; i < 3 * n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate the maximum points and print the result
    printf("%d\n", maxPoints(arr, n));

    // Free the array
    free(arr);

    return 0;
}