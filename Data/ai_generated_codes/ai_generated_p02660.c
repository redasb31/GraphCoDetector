// This program finds the maximum number of times a given operation can be applied to a positive integer.
// The operation involves repeatedly dividing the integer by a prime power that divides it.

#include <stdio.h>
#include <math.h>

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) {
        return 0; // 0 and 1 are not prime
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0; // Not prime if divisible by any number from 2 to its square root
        }
    }
    return 1; // Prime if not divisible by any number from 2 to its square root
}

// Function to find the maximum number of operations
int maxOperations(long long N) {
    int count = 0; // Initialize operation count

    // Iterate over potential prime powers
    for (long long i = 2; i <= N; i++) {
        if (isPrime(i)) { // Check if i is prime
            long long power = 1;
            while (pow(i, power) <= N) {
                if (N % pow(i, power) == 0) {
                    count++; // Increment count if i^power divides N
                    N /= pow(i, power); // Divide N by i^power
                    i = 2; // Reset i to 2 for the next iteration
                    power = 1; // Reset power to 1
                } else {
                    power++; // Increment power if i^power does not divide N
                }
            }
        }
    }
    return count; // Return the total operation count
}

int main() {
    long long N;
    scanf("%lld", &N); // Input the integer N

    printf("%d\n", maxOperations(N)); // Output the maximum number of operations
    return 0;
}