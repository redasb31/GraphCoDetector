#include <stdio.h>
#include <stdlib.h>

// Structure to represent an assignment
typedef struct Assignment {
    int id; // Assignment ID
    int givenDay; // Day the assignment was given
    int deadline; // Deadline of the assignment
} Assignment;

// Function to compare two assignments based on their deadlines
int compareAssignments(const void *a, const void *b) {
    Assignment *assignmentA = (Assignment *)a;
    Assignment *assignmentB = (Assignment *)b;

    // Compare deadlines
    if (assignmentA->deadline != assignmentB->deadline) {
        return assignmentA->deadline - assignmentB->deadline;
    }

    // If deadlines are the same, compare assignment IDs
    return assignmentA->id - assignmentB->id;
}

// Function to simulate Taro's homework completion
int simulateHomework(Assignment *assignments, int n, int m, int maxOrMin) {
    int completedAssignments = 0;
    int currentDay = 1; // Start from the first day
    int mathAssignmentsCompleted = 0;
    int informaticsAssignmentsCompleted = 0;

    // Sort assignments by deadline, then by ID
    qsort(assignments, n, sizeof(Assignment), compareAssignments);

    while (currentDay <= 400) {
        // Choose a course at random (or based on maxOrMin parameter)
        int course = (maxOrMin == 1) ? (rand() % 2) : ((mathAssignmentsCompleted < m) ? 0 : 1);
        int startIndex = (course == 0) ? 0 : m;
        int endIndex = (course == 0) ? m : n;
        int i = startIndex;

        // Find the first assignment with a deadline on or after the current day
        while (i < endIndex && assignments[i].deadline < currentDay) {
            i++;
        }

        // Check if there are unfinished assignments with a deadline on or after the current day
        if (i < endIndex) {
            // Find the assignment with the smallest ID among assignments with the nearest deadline
            int nearestDeadline = assignments[i].deadline;
            int smallestID = assignments[i].id;

            for (; i < endIndex && assignments[i].deadline == nearestDeadline; i++) {
                if (assignments[i].id < smallestID) {
                    smallestID = assignments[i].id;
                }
            }

            // Complete the assignment
            completedAssignments++;
            if (smallestID <= m) {
                mathAssignmentsCompleted++;
            } else {
                informaticsAssignmentsCompleted++;
            }
        }

        currentDay++;
    }

    return completedAssignments;
}

int main() {
    int n, m; // Number of assignments and mathematics assignments
    scanf("%d %d", &n, &m);

    Assignment *assignments = (Assignment *)malloc(n * sizeof(Assignment));

    // Read assignment details
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &assignments[i].givenDay, &assignments[i].deadline);
        assignments[i].id = i + 1;
    }

    // Calculate the maximum number of assignments Taro can complete
    int maxCompleted = simulateHomework(assignments, n, m, 1);
    printf("%d\n", maxCompleted);

    // Calculate the minimum number of assignments Taro can complete
    int minCompleted = simulateHomework(assignments, n, m, 0);
    printf("%d\n", minCompleted);

    free(assignments);
    return 0;
}