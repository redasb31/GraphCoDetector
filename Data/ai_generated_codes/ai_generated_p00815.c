#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 100
#define MAX_DOORS 40

// Structure to represent a room
struct Room {
    int doors[MAX_DOORS]; // Array to store connected rooms
    int num_doors; // Number of doors in the room
};

// Function to add a door to a room
void add_door(struct Room *room, int door) {
    room->doors[room->num_doors++] = door;
}

// Function to print the map of the Ninja House
void print_map(struct Room rooms[], int num_rooms) {
    for (int i = 1; i <= num_rooms; i++) {
        printf("%d", i);
        for (int j = 0; j < rooms[i].num_doors; j++) {
            printf(" %d", rooms[i].doors[j]);
        }
        printf("\n");
    }
}

int main() {
    int n; // Number of Ninja Houses
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        // Initialize variables for each Ninja House
        struct Room rooms[MAX_ROOMS];
        int num_rooms = 0;
        int current_room = 1; // Start from room 1
        int distance = 0; // Distance from the first room
        int visited[MAX_ROOMS] = {0}; // Array to track visited rooms

        // Read the record of the exploration
        int record;
        while (scanf("%d", &record) != EOF && record != 0) {
            if (record > 0) {
                // New room found
                num_rooms++;
                rooms[num_rooms].num_doors = record;
                add_door(&rooms[current_room], num_rooms); // Add the new room to the current room's doors
                visited[num_rooms] = 1;
                current_room = num_rooms;
                distance++;
            } else {
                // Visited room found
                int target_room = current_room - record;
                add_door(&rooms[current_room], target_room); // Add the target room to the current room's doors
                add_door(&rooms[target_room], current_room); // Add the current room to the target room's doors
                current_room = target_room;
                distance += record;
            }
        }

        // Print the map of the Ninja House
        print_map(rooms, num_rooms);
    }

    return 0;
}