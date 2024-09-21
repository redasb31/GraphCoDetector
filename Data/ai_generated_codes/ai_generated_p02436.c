#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000
#define MAX_Q 200000

// Structure for a node in the queue
struct Node {
    int data;
    struct Node* next;
};

// Structure for a queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to enqueue an element into the queue
void enqueue(struct Queue* queue, int data) {
    struct Node* node = newNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = node;
        return;
    }
    queue->rear->next = node;
    queue->rear = node;
}

// Function to get the front element of the queue
int front(struct Queue* queue) {
    if (queue->front == NULL) {
        return -1; // Queue is empty
    }
    return queue->front->data;
}

// Function to dequeue an element from the queue
void dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        return; // Queue is empty
    }
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
}

int main() {
    int n, q, t, x, op;
    struct Queue* queues[MAX_N];

    // Read input
    scanf("%d %d", &n, &q);

    // Initialize queues
    for (int i = 0; i < n; i++) {
        queues[i] = createQueue();
    }

    // Process queries
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &op, &t);
        if (op == 0) {
            scanf("%d", &x);
            enqueue(queues[t], x); // Enqueue
        } else if (op == 1) {
            int front_val = front(queues[t]); // Front
            if (front_val != -1) {
                printf("%d\n", front_val);
            }
        } else if (op == 2) {
            dequeue(queues[t]); // Dequeue
        }
    }

    return 0;
}