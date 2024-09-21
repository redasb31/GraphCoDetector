#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_R 50
#define MAX_C 50
#define MAX_M 1000

// Structure to represent a room
typedef struct {
    int r, c;
} Room;

// Structure to represent a task
typedef struct {
    Room room;
    int cost;
} Task;

// Function to calculate the minimum power consumption
int min_power(int R, int C, char grid[MAX_R][MAX_C], int power[MAX_R][MAX_C], int on_cost[MAX_R][MAX_C], int off_cost[MAX_R][MAX_C], Task tasks[], int M) {
    // Initialize a 3D array to store the minimum power consumption for each task at each room
    int dp[MAX_R][MAX_C][MAX_M];
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            for (int k = 0; k < M; k++) {
                dp[i][j][k] = INT_MAX;
            }
        }
    }

    // Base case: no tasks, no power consumed
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            dp[i][j][0] = 0;
        }
    }

    // Iterate over the tasks
    for (int k = 1; k <= M; k++) {
        // Iterate over the rooms
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                // Check if the room is a valid room
                if (grid[i][j] == '.') {
                    // Calculate the power consumption for the current task at the current room
                    int current_cost = power[i][j] + on_cost[i][j] + off_cost[i][j];

                    // Iterate over the neighboring rooms
                    for (int x = -1; x <= 1; x++) {
                        for (int y = -1; y <= 1; y++) {
                            // Check if the neighbor room is a valid room and is not the same room
                            if (i + x >= 0 && i + x < R && j + y >= 0 && j + y < C && (x != 0 || y != 0) && grid[i + x][j + y] == '.') {
                                // Calculate the power consumption for the previous task at the neighbor room
                                int prev_cost = dp[i + x][j + y][k - 1];
                                // Update the minimum power consumption for the current task at the current room
                                dp[i][j][k] = min(dp[i][j][k], prev_cost + current_cost);
                            }
                        }
                    }
                }
            }
        }
    }

    // Find the minimum power consumption for the last task at any room
    int min_power = INT_MAX;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            min_power = min(min_power, dp[i][j][M]);
        }
    }

    // Return the minimum power consumption
    return min_power;
}

// Function to read the input
void read_input(int R, int C, int M, char grid[MAX_R][MAX_C], int power[MAX_R][MAX_C], int on_cost[MAX_R][MAX_C], int off_cost[MAX_R][MAX_C], Task tasks[]) {
    // Read the grid
    for (int i = 0; i < R; i++) {
        scanf("%s", grid[i]);
    }

    // Read the power consumption
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%d", &power[i][j]);
        }
    }

    // Read the on cost
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%d", &on_cost[i][j]);
        }
    }

    // Read the off cost
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%d", &off_cost[i][j]);
        }
    }

    // Read the tasks
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &tasks[i].room.r, &tasks[i].room.c);
    }
}

int main() {
    int R, C, M;
    char grid[MAX_R][MAX_C];
    int power[MAX_R][MAX_C];
    int on_cost[MAX_R][MAX_C];
    int off_cost[MAX_R][MAX_C];
    Task tasks[MAX_M];

    // Read the input
    scanf("%d %d %d", &R, &C, &M);
    read_input(R, C, M, grid, power, on_cost, off_cost, tasks);

    // Calculate the minimum power consumption
    int min_power_consumption = min_power(R, C, grid, power, on_cost, off_cost, tasks, M);

    // Print the output
    printf("%d\n", min_power_consumption);

    return 0;
}