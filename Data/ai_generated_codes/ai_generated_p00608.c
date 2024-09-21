#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_H 10
#define MAX_W 10
#define MAX_N 10

// Structure to represent a cell in the grid
typedef struct {
    char value;
    int is_blank;
} Cell;

// Function to check if a given expression is valid
int is_valid_expression(char *expression, int len) {
    int num_operators = 0;
    int num_operands = 0;
    int prev_is_operator = 0;

    // Iterate over the expression
    for (int i = 0; i < len; i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            num_operators++;
            prev_is_operator = 1;
        } else if (expression[i] >= '0' && expression[i] <= '9') {
            num_operands++;
            prev_is_operator = 0;
        } else if (expression[i] == '=') {
            // Check for '='
            if (num_operands < 2 || prev_is_operator) {
                return 0;
            }
        } else {
            // Invalid character
            return 0;
        }
    }

    // Check if the expression has at least one operand and one operator
    if (num_operands < 1 || num_operators < 1) {
        return 0;
    }

    return 1;
}

// Function to evaluate an expression
int evaluate_expression(char *expression, int len) {
    int result = 0;
    int operand = 0;
    int operator = 0;
    int prev_is_operator = 0;

    // Iterate over the expression
    for (int i = 0; i < len; i++) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            operand = operand * 10 + (expression[i] - '0');
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            if (prev_is_operator) {
                // Invalid expression
                return -1;
            }

            operator = expression[i];
            prev_is_operator = 1;
        } else if (expression[i] == '=') {
            // Handle the equality
            if (prev_is_operator) {
                // Invalid expression
                return -1;
            }

            // Evaluate the expression on the right side
            int right_result = evaluate_expression(expression + i + 1, len - i - 1);
            if (right_result == -1) {
                // Invalid expression
                return -1;
            }

            // Check if the left side evaluates to the same value
            if (operator == '+') {
                if (result + operand != right_result) {
                    return 0;
                }
            } else if (operator == '-') {
                if (result - operand != right_result) {
                    return 0;
                }
            } else if (operator == '*') {
                if (result * operand != right_result) {
                    return 0;
                }
            } else if (operator == '/') {
                if (operand == 0) {
                    // Division by zero
                    return 0;
                } else if (result % operand != 0 || result / operand != right_result) {
                    // Division with remainder or invalid result
                    return 0;
                }
            }

            return 1;
        }
    }

    // If no equality is found, the expression is invalid
    return 0;
}

// Function to check if the puzzle is solvable
int is_puzzle_solvable(Cell grid[MAX_H][MAX_W], int h, int w, char *numbers_operators, int n) {
    int num_blanks = 0;
    // Count the number of blank cells
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j].is_blank) {
                num_blanks++;
            }
        }
    }

    // Check if the number of blanks is equal to the length of the list
    if (num_blanks != n) {
        return 0;
    }

    // Iterate over all possible combinations of filling the blank cells
    for (int i = 0; i < 1 << n; i++) {
        // Create a copy of the list
        char current_numbers_operators[MAX_N];
        memcpy(current_numbers_operators, numbers_operators, n);

        // Fill the blank cells with the numbers and operators from the list
        int blank_index = 0;
        for (int j = 0; j < h; j++) {
            for (int k = 0; k < w; k++) {
                if (grid[j][k].is_blank) {
                    // Fill the blank cell with the next character from the list
                    grid[j][k].value = current_numbers_operators[blank_index];

                    // Remove the character from the list
                    current_numbers_operators[blank_index] = ' ';
                    blank_index++;
                }
            }
        }

        // Check if the puzzle is solved
        if (is_puzzle_solved(grid, h, w)) {
            return 1;
        }
    }

    return 0;
}

// Function to check if the puzzle is solved
int is_puzzle_solved(Cell grid[MAX_H][MAX_W], int h, int w) {
    // Check if all rows and columns are solved
    for (int i = 0; i < h; i++) {
        // Check if the row is solved
        if (!is_valid_expression((char *)grid[i], w)) {
            return 0;
        }

        // Check if the column is solved
        char column[MAX_H];
        for (int j = 0; j < h; j++) {
            column[j] = grid[j][i].value;
        }
        if (!is_valid_expression((char *)column, h)) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int h, w, n;
    char grid[MAX_H][MAX_W];
    char numbers_operators[MAX_N];

    // Read the input
    while (scanf("%d %d", &h, &w) != EOF && (h != 0 || w != 0)) {
        Cell grid_cells[MAX_H][MAX_W];

        // Read the grid
        for (int i = 0; i < h; i++) {
            scanf("%s", grid[i]);
            for (int j = 0; j < w; j++) {
                grid_cells[i][j].value = grid[i][j];
                if (grid[i][j] == '.') {
                    grid_cells[i][j].is_blank = 1;
                } else {
                    grid_cells[i][j].is_blank = 0;
                }
            }
        }

        // Read the list of numbers and operators
        scanf("%d", &n);
        scanf("%s", numbers_operators);

        // Check if the puzzle is solvable
        if (is_puzzle_solvable(grid_cells, h, w, numbers_operators, n)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}