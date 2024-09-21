#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_H 1000000
#define MAX_W 1000000

typedef struct {
    int x;
    int y;
    int stroke;
} Node;

int H, W, K;
char pond[MAX_H][MAX_W + 1];
int dist[MAX_H][MAX_W];

// Function to allocate memory for a queue
Node* createQueue(int capacity) {
    Node* queue = (Node*)malloc(sizeof(Node) * capacity);
    if (queue == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    return queue;
}

// Function to enqueue a node to the queue
void enqueue(Node* queue, int* front, int* rear, Node node) {
    if ((*rear + 1) % MAX_H == *front) {
        fprintf(stderr, "Queue Overflow!\n");
        exit(1);
    }
    queue[*rear] = node;
    *rear = (*rear + 1) % MAX_H;
}

// Function to dequeue a node from the queue
Node dequeue(Node* queue, int* front, int* rear) {
    if (*front == *rear) {
        fprintf(stderr, "Queue Underflow!\n");
        exit(1);
    }
    Node node = queue[*front];
    *front = (*front + 1) % MAX_H;
    return node;
}

// Function to check if the queue is empty
int isEmpty(int front, int rear) {
    return front == rear;
}

// Function to perform Breadth-First Search (BFS) to find the shortest path
int bfs(int x1, int y1, int x2, int y2) {
    // Initialize the queue and its front and rear pointers
    Node* queue = createQueue(MAX_H * MAX_W);
    int front = 0, rear = 0;

    // Initialize the distance matrix with a large value
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            dist[i][j] = INT_MAX;
        }
    }

    // Enqueue the starting node
    enqueue(queue, &front, &rear, (Node){x1, y1, 0});
    dist[x1 - 1][y1 - 1] = 0; // Adjust coordinates for 0-based indexing

    // Perform BFS until the queue is empty
    while (!isEmpty(front, rear)) {
        // Dequeue a node from the queue
        Node current = dequeue(queue, &front, &rear);

        // Check if the destination node is reached
        if (current.x == x2 && current.y == y2) {
            free(queue);
            return current.stroke;
        }

        // Explore neighboring nodes
        for (int i = 1; i <= K; i++) {
            // North
            if (current.x - i >= 1 && pond[current.x - i - 1][current.y - 1] == '.' &&
                dist[current.x - i - 1][current.y - 1] > current.stroke + 1) {
                enqueue(queue, &front, &rear, (Node){current.x - i, current.y, current.stroke + 1});
                dist[current.x - i - 1][current.y - 1] = current.stroke + 1;
            }

            // East
            if (current.y + i <= W && pond[current.x - 1][current.y + i - 1] == '.' &&
                dist[current.x - 1][current.y + i - 1] > current.stroke + 1) {
                enqueue(queue, &front, &rear, (Node){current.x, current.y + i, current.stroke + 1});
                dist[current.x - 1][current.y + i - 1] = current.stroke + 1;
            }

            // South
            if (current.x + i <= H && pond[current.x + i - 1][current.y - 1] == '.' &&
                dist[current.x + i - 1][current.y - 1] > current.stroke + 1) {
                enqueue(queue, &front, &rear, (Node){current.x + i, current.y, current.stroke + 1});
                dist[current.x + i - 1][current.y - 1] = current.stroke + 1;
            }

            // West
            if (current.y - i >= 1 && pond[current.x - 1][current.y - i - 1] == '.' &&
                dist[current.x - 1][current.y - i - 1] > current.stroke + 1) {
                enqueue(queue, &front, &rear, (Node){current.x, current.y - i, current.stroke + 1});
                dist[current.x - 1][current.y - i - 1] = current.stroke + 1;
            }
        }
    }

    // If the destination node is not reached, return -1
    free(queue);
    return -1;
}

int main() {
    // Input the dimensions of the pond, the maximum number of squares to move, and the coordinates of the starting and ending points
    scanf("%d %d %d", &H, &W, &K);
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    // Input the pond configuration
    for (int i = 0; i < H; i++) {
        scanf("%s", pond[i]);
    }

    // Perform BFS to find the shortest path
    int strokes = bfs(x1, y1, x2, y2);

    // Output the result
    printf("%d\n", strokes);

    return 0;
}