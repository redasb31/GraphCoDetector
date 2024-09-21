#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_ROOMS 100000
#define MAX_DOORS 100000

// Structure to represent a door
typedef struct Door {
    int room1;
    int room2;
    int direction; // 1: one-way (room1 to room2), 2: two-way
} Door;

// Structure to represent a room
typedef struct Room {
    int doors_count;
    Door* doors;
} Room;

// Function to create a new room
Room* createRoom() {
    Room* room = (Room*)malloc(sizeof(Room));
    room->doors_count = 0;
    room->doors = NULL;
    return room;
}

// Function to add a door to a room
void addDoor(Room* room, Door door) {
    room->doors_count++;
    room->doors = (Door*)realloc(room->doors, room->doors_count * sizeof(Door));
    room->doors[room->doors_count - 1] = door;
}

// Function to perform depth-first search (DFS)
int dfs(Room* rooms, int current_room, int visited[], int time) {
    visited[current_room] = 1;

    int max_time = time;

    // Iterate over all doors connected to the current room
    for (int i = 0; i < rooms[current_room].doors_count; i++) {
        Door door = rooms[current_room].doors[i];
        int next_room = (door.room1 == current_room) ? door.room2 : door.room1;

        // If the door is one-way and we are going in the wrong direction, skip it
        if (door.direction == 1 && next_room == door.room1) {
            continue;
        }

        // If the next room is not visited, recursively explore it
        if (!visited[next_room]) {
            int new_time = dfs(rooms, next_room, visited, time + 1);
            max_time = (new_time > max_time) ? new_time : max_time;
        }
    }

    return max_time;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Create an array of rooms
    Room* rooms = (Room*)malloc(n * sizeof(Room));
    for (int i = 0; i < n; i++) {
        rooms[i] = *createRoom();
    }

    // Read door information
    Door door;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &door.room1, &door.room2, &door.direction);
        addDoor(&rooms[door.room1 - 1], door);
        if (door.direction == 2) {
            addDoor(&rooms[door.room2 - 1], door);
        }
    }

    // Initialize visited array
    int* visited = (int*)calloc(n, sizeof(int));

    int max_time = 0;
    // Perform DFS from each room
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int time = dfs(rooms, i, visited, 0);
            max_time = (time > max_time) ? time : max_time;
        }
    }

    // Check if George can escape forever
    for (int i = 0; i < n; i++) {
        if (rooms[i].doors_count > 1) {
            max_time = INT_MAX;
            break;
        }
    }

    // Print the result
    if (max_time == INT_MAX) {
        printf("Infinite\n");
    } else {
        printf("%d\n", max_time);
    }

    // Free allocated memory
    free(rooms);
    free(visited);

    return 0;
}