#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to calculate the XOR of two integers
long long int xor(long long int a, long long int b) {
    return a ^ b;
}

int main() {
    long long int n, *a, sum = 0;
    
    // Input the number of integers
    scanf("%lld", &n);

    // Allocate memory for the array of integers
    a = (long long int *)malloc(n * sizeof(long long int));

    // Input the integers
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    // Calculate the sum of XORs
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            sum = (sum + xor(a[i], a[j])) % MOD;
        }
    }

    // Print the sum modulo (10^9+7)
    printf("%lld\n", sum);

    // Free the allocated memory
    free(a);

    return 0;
}