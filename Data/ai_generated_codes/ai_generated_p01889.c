#include <stdio.h>
#include <string.h>

#define MOD 1000000007

long long calculate(char *formula) {
    // Handle edge case: empty formula
    if (formula[0] == '\0') {
        return 0;
    }

    // Tokenize the formula
    char *token;
    token = strtok(formula, "+-");
    long long result = 0;
    long long term = 0;
    long long sign = 1; // 1 for positive, -1 for negative

    // Evaluate each term and update the result
    while (token != NULL) {
        // Get the next term (number or a product)
        if (strchr(token, '*') != NULL) {
            // Handle multiplication
            term = 1;
            char *factor = strtok(token, "*");
            while (factor != NULL) {
                term = (term * atoi(factor)) % MOD;
                factor = strtok(NULL, "*");
            }
        } else {
            // Simple number
            term = atoi(token);
        }

        // Apply sign to the term
        result = (result + (sign * term)) % MOD;

        // Get the next token
        token = strtok(NULL, "+-");
        if (token != NULL) {
            // Determine the sign for the next term
            if (token[0] == '+') {
                sign = 1;
            } else {
                sign = -1;
            }
            // Move past the sign to the next term
            token++;
        }
    }

    return (result + MOD) % MOD; // Ensure non-negative result
}

int main() {
    int n;
    scanf("%d", &n);

    char *formula = malloc(10000000); // Allocate a large enough buffer
    formula[0] = '\0'; // Initialize the formula string

    // Build the formula by concatenating repeated pieces
    for (int i = 0; i < n; i++) {
        int r;
        char s[11];
        scanf("%d %s", &r, s);

        // Append repeated piece to the formula string
        for (int j = 0; j < r; j++) {
            strcat(formula, s);
        }
    }

    long long answer = calculate(formula);
    printf("%lld\n", answer);

    free(formula); // Release the allocated memory
    return 0;
}