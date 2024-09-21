#include <stdio.h>

// Function to calculate the greatest common divisor (GCD) of two integers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int N, M;

    // Read the input values N and M
    scanf("%d %d", &N, &M);

    // Find the maximum possible GCD by dividing M by (N - 1)
    int max_gcd = M / (N - 1);

    // Print the maximum possible GCD
    printf("%d\n", max_gcd);

    return 0;
}