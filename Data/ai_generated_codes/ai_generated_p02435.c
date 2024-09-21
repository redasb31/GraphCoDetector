#include <stdio.h>
#include <stdlib.h>

#define MAX_STACKS 1000
#define MAX_QUERY 200000

// Structure to represent a stack
struct Stack {
    int top;
    int data[MAX_QUERY]; // Assuming maximum query size is 200,000
};

// Function to initialize a stack
void initStack(struct Stack *stack) {
    stack->top = -1; // Initially empty
}

// Function to push an element onto the stack
void push(struct Stack *stack, int x) {
    stack->data[++stack->top] = x;
}

// Function to get the top element of the stack
int top(struct Stack *stack) {
    if (stack->top == -1) {
        return -1; // Stack is empty
    }
    return stack->data[stack->top];
}

// Function to pop an element from the stack
void pop(struct Stack *stack) {
    if (stack->top != -1) {
        stack->top--;
    }
}

int main() {
    int n, q; // Number of stacks and queries
    scanf("%d %d", &n, &q);

    struct Stack stacks[MAX_STACKS]; // Array to store stacks
    for (int i = 0; i < n; i++) {
        initStack(&stacks[i]); // Initialize all stacks
    }

    int operation, t, x;

    for (int i = 0; i < q; i++) {
        scanf("%d %d", &operation, &t);

        switch (operation) {
            case 0: // push operation
                scanf("%d", &x);
                push(&stacks[t], x);
                break;
            case 1: // top operation
                int topValue = top(&stacks[t]);
                if (topValue != -1) {
                    printf("%d\n", topValue);
                }
                break;
            case 2: // pop operation
                pop(&stacks[t]);
                break;
        }
    }

    return 0;
}