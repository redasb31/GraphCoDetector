#include <stdio.h>

// Function to calculate the greatest common divisor (GCD) of two integers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to calculate the sum of GCDs for all combinations of (a, b, c)
long long calculate_sum_gcd(int K) {
    long long sum = 0;
    // Iterate through all possible values of a, b, and c
    for (int a = 1; a <= K; a++) {
        for (int b = 1; b <= K; b++) {
            for (int c = 1; c <= K; c++) {
                // Calculate the GCD of a, b, and c
                int gcd_abc = gcd(gcd(a, b), c);
                // Add the GCD to the sum
                sum += gcd_abc;
            }
        }
    }
    return sum;
}

int main() {
    int K;
    // Read the value of K from the input
    scanf("%d", &K);
    // Calculate the sum of GCDs
    long long result = calculate_sum_gcd(K);
    // Print the result
    printf("%lld\n", result);
    return 0;
}