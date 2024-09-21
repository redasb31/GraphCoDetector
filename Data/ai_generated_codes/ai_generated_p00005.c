#include <stdio.h>

// Function to calculate the greatest common divisor (GCD) using Euclid's algorithm
int gcd(int a, int b) {
    // If b is 0, then a is the GCD
    if (b == 0) {
        return a;
    }
    // Recursively call gcd with b and the remainder of a divided by b
    return gcd(b, a % b);
}

// Function to calculate the least common multiple (LCM)
int lcm(int a, int b) {
    // LCM(a, b) = (a * b) / GCD(a, b)
    return (a * b) / gcd(a, b);
}

int main() {
    int a, b;
    // Loop until EOF is reached
    while (scanf("%d %d", &a, &b) != EOF) {
        // Calculate and print the GCD and LCM
        printf("%d %d\n", gcd(a, b), lcm(a, b));
    }
    return 0;
}