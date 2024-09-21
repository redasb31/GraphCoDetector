#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to calculate the factorial of a number modulo MOD
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result = (result * i) % MOD;
    }
    return result;
}

// Function to calculate the probability of winning for a given state of lamps
long long winningProbability(int n, int a, int *lamps) {
    // Base cases:
    // If all lamps are on, Snuke wins.
    if (a == n) {
        return factorial(n);
    }
    // If no lamps are on, Snuke loses.
    if (a == 0) {
        return 0;
    }

    // Recursive step:
    long long total = 0;
    // Try pressing each button corresponding to a lit lamp
    for (int i = 1; i <= n; i++) {
        if (lamps[i] == 1) {
            // Flip the state of the lamp connected to the button
            lamps[i] = 0;
            lamps[(i + 1) % n] = 1 - lamps[(i + 1) % n];
            // Recursively calculate the winning probability for the new state
            total = (total + winningProbability(n, a, lamps)) % MOD;
            // Restore the original state
            lamps[(i + 1) % n] = 1 - lamps[(i + 1) % n];
            lamps[i] = 1;
        }
    }
    return total;
}

int main() {
    int n, a;
    scanf("%d %d", &n, &a);

    // Create an array to represent the state of the lamps
    int *lamps = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 1; i <= n; i++) {
        lamps[i] = (i <= a) ? 1 : 0;
    }

    // Calculate and print the probability of winning multiplied by N! modulo MOD
    long long probability = winningProbability(n, a, lamps);
    printf("%lld\n", probability);

    free(lamps);
    return 0;
}