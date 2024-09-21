#include <stdio.h>
#include <stdlib.h>

// Function to check if a number is consecutive and increasing
int isConsecutiveIncreasing(int num) {
    int prevDigit = -1;
    while (num > 0) {
        int digit = num % 10;
        if (prevDigit != -1 && digit != prevDigit + 1) {
            return 0;
        }
        prevDigit = digit;
        num /= 10;
    }
    return 1;
}

// Function to find the largest product of two consecutive increasing numbers
int findLargestProduct(int* arr, int n) {
    int maxProduct = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int product = arr[i] * arr[j];
            if (isConsecutiveIncreasing(product) && product > maxProduct) {
                maxProduct = product;
            }
        }
    }
    return maxProduct;
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int maxProduct = findLargestProduct(arr, n);
    printf("%d\n", maxProduct);

    free(arr);
    return 0;
}