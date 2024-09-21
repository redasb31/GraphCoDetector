#include <stdio.h>

// Function to calculate the greatest common divisor (GCD) using Euclid's algorithm
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to calculate the least common multiple (LCM) of two numbers
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int n, i;
    scanf("%d", &n); // Read the number of integers

    int numbers[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]); // Read the integers
    }

    // Calculate the LCM iteratively
    int lcm_result = numbers[0];
    for (i = 1; i < n; i++) {
        lcm_result = lcm(lcm_result, numbers[i]);
    }

    printf("%d\n", lcm_result); // Print the LCM
    return 0;
}