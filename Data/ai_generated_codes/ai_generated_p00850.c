#include <stdio.h>
#include <limits.h>

// Function to calculate the minimum number of operations required to compute x^n
int minOperations(int n) {
    // Base case: n = 1 requires no operations
    if (n == 1) {
        return 0;
    }

    // Initialize minimum operations to a large value
    int minOps = INT_MAX;

    // Iterate through all possible powers of 2 less than or equal to n
    for (int i = 0; (1 << i) <= n; i++) {
        // Calculate the number of operations for the current power of 2
        int ops = i + minOperations(n - (1 << i));

        // Update the minimum operations if a smaller value is found
        minOps = (ops < minOps) ? ops : minOps;
    }

    // If n is a power of 2, we only need one division operation
    if (n == (1 << (int)log2(n))) {
        minOps = 1;
    }

    return minOps;
}

// Function to calculate the logarithm base 2 of a number
int log2(int n) {
    int count = 0;
    while (n >>= 1) {
        count++;
    }
    return count;
}

int main() {
    int n;

    // Read input until a zero is encountered
    while (1) {
        scanf("%d", &n);

        // Break the loop if the input is zero
        if (n == 0) {
            break;
        }

        // Calculate and print the minimum number of operations
        printf("%d\n", minOperations(n));
    }

    return 0;
}