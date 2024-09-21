#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000
#define MAX_Q 200000

// Structure for a priority queue node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Structure for a priority queue
typedef struct PriorityQueue {
    Node *head;
} PriorityQueue;

// Function to create a new node
Node *newNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to initialize a priority queue
PriorityQueue *initPriorityQueue() {
    PriorityQueue *queue = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    queue->head = NULL;
    return queue;
}

// Function to insert an element into a priority queue
void insert(PriorityQueue *queue, int data) {
    // Create a new node with the data
    Node *node = newNode(data);

    // If the queue is empty, insert the node as the head
    if (queue->head == NULL) {
        queue->head = node;
        return;
    }

    // If the data is greater than or equal to the head's data, insert the node before the head
    if (data >= queue->head->data) {
        node->next = queue->head;
        queue->head = node;
        return;
    }

    // Traverse the queue to find the appropriate insertion point
    Node *current = queue->head;
    Node *previous = NULL;
    while (current != NULL && data < current->data) {
        previous = current;
        current = current->next;
    }

    // Insert the node after the previous node
    node->next = current;
    previous->next = node;
}

// Function to get the maximum element from a priority queue
int getMax(PriorityQueue *queue) {
    // If the queue is empty, return -1 (or any other sentinel value)
    if (queue->head == NULL) {
        return -1;
    }

    // Return the data of the head node
    return queue->head->data;
}

// Function to delete the maximum element from a priority queue
void deleteMax(PriorityQueue *queue) {
    // If the queue is empty, do nothing
    if (queue->head == NULL) {
        return;
    }

    // Remove the head node
    Node *temp = queue->head;
    queue->head = queue->head->next;
    free(temp);
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    // Create an array of priority queues
    PriorityQueue *queues[MAX_N];
    for (int i = 0; i < n; i++) {
        queues[i] = initPriorityQueue();
    }

    // Process the queries
    for (int i = 0; i < q; i++) {
        int operation, t, x;
        scanf("%d %d", &operation, &t);

        switch (operation) {
            case 0: // Insert
                scanf("%d", &x);
                insert(queues[t], x);
                break;
            case 1: // Get Max
                int max = getMax(queues[t]);
                if (max != -1) {
                    printf("%d\n", max);
                }
                break;
            case 2: // Delete Max
                deleteMax(queues[t]);
                break;
        }
    }

    // Free the memory allocated for the priority queues
    for (int i = 0; i < n; i++) {
        free(queues[i]);
    }

    return 0;
}