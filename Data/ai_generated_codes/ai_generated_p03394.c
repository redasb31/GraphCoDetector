#include <stdio.h>

// Function to calculate the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// Function to check if a set is special
int is_special_set(int *set, int n) {
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                sum += set[j];
            }
        }
        if (gcd(set[i], sum) == 1) {
            return 0; // Not a special set
        }
    }
    return 1; // Special set
}

// Function to find a special set of size N
void find_special_set(int n) {
    int set[20000]; // Array to store the elements of the set

    // Initialize the set with prime numbers less than 30000
    int prime_count = 0;
    for (int i = 2; i <= 30000; i++) {
        int is_prime = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            set[prime_count++] = i;
        }
    }

    // Iterate through combinations of prime numbers until a special set is found
    for (int i = 0; i < prime_count; i++) {
        for (int j = i + 1; j < prime_count; j++) {
            for (int k = j + 1; k < prime_count; k++) {
                // Create a subset of size N using the prime numbers
                int subset[20000];
                subset[0] = set[i];
                subset[1] = set[j];
                subset[2] = set[k];
                for (int l = 3; l < n; l++) {
                    subset[l] = set[(l + k) % prime_count];
                }

                // Check if the subset is a special set
                if (is_special_set(subset, n)) {
                    // Print the elements of the special set
                    for (int l = 0; l < n; l++) {
                        printf("%d ", subset[l]);
                    }
                    printf("\n");
                    return; // Exit after finding a solution
                }
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n); // Read the size of the set from input
    find_special_set(n); // Find and print a special set of size N
    return 0;
}