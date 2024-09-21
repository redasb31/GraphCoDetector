#include <stdio.h>
#include <math.h>

// Function to calculate (i * j) ^ 2019
long long calculate_power(long long i, long long j) {
    long long result = i * j;
    for (int k = 1; k < 2019; k++) {
        result *= (i * j);
    }
    return result;
}

int main() {
    long long L, R;

    // Input the values of L and R
    scanf("%lld %lld", &L, &R);

    // Initialize minimum power with a very large value
    long long min_power = 1e18; 

    // Iterate through all possible pairs (i, j)
    for (long long i = L; i < R; i++) {
        for (long long j = i + 1; j <= R; j++) {
            // Calculate the power and update the minimum
            long long current_power = calculate_power(i, j);
            if (current_power < min_power) {
                min_power = current_power;
            }
        }
    }

    // Print the minimum power
    printf("%lld\n", min_power);

    return 0;
}