#include <stdio.h>
#include <string.h>

#define MAX_UNITS 5
#define MAX_CLOCKS 20
#define NUM_TASKS 10

// Structure to represent a reservation table
struct ReservationTable {
    char units[MAX_UNITS][MAX_CLOCKS];
};

// Function to check if a task can be started at a given clock
int canStartTask(struct ReservationTable table, int clock) {
    // Check if any unit is busy at the clock
    for (int i = 0; i < MAX_UNITS; i++) {
        if (table.units[i][clock] == 'X') {
            return 0;
        }
    }
    return 1;
}

// Function to find the minimum number of clock cycles to process 10 tasks
int findMinClockCycles(struct ReservationTable table) {
    int clock = 0;
    int tasksCompleted = 0;

    // Loop until all tasks are completed
    while (tasksCompleted < NUM_TASKS) {
        // Find the next available clock to start a task
        while (!canStartTask(table, clock)) {
            clock++;
        }

        // Start the task
        tasksCompleted++;

        // Advance the clock by the task's duration
        clock += strlen(table.units[0]);
    }

    // Return the total number of clock cycles
    return clock;
}

int main() {
    int n;
    struct ReservationTable table;

    while (1) {
        scanf("%d", &n);

        // End of input
        if (n == 0) {
            break;
        }

        // Read the reservation table
        for (int i = 0; i < MAX_UNITS; i++) {
            scanf("%s", table.units[i]);
        }

        // Find the minimum clock cycles and print the result
        printf("%d\n", findMinClockCycles(table));
    }

    return 0;
}