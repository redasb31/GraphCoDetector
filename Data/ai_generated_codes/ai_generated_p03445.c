#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007

// Structure to represent a point
typedef struct {
    int x;
    int y;
} Point;

// Function to calculate the Manhattan distance between two points
int manhattanDistance(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// Function to perform BFS to find the shortest distance between two white squares
int bfs(Point start, Point end, int H, int W, int N, Point blackSquares[30]) {
    // Create a 2D array to store the grid
    int **grid = (int **)malloc(H * sizeof(int *));
    for (int i = 0; i < H; i++) {
        grid[i] = (int *)malloc(W * sizeof(int));
    }

    // Initialize the grid with 0s (representing white squares)
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            grid[i][j] = 0;
        }
    }

    // Mark the black squares as 1s
    for (int i = 0; i < N; i++) {
        grid[blackSquares[i].x][blackSquares[i].y] = 1;
    }

    // Create a queue for BFS
    Point *queue = (Point *)malloc(H * W * sizeof(Point));
    int front = 0, rear = 0;

    // Enqueue the starting point
    queue[rear++] = start;
    grid[start.x][start.y] = 2; // Mark the starting point as visited

    // Perform BFS
    while (front < rear) {
        Point current = queue[front++];

        // Check if we have reached the destination
        if (current.x == end.x && current.y == end.y) {
            free(queue);
            for (int i = 0; i < H; i++) {
                free(grid[i]);
            }
            free(grid);
            return grid[end.x][end.y] - 2; // Return the distance
        }

        // Explore adjacent squares
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++) {
            int x = current.x + dx[i];
            int y = current.y + dy[i];

            // Check if the adjacent square is valid and not visited
            if (x >= 0 && x < H && y >= 0 && y < W && grid[x][y] == 0) {
                queue[rear++] = (Point){x, y};
                grid[x][y] = grid[current.x][current.y] + 1; // Mark the square as visited and update distance
            }
        }
    }

    // If the destination is not reached, return -1
    free(queue);
    for (int i = 0; i < H; i++) {
        free(grid[i]);
    }
    free(grid);
    return -1;
}

int main() {
    int H, W, N;
    scanf("%d %d", &H, &W);
    scanf("%d", &N);

    // Store the black squares
    Point blackSquares[30];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &blackSquares[i].x, &blackSquares[i].y);
    }

    // Calculate the total number of white squares
    int totalWhiteSquares = H * W - N;

    // Calculate the number of ways to choose 2 white squares
    long long combinations = (totalWhiteSquares * (totalWhiteSquares - 1)) / 2;

    // Calculate the sum of the shortest distances
    long long sum = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            // Check if the current square is white
            if (grid[i][j] == 0) {
                for (int k = i; k < H; k++) {
                    for (int l = (k == i) ? (j + 1) : 0; l < W; l++) {
                        // Check if the other square is white
                        if (grid[k][l] == 0) {
                            // Calculate the shortest distance between the two white squares
                            int distance = bfs((Point){i, j}, (Point){k, l}, H, W, N, blackSquares);
                            // Add the distance to the sum
                            sum = (sum + distance) % MOD;
                        }
                    }
                }
            }
        }
    }

    // Print the sum of the shortest distances modulo 10^9+7
    printf("%lld\n", sum);

    return 0;
}