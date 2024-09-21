#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

// Structure to represent a tile
typedef struct {
    int x;
    int y;
} Tile;

// Structure to represent a node in the queue
typedef struct Node {
    Tile tile;
    int moves;
    struct Node *next;
} Node;

// Function to create a new node
Node* newNode(Tile tile, int moves) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->tile = tile;
    node->moves = moves;
    node->next = NULL;
    return node;
}

// Function to enqueue a node
void enqueue(Node** front, Node** rear, Tile tile, int moves) {
    Node* node = newNode(tile, moves);
    if (*rear == NULL) {
        *front = node;
        *rear = node;
    } else {
        (*rear)->next = node;
        *rear = node;
    }
}

// Function to dequeue a node
Node* dequeue(Node** front, Node** rear) {
    if (*front == NULL) {
        return NULL;
    }
    Node* node = *front;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    return node;
}

// Function to perform BFS
int bfs(char room[MAX_SIZE][MAX_SIZE], int w, int h, Tile start) {
    int visited[MAX_SIZE][MAX_SIZE] = {0};
    int dirtyCount = 0;
    Node* front = NULL;
    Node* rear = NULL;

    // Count the number of dirty tiles
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (room[i][j] == '*') {
                dirtyCount++;
            }
        }
    }

    // Enqueue the starting tile
    enqueue(&front, &rear, start, 0);
    visited[start.y][start.x] = 1;

    // Perform BFS
    while (front != NULL) {
        Node* current = dequeue(&front, &rear);
        Tile tile = current->tile;
        int moves = current->moves;

        // Check if the current tile is a dirty tile
        if (room[tile.y][tile.x] == '*') {
            room[tile.y][tile.x] = '.'; // Mark the tile as clean
            dirtyCount--;
            if (dirtyCount == 0) {
                return moves; // All dirty tiles cleaned
            }
        }

        // Explore adjacent tiles
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++) {
            int newX = tile.x + dx[i];
            int newY = tile.y + dy[i];
            if (newX >= 0 && newX < w && newY >= 0 && newY < h &&
                room[newY][newX] != 'x' && !visited[newY][newX]) {
                Tile newTile = {newX, newY};
                enqueue(&front, &rear, newTile, moves + 1);
                visited[newY][newX] = 1;
            }
        }
    }

    // If there are still dirty tiles, the robot cannot reach them
    return -1;
}

int main() {
    int w, h;
    char room[MAX_SIZE][MAX_SIZE];
    Tile start;

    while (1) {
        scanf("%d %d", &w, &h);

        // End of input
        if (w == 0 && h == 0) {
            break;
        }

        // Read the room layout
        start.x = -1;
        start.y = -1;
        for (int i = 0; i < h; i++) {
            scanf("%s", room[i]);
            for (int j = 0; j < w; j++) {
                if (room[i][j] == 'o') {
                    start.x = j;
                    start.y = i;
                }
            }
        }

        // Perform BFS if the robot's initial position is valid
        if (start.x != -1 && start.y != -1) {
            int moves = bfs(room, w, h, start);
            printf("%d\n", moves);
        } else {
            printf("-1\n");
        }
    }

    return 0;
}