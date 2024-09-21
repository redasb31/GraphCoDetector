#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_H 1003
#define MAX_W 1003

int H, W, Ch, Cw, Dh, Dw;
char S[MAX_H][MAX_W];
int visited[MAX_H][MAX_W];

// Function to check if a square is within the maze and is a road
int is_valid(int h, int w) {
    return h >= 1 && h <= H && w >= 1 && w <= W && S[h][w] == '.';
}

// Function to perform a breadth-first search (BFS) to find the shortest path
int bfs(int start_h, int start_w, int end_h, int end_w) {
    int queue[MAX_H * MAX_W][2]; // Queue for BFS
    int front = 0, rear = 0;
    int distance[MAX_H][MAX_W]; // Distance from the starting point

    // Initialize the queue and distance array
    queue[rear][0] = start_h;
    queue[rear][1] = start_w;
    rear++;
    memset(distance, -1, sizeof(distance));
    distance[start_h][start_w] = 0;

    // Iterate through the queue until it is empty
    while (front < rear) {
        int h = queue[front][0];
        int w = queue[front][1];
        front++;

        // If the destination is reached, return the distance
        if (h == end_h && w == end_w) {
            return distance[h][w];
        }

        // Explore the four adjacent squares
        for (int dh = -1; dh <= 1; dh++) {
            for (int dw = -1; dw <= 1; dw++) {
                if (abs(dh) + abs(dw) == 1 && is_valid(h + dh, w + dw) && distance[h + dh][w + dw] == -1) {
                    queue[rear][0] = h + dh;
                    queue[rear][1] = w + dw;
                    rear++;
                    distance[h + dh][w + dw] = distance[h][w] + 1;
                }
            }
        }

        // Explore the 5x5 area centered at the current square
        for (int dh = -2; dh <= 2; dh++) {
            for (int dw = -2; dw <= 2; dw++) {
                if (is_valid(h + dh, w + dw) && distance[h + dh][w + dw] == -1) {
                    queue[rear][0] = h + dh;
                    queue[rear][1] = w + dw;
                    rear++;
                    distance[h + dh][w + dw] = distance[h][w] + 1;
                }
            }
        }
    }

    // Destination not reachable
    return -1;
}

int main() {
    scanf("%d %d", &H, &W);
    scanf("%d %d", &Ch, &Cw);
    scanf("%d %d", &Dh, &Dw);

    // Read the maze input
    for (int i = 1; i <= H; i++) {
        scanf("%s", S[i] + 1);
    }

    // Perform BFS
    int min_magic = bfs(Ch, Cw, Dh, Dw);

    // Print the result
    printf("%d\n", min_magic);

    return 0;
}