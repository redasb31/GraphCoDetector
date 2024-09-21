#include <stdio.h>
#include <stdlib.h>

// Function to calculate the Nim-sum of an array of integers
long long nim_sum(long long *arr, int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum ^= arr[i];
    }
    return sum;
}

// Function to find the minimum number of stones to move to guarantee Takahashi's win
long long find_min_stones(long long *arr, int n) {
    // Calculate the Nim-sum of the initial piles
    long long initial_nim_sum = nim_sum(arr, n);

    // If the Nim-sum is zero, Takahashi cannot win
    if (initial_nim_sum == 0) {
        return -1;
    }

    // Find the minimum number of stones to move
    long long min_stones = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min_stones) {
            min_stones = arr[i];
        }
    }

    // Check if moving stones from the first pile is sufficient
    long long new_nim_sum = initial_nim_sum ^ arr[0] ^ (arr[0] - min_stones);
    if (new_nim_sum == 0) {
        return min_stones;
    }

    // If moving stones from the first pile is not sufficient, Takahashi cannot win
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);

    long long *arr = malloc(sizeof(long long) * n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    // Find the minimum number of stones to move
    long long min_stones = find_min_stones(arr, n);

    // Print the result
    printf("%lld\n", min_stones);

    free(arr);
    return 0;
}