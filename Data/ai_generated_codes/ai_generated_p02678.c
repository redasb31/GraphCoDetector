#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 100000
#define MAX_M 200000

// Structure to represent a passage
typedef struct Passage {
    int a;
    int b;
} Passage;

// Structure to represent the adjacency list of a room
typedef struct AdjacencyList {
    int count;
    int rooms[MAX_M];
} AdjacencyList;

// Global variables
Passage passages[MAX_M];
AdjacencyList adjacencyList[MAX_N + 1];
int roomToEntranceDistance[MAX_N + 1];
int signpost[MAX_N + 1]; // Stores the room indicated by the signpost in each room

// Function to add a passage to the adjacency list
void addPassage(int a, int b) {
    adjacencyList[a].rooms[adjacencyList[a].count++] = b;
    adjacencyList[b].rooms[adjacencyList[b].count++] = a;
}

// Function to perform Breadth-First Search (BFS) from a given room
void bfs(int startRoom) {
    bool visited[MAX_N + 1] = {false};
    int queue[MAX_N + 1];
    int front = 0, rear = 0;

    visited[startRoom] = true;
    queue[rear++] = startRoom;
    roomToEntranceDistance[startRoom] = 0;

    while (front < rear) {
        int currentRoom = queue[front++];
        for (int i = 0; i < adjacencyList[currentRoom].count; i++) {
            int nextRoom = adjacencyList[currentRoom].rooms[i];
            if (!visited[nextRoom]) {
                visited[nextRoom] = true;
                roomToEntranceDistance[nextRoom] = roomToEntranceDistance[currentRoom] + 1;
                queue[rear++] = nextRoom;
            }
        }
    }
}

// Function to place signposts in rooms
void placeSignposts(int room) {
    for (int i = 0; i < adjacencyList[room].count; i++) {
        int nextRoom = adjacencyList[room].rooms[i];
        // If the next room is closer to the entrance than the current room
        if (roomToEntranceDistance[nextRoom] < roomToEntranceDistance[room]) {
            signpost[room] = nextRoom; // Place the signpost pointing to the next room
            return; // Signpost placed for the current room, no need to check further
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // Read passages
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &passages[i].a, &passages[i].b);
        addPassage(passages[i].a, passages[i].b);
    }

    // Perform BFS from Room 1 to calculate shortest distances to the entrance
    bfs(1);

    // Place signposts for each room except Room 1
    for (int i = 2; i <= N; i++) {
        placeSignposts(i);
    }

    // Check if signposts are placed correctly
    bool validPlacement = true;
    for (int i = 2; i <= N; i++) {
        if (roomToEntranceDistance[signpost[i]] + 1 != roomToEntranceDistance[i]) {
            validPlacement = false;
            break;
        }
    }

    // Output
    if (validPlacement) {
        printf("Yes\n");
        for (int i = 2; i <= N; i++) {
            printf("%d\n", signpost[i]);
        }
    } else {
        printf("No\n");
    }

    return 0;
}