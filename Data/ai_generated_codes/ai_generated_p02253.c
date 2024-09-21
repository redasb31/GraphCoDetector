#include <stdio.h>
#include <stdlib.h>

// Structure to represent an activity
typedef struct Activity {
    int start;
    int finish;
} Activity;

// Function to compare two activities based on their finish times
int compareActivities(const void *a, const void *b) {
    Activity *activityA = (Activity *)a;
    Activity *activityB = (Activity *)b;
    return activityA->finish - activityB->finish;
}

// Function to find the maximum number of activities that can be performed
int findMaxActivities(Activity activities[], int n) {
    // Sort activities based on their finish times
    qsort(activities, n, sizeof(Activity), compareActivities);

    // Initialize the count of selected activities
    int count = 1; 

    // Select the first activity
    int i = 0;

    // Iterate over the remaining activities
    for (int j = 1; j < n; j++) {
        // If the current activity's start time is greater than or equal to the finish time of the previously selected activity
        if (activities[j].start >= activities[i].finish) {
            // Select the current activity
            count++;
            i = j;
        }
    }

    // Return the count of selected activities
    return count;
}

int main() {
    // Read the number of activities
    int n;
    scanf("%d", &n);

    // Allocate memory for the activities
    Activity *activities = (Activity *)malloc(n * sizeof(Activity));

    // Read the start and finish times of each activity
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &activities[i].start, &activities[i].finish);
    }

    // Find the maximum number of activities
    int maxActivities = findMaxActivities(activities, n);

    // Print the result
    printf("%d\n", maxActivities);

    // Free the allocated memory
    free(activities);

    return 0;
}