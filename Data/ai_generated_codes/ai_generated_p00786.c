#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a BUT
typedef struct BUT {
    char label;
    struct BUT *left;
    struct BUT *right;
} BUT;

// Function to create a new BUT node
BUT* createBUT(char label) {
    BUT *node = (BUT*)malloc(sizeof(BUT));
    node->label = label;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to parse the expression and build the BUT tree
BUT* parseExpression(char *expression) {
    char *current = expression;
    BUT *root = NULL;

    // Skip whitespace
    while (*current == ' ' || *current == '\t') {
        current++;
    }

    // If we encounter a letter, create a 0-ary BUT
    if (isalpha(*current)) {
        root = createBUT(*current);
        current++;
    }

    // If we encounter a parenthesis, it's a unary or binary BUT
    if (*current == '(') {
        current++;

        // Create the left component
        root = createBUT(*current);
        current++;
        root->left = parseExpression(current);

        // If it's a binary BUT, parse the right component
        if (*current == ',') {
            current++;
            root->right = parseExpression(current);
        }

        // Skip the closing parenthesis
        if (*current == ')') {
            current++;
        }
    }

    return root;
}

// Function to print the diagram of the BUT
void printDiagram(BUT *root, int level, int left, int right) {
    // Base case: 0-ary BUT
    if (root == NULL) {
        return;
    }

    // Print the root
    for (int i = 0; i < level; i++) {
        printf(" ");
    }
    printf("%c\n", root->label);

    // Print the minus symbols for the root
    if (root->left || root->right) {
        for (int i = 0; i < level; i++) {
            printf(" ");
        }
        for (int i = left; i <= right; i++) {
            printf("-");
        }
        printf("\n");
    }

    // Print the left component
    if (root->left) {
        printDiagram(root->left, level + 1, left, (left + right) / 2 - 1);
    }

    // Print the right component
    if (root->right) {
        printDiagram(root->right, level + 1, (left + right) / 2 + 1, right);
    }
}

int main() {
    char expression[100];
    int count = 1;

    // Read expressions from input
    while (fgets(expression, 100, stdin) != NULL) {
        // Remove trailing newline
        expression[strcspn(expression, "\n")] = 0;

        // Parse the expression and build the BUT tree
        BUT *root = parseExpression(expression);

        // Print the diagram
        printf("%d:\n", count);
        printDiagram(root, 0, 0, 79);

        // Free the BUT tree
        free(root);

        count++;
    }

    return 0;
}