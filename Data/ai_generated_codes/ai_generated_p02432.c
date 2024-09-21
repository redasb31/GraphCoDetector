#include <stdio.h>
#include <stdlib.h>

// Structure to represent a deque
struct Deque {
    int *arr; // Array to store elements
    int front; // Index of the front element
    int rear; // Index of the rear element
    int capacity; // Maximum capacity of the deque
};

// Function to initialize a new deque
struct Deque* createDeque(int capacity) {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    deque->arr = (int*)malloc(capacity * sizeof(int));
    deque->front = -1;
    deque->rear = -1;
    deque->capacity = capacity;
    return deque;
}

// Function to check if the deque is empty
int isEmpty(struct Deque* deque) {
    return (deque->front == -1);
}

// Function to check if the deque is full
int isFull(struct Deque* deque) {
    return ((deque->rear + 1) % deque->capacity == deque->front);
}

// Function to push an element at the front of the deque
void pushFront(struct Deque* deque, int x) {
    if (isFull(deque)) {
        printf("Deque is full\n");
        return;
    }

    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->front = (deque->front - 1 + deque->capacity) % deque->capacity;
    }

    deque->arr[deque->front] = x;
}

// Function to push an element at the rear of the deque
void pushRear(struct Deque* deque, int x) {
    if (isFull(deque)) {
        printf("Deque is full\n");
        return;
    }

    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->rear = (deque->rear + 1) % deque->capacity;
    }

    deque->arr[deque->rear] = x;
}

// Function to get the element at a given position in the deque
int randomAccess(struct Deque* deque, int p) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return -1;
    }

    if (p < 0 || p >= (deque->rear - deque->front + deque->capacity) % deque->capacity) {
        printf("Invalid position\n");
        return -1;
    }

    return deque->arr[(deque->front + p) % deque->capacity];
}

// Function to pop the element from the front of the deque
void popFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }

    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->front = (deque->front + 1) % deque->capacity;
    }
}

// Function to pop the element from the rear of the deque
void popRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }

    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->rear = (deque->rear - 1 + deque->capacity) % deque->capacity;
    }
}

int main() {
    int q, operation, d, x, p;

    // Read the number of queries
    scanf("%d", &q);

    // Create a deque with initial capacity
    struct Deque* deque = createDeque(100);

    // Process each query
    for (int i = 0; i < q; i++) {
        scanf("%d", &operation);

        if (operation == 0) {
            // Push operation
            scanf("%d %d", &d, &x);
            if (d == 0) {
                pushFront(deque, x);
            } else {
                pushRear(deque, x);
            }
        } else if (operation == 1) {
            // Random access operation
            scanf("%d", &p);
            int element = randomAccess(deque, p);
            if (element != -1) {
                printf("%d\n", element);
            }
        } else if (operation == 2) {
            // Pop operation
            scanf("%d", &d);
            if (d == 0) {
                popFront(deque);
            } else {
                popRear(deque);
            }
        }
    }

    // Free the memory allocated for the deque
    free(deque->arr);
    free(deque);

    return 0;
}