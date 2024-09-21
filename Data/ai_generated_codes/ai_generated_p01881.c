#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_H 200
#define MAX_W 200

// Structure to represent a cell in the grid
typedef struct {
    int row;
    int col;
} Cell;

// Structure to represent a node in the queue
typedef struct Node {
    Cell cell;
    int steps;
    struct Node *next;
} Node;

// Function to create a new node for the queue
Node *newNode(Cell cell, int steps) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    node->cell = cell;
    node->steps = steps;
    node->next = NULL;
    return node;
}

// Function to enqueue a node to the queue
void enqueue(Node **front, Node **rear, Cell cell, int steps) {
    Node *node = newNode(cell, steps);
    if (*rear == NULL) {
        *front = *rear = node;
    } else {
        (*rear)->next = node;
        *rear = node;
    }
}

// Function to dequeue a node from the queue
Node *dequeue(Node **front) {
    if (*front == NULL) {
        return NULL;
    }
    Node *node = *front;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    return node;
}

// Function to check if a cell is valid (within the grid bounds and not a wall)
int isValid(int h, int w, char grid[MAX_H][MAX_W], Cell cell) {
    return cell.row >= 0 && cell.row < h && cell.col >= 0 && cell.col < w && grid[cell.row][cell.col] != '#';
}

// Function to check if a cell is the escape hatch
int isEscapeHatch(Cell cell) {
    return grid[cell.row][cell.col] == ' ';
}

// Function to find the shortest path from the princess to the escape hatch using BFS
int findShortestPath(int h, int w, char grid[MAX_H][MAX_W], Cell princess, Cell escapeHatch) {
    // Create a queue for BFS
    Node *front = NULL;
    Node *rear = NULL;

    // Mark visited cells
    int visited[MAX_H][MAX_W] = {0};

    // Enqueue the starting cell (princess's location)
    enqueue(&front, &rear, princess, 0);
    visited[princess.row][princess.col] = 1;

    // Perform BFS
    while (front != NULL) {
        Node *node = dequeue(&front);

        // Check if we have reached the escape hatch
        if (isEscapeHatch(node->cell)) {
            return node->steps;
        }

        // Explore adjacent cells
        Cell adjacentCells[] = {{node->cell.row - 1, node->cell.col},
                               {node->cell.row + 1, node->cell.col},
                               {node->cell.row, node->cell.col - 1},
                               {node->cell.row, node->cell.col + 1}};

        for (int i = 0; i < 4; i++) {
            Cell adjacentCell = adjacentCells[i];
            if (isValid(h, w, grid, adjacentCell) && !visited[adjacentCell.row][adjacentCell.col]) {
                enqueue(&front, &rear, adjacentCell, node->steps + 1);
                visited[adjacentCell.row][adjacentCell.col] = 1;
            }
        }
    }

    // No path found to the escape hatch
    return -1;
}

// Function to check if the princess can escape from the soldiers
int canPrincessEscape(int h, int w, char grid[MAX_H][MAX_W], Cell princess, Cell escapeHatch, Cell soldiers[]) {
    // Find the shortest path from the princess to the escape hatch
    int shortestPath = findShortestPath(h, w, grid, princess, escapeHatch);

    // If there is no path to the escape hatch, the princess cannot escape
    if (shortestPath == -1) {
        return 0;
    }

    // Check if the soldiers can intercept the princess on the shortest path
    for (int i = 0; i < 4; i++) {
        // Iterate over each soldier
        for (int j = 0; j < 4; j++) {
            // Check if the soldier can reach the princess's position in the same number of steps
            if (findShortestPath(h, w, grid, soldiers[i], princess) <= shortestPath) {
                // The princess cannot escape
                return 0;
            }
        }
    }

    // The princess can escape
    return 1;
}

int main() {
    int h, w;
    char grid[MAX_H][MAX_W];
    Cell princess, escapeHatch;
    Cell soldiers[4] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
    int soldierCount = 0;

    // Read the grid dimensions
    scanf("%d %d", &h, &w);

    // Read the grid
    for (int i = 0; i < h; i++) {
        scanf("%s", grid[i]);
    }

    // Find the princess's and escape hatch's locations
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == '@') {
                princess.row = i;
                princess.col = j;
            } else if (grid[i][j] == ' ') {
                escapeHatch.row = i;
                escapeHatch.col = j;
            } else if (grid[i][j] == '$') {
                soldiers[soldierCount].row = i;
                soldiers[soldierCount].col = j;
                soldierCount++;
            }
        }
    }

    // Check if the princess can escape
    if (canPrincessEscape(h, w, grid, princess, escapeHatch, soldiers)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}