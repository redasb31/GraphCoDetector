#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353

// Function to calculate the number of operations required to return to the original value
long long operations(long long k, int N) {
    long long original = k;
    long long count = 0;

    while (1) {
        // If the number is odd, subtract 1 and divide by 2
        if (k % 2) {
            k = (k - 1) / 2;
        } 
        // Otherwise, divide by 2 and add 2^N - 1
        else {
            k = (k / 2) + (1LL << N) - 1;
        }
        count++;
        // Check if the number has returned to the original value
        if (k == original) {
            return count;
        }
    }
    return 0; // This line is unreachable, but it's good practice to have a default return value
}

int main() {
    int N;
    long long X, sum = 0, k;

    // Input N and X
    scanf("%d\n", &N);
    scanf("%lld\n", &X);

    // Iterate from 0 to X and calculate the operations for each value
    for (k = 0; k <= X; k++) {
        sum = (sum + operations(k, N)) % MOD;
    }

    // Print the sum of the operations
    printf("%lld\n", sum);

    return 0;
}