#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to evaluate a boolean expression
long long evaluate(char *expression, int *variables, int n) {
    // Base case: If the expression is a single variable
    if (expression[0] == 'x') {
        int variable_index = atoi(expression + 1) - 1;
        return variables[variable_index];
    }

    // Evaluate the expression recursively
    long long result = 0;
    int i = 0;
    while (expression[i] != '\0') {
        // Skip spaces and parentheses
        if (expression[i] == ' ' || expression[i] == '(' || expression[i] == ')') {
            i++;
            continue;
        }

        // Evaluate the current term
        long long term = evaluate(expression + i, variables, n);
        // Check for OR operator
        if (expression[i] == '|') {
            result = (result + term) % MOD;
            i++;
        } else {
            // Check for AND operator
            if (expression[i] == ' ') {
                result = (result * term) % MOD;
                i++;
            } else {
                // Check for NOT operator
                if (expression[i] == ' ') {
                    result = (result + (1 - term)) % MOD;
                    i++;
                }
            }
        }
    }
    return result;
}

// Function to count the number of variable assignments that make the expression true
long long count_assignments(char *expression, int n) {
    long long count = 0;
    // Iterate over all possible variable assignments
    for (int i = 0; i < (1 << n); i++) {
        // Create an array to store the variable values
        int variables[n];
        // Assign values to the variables based on the current iteration
        for (int j = 0; j < n; j++) {
            variables[j] = (i >> j) & 1;
        }
        // Evaluate the expression with the current variable assignment
        if (evaluate(expression, variables, n) == 1) {
            count = (count + 1) % MOD;
        }
    }
    return count;
}

int main() {
    char expression[1000001];
    // Read the boolean expression from standard input
    scanf("%s", expression);
    // Count the number of variables in the expression
    int n = 0;
    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == 'x') {
            n++;
        }
    }
    // Count the number of variable assignments that make the expression true
    long long count = count_assignments(expression, n);
    // Print the result
    printf("%lld\n", count);
    return 0;
}