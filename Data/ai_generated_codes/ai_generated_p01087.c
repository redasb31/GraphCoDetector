#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an expression node
typedef struct Expression {
    char operator; // Operator (+ or *)
    int operand_count; // Number of operands
    int value; // Value of the expression
    struct Expression** operands; // Array of pointers to operands
} Expression;

// Function to create a new expression node
Expression* createExpression(char operator, int operand_count) {
    Expression* expr = (Expression*) malloc(sizeof(Expression));
    expr->operator = operator;
    expr->operand_count = operand_count;
    expr->value = 0;
    expr->operands = (Expression**) malloc(sizeof(Expression*) * operand_count);
    return expr;
}

// Function to parse an expression from the input
Expression* parseExpression(char* input, int level, int* i) {
    // Skip the dots indicating nesting level
    while (input[*i] == '.') {
        (*i)++;
    }

    // If it's an integer, create a new expression node with the value
    if (input[*i] >= '0' && input[*i] <= '9') {
        Expression* expr = createExpression(' ', 1);
        expr->value = input[*i] - '0';
        (*i)++;
        return expr;
    }

    // If it's an operator, create a new expression node and parse its operands
    char operator = input[*i];
    (*i)++;
    int operand_count = 0;
    Expression* expr = createExpression(operator, 0);

    // Keep parsing operands until we reach the end of the expression
    while (input[*i] != '\n' && input[*i] != '\0') {
        expr->operands[operand_count++] = parseExpression(input, level + 1, i);
    }
    expr->operand_count = operand_count;

    return expr;
}

// Function to calculate the value of an expression
int evaluateExpression(Expression* expr) {
    // Base case: If it's an integer, return its value
    if (expr->operator == ' ') {
        return expr->value;
    }

    // If it's an addition, sum the values of the operands
    if (expr->operator == '+') {
        int sum = 0;
        for (int i = 0; i < expr->operand_count; i++) {
            sum += evaluateExpression(expr->operands[i]);
        }
        return sum;
    }

    // If it's a multiplication, multiply the values of the operands
    if (expr->operator == '*') {
        int product = 1;
        for (int i = 0; i < expr->operand_count; i++) {
            product *= evaluateExpression(expr->operands[i]);
        }
        return product;
    }

    return 0; // Should never reach here
}

// Function to free the memory allocated for an expression tree
void freeExpression(Expression* expr) {
    if (expr == NULL) {
        return;
    }

    // Recursively free operands
    for (int i = 0; i < expr->operand_count; i++) {
        freeExpression(expr->operands[i]);
    }

    // Free the expression itself
    free(expr->operands);
    free(expr);
}

int main() {
    int n;
    char input[100]; // Assuming maximum input length of 100 characters

    while (1) {
        scanf("%d", &n);

        // If input is 0, exit the loop
        if (n == 0) {
            break;
        }

        // Read the expression from input
        fgets(input, 100, stdin); // Read the input line
        input[strcspn(input, "\n")] = '\0'; // Remove the newline character

        // Parse the expression and calculate its value
        int i = 0;
        Expression* expr = parseExpression(input, 0, &i);
        int result = evaluateExpression(expr);

        // Output the result
        printf("%d\n", result);

        // Free the memory allocated for the expression tree
        freeExpression(expr);
    }

    return 0;
}