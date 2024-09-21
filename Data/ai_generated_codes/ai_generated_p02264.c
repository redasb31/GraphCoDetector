#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Process {
    char name[11]; // Maximum name length is 10
    int time;
    struct Process *next;
} Process;

// Function to create a new process node
Process* createProcess(char *name, int time) {
    Process *newProcess = (Process*)malloc(sizeof(Process));
    strcpy(newProcess->name, name);
    newProcess->time = time;
    newProcess->next = NULL;
    return newProcess;
}

// Function to insert a process at the end of the queue
void enqueue(Process **head, Process *newProcess) {
    if (*head == NULL) {
        *head = newProcess;
        return;
    }

    Process *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newProcess;
}

// Function to remove a process from the front of the queue
Process* dequeue(Process **head) {
    if (*head == NULL) {
        return NULL;
    }

    Process *temp = *head;
    *head = (*head)->next;
    return temp;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    Process *head = NULL; // Head of the process queue

    // Read process information from input
    for (int i = 0; i < n; i++) {
        char name[11];
        int time;
        scanf("%s %d", name, &time);
        Process *newProcess = createProcess(name, time);
        enqueue(&head, newProcess);
    }

    int totalTime = 0; // Total time taken for all processes

    // Round-Robin scheduling
    while (head != NULL) {
        Process *currentProcess = dequeue(&head); // Get the process from the front

        // Process the current process for the quantum
        if (currentProcess->time > q) {
            totalTime += q;
            currentProcess->time -= q; // Update remaining time

            // Add the process back to the end of the queue
            enqueue(&head, currentProcess); 
        } else {
            totalTime += currentProcess->time; // Process completed in this quantum

            // Print the process name and finish time
            printf("%s %d\n", currentProcess->name, totalTime);

            free(currentProcess); // Free the memory for the completed process
        }
    }

    return 0;
}