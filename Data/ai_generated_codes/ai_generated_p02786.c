#include <stdio.h>

// Function to calculate the minimum number of attacks required
long long int minAttacks(long long int H) {
    // Initialize the number of attacks to 0
    long long int attacks = 0;

    // While the monster's health is greater than 0
    while (H > 0) {
        // If the monster's health is 1, it drops to 0
        if (H == 1) {
            attacks++;
            H = 0;
        } else {
            // Otherwise, the monster disappears and two new monsters appear
            attacks++;
            H = H / 2;
        }
    }

    // Return the number of attacks required
    return attacks;
}

int main() {
    // Input the monster's health
    long long int H;
    scanf("%lld", &H);

    // Calculate the minimum number of attacks
    long long int attacks = minAttacks(H);

    // Output the result
    printf("%lld\n", attacks);

    return 0;
}