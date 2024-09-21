#include <stdio.h>
#include <stdlib.h>

// Structure to represent a job
typedef struct {
    int duration; // Time taken to complete the job
    int deadline; // Deadline for the job
} Job;

// Function to compare two jobs based on their deadlines
int compareJobs(const void *a, const void *b) {
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    return jobA->deadline - jobB->deadline;
}

int main() {
    int N;
    scanf("%d", &N);

    // Allocate memory for the jobs
    Job *jobs = (Job *)malloc(N * sizeof(Job));

    // Read the job details from the input
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &jobs[i].duration, &jobs[i].deadline);
    }

    // Sort the jobs in ascending order of their deadlines
    qsort(jobs, N, sizeof(Job), compareJobs);

    // Initialize current time to 0
    int currentTime = 0;

    // Check if all jobs can be completed in time
    for (int i = 0; i < N; i++) {
        // If the current time plus the job duration exceeds the deadline, it's not possible
        if (currentTime + jobs[i].duration > jobs[i].deadline) {
            printf("No\n");
            free(jobs);
            return 0;
        }

        // Update the current time to the completion time of the current job
        currentTime += jobs[i].duration;
    }

    // All jobs can be completed in time
    printf("Yes\n");

    // Free the allocated memory
    free(jobs);

    return 0;
}