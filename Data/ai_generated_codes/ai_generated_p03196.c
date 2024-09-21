#include <stdio.h>
#include <math.h>

// Function to calculate the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    // Input the number of integers (N) and their product (P)
    long long int N, P;
    scanf("%lld %lld", &N, &P);

    // Calculate the maximum possible GCD
    long long int maxGCD = 1;
    for (long long int i = 2; i * i <= P; i++) {
        // If 'i' is a factor of P, find the maximum power of 'i' that divides P
        if (P % i == 0) {
            long long int power = 0;
            while (P % i == 0) {
                P /= i;
                power++;
            }
            // Update the maximum GCD by multiplying with the highest power of 'i' that divides P
            maxGCD = maxGCD * pow(i, power / N); 
        }
    }

    // If P is not 1, it means there is a prime factor larger than the square root of P
    if (P != 1) {
        maxGCD = maxGCD * P;
    }

    // Print the maximum possible GCD
    printf("%lld\n", maxGCD);

    return 0;
}