#include <stdio.h>

// Function to calculate the modular exponentiation
long long int mod_pow(long long int base, long long int exponent, long long int modulus) {
    long long int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent /= 2;
    }
    return result;
}

// Function to calculate the number of sets of ramen modulo M
long long int count_ramen_sets(int N, long long int M) {
    // Calculate the number of possible ramen types (2^N)
    long long int total_ramen = mod_pow(2, N, M);

    // Calculate the number of sets where a topping is missing
    long long int missing_topping_sets = mod_pow(2, N - 1, M);

    // Calculate the number of valid sets (total sets - sets with missing toppings)
    long long int valid_sets = (total_ramen - missing_topping_sets * N) % M;

    // If the result is negative, add M to make it positive
    if (valid_sets < 0) {
        valid_sets += M;
    }

    return valid_sets;
}

int main() {
    int N;
    long long int M;

    // Read input values from standard input
    scanf("%d %lld", &N, &M);

    // Calculate and print the number of valid ramen sets modulo M
    printf("%lld\n", count_ramen_sets(N, M));

    return 0;
}