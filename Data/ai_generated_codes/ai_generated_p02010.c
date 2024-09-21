#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Function to check if a string is a valid formula
int is_valid_formula(char *formula) {
    int len = strlen(formula);
    if (len == 0) {
        return 0;
    }
    // Check for leading zeros
    if (formula[0] == '0' && len > 1) {
        return 0;
    }
    // Check for unary pluses
    if (formula[0] == '+' || formula[len - 1] == '+') {
        return 0;
    }
    // Check for consecutive pluses
    for (int i = 0; i < len - 1; i++) {
        if (formula[i] == '+' && formula[i + 1] == '+') {
            return 0;
        }
    }
    return 1;
}

// Function to calculate the value of a formula
int calculate_formula(char *formula) {
    int len = strlen(formula);
    int result = 0;
    int num = 0;
    for (int i = 0; i < len; i++) {
        if (formula[i] == '+') {
            result += num;
            num = 0;
        } else {
            num = num * 10 + (formula[i] - '0');
        }
    }
    result += num;
    return result;
}

// Function to find the minimum number of replacements
int find_minimum_replacements(char *formula, int N) {
    int len = strlen(formula);
    int min_replacements = INT_MAX;
    // Try all possible combinations of replacements
    for (int i = 0; i < (1 << len); i++) {
        char new_formula[len + 1];
        int replacements = 0;
        // Replace characters based on the current combination
        for (int j = 0; j < len; j++) {
            if (i & (1 << j)) {
                new_formula[j] = '0';
                replacements++;
            } else {
                new_formula[j] = formula[j];
            }
        }
        new_formula[len] = '\0';
        // Check if the new formula is valid and smaller than N
        if (is_valid_formula(new_formula) && calculate_formula(new_formula) <= N) {
            min_replacements = (min_replacements < replacements) ? min_replacements : replacements;
        }
    }
    // If no valid formula was found, return -1
    if (min_replacements == INT_MAX) {
        return -1;
    }
    return min_replacements;
}

int main() {
    int N;
    char formula[1001];
    scanf("%d\n", &N);
    scanf("%s", formula);
    int min_replacements = find_minimum_replacements(formula, N);
    printf("%d\n", min_replacements);
    return 0;
}