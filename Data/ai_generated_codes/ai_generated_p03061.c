#include <stdio.h>

// Function to calculate the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int N; // Number of integers
    scanf("%d", &N);

    int A[N]; // Array to store the integers
    int max_gcd = 1; // Initialize the maximum GCD to 1

    // Read the integers from input
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        // Update the maximum GCD after reading each integer
        max_gcd = gcd(max_gcd, A[i]);
    }

    // Find the maximum possible GCD after one replacement
    for (int i = 1; i <= 1000000000; i++) {
        // Calculate the GCD with each integer and update max_gcd
        for (int j = 0; j < N; j++) {
            max_gcd = gcd(max_gcd, gcd(i, A[j]));
        }
    }

    printf("%d\n", max_gcd);

    return 0;
}