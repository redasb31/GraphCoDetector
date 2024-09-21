#include <stdio.h>
#include <stdlib.h>

// Structure to represent a resource
typedef struct {
    int instances; // Number of available instances
    int total_instances; // Total number of instances
} Resource;

// Structure to represent a process
typedef struct {
    int id; // Process ID
    int *needs; // Number of instances needed for each resource
    int acquired[300]; // Array to track acquired instances for each resource
} Process;

// Function to initialize resources
void init_resources(Resource *resources, int r, int *l) {
    for (int i = 0; i < r; i++) {
        resources[i].instances = l[i];
        resources[i].total_instances = l[i];
    }
}

// Function to initialize processes
void init_processes(Process *processes, int p, int r, int **n) {
    for (int i = 0; i < p; i++) {
        processes[i].id = i + 1;
        processes[i].needs = n[i];
        for (int j = 0; j < r; j++) {
            processes[i].acquired[j] = 0;
        }
    }
}

// Function to check if a process can acquire a resource
int can_acquire(Process *process, Resource *resources, int resource_id) {
    return resources[resource_id].instances > 0 &&
           process->acquired[resource_id] < process->needs[resource_id];
}

// Function to acquire a resource instance
void acquire(Process *process, Resource *resources, int resource_id) {
    process->acquired[resource_id]++;
    resources[resource_id].instances--;
}

// Function to check for deadlock
int is_deadlock(Process *processes, Resource *resources, int p, int r) {
    // Create a temporary copy of the resources array
    Resource *temp_resources = malloc(sizeof(Resource) * r);
    for (int i = 0; i < r; i++) {
        temp_resources[i] = resources[i];
    }

    // Create a temporary copy of the processes array
    Process *temp_processes = malloc(sizeof(Process) * p);
    for (int i = 0; i < p; i++) {
        temp_processes[i] = processes[i];
    }

    // Initialize a flag to track if any process can acquire resources
    int can_acquire_flag = 1;

    // Keep trying to acquire resources until no process can acquire anything
    while (can_acquire_flag) {
        can_acquire_flag = 0;
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < r; j++) {
                if (can_acquire(&temp_processes[i], temp_resources, j)) {
                    acquire(&temp_processes[i], temp_resources, j);
                    can_acquire_flag = 1;
                }
            }
        }
    }

    // Check if any process has unmet needs
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < r; j++) {
            if (temp_processes[i].needs[j] > temp_processes[i].acquired[j]) {
                free(temp_processes);
                free(temp_resources);
                return 1; // Deadlock detected
            }
        }
    }

    // No deadlock detected
    free(temp_processes);
    free(temp_resources);
    return 0;
}

int main() {
    int p, r, t;
    scanf("%d %d %d", &p, &r, &t);

    // Read initial available instances of each resource
    int *l = malloc(sizeof(int) * r);
    for (int i = 0; i < r; i++) {
        scanf("%d", &l[i]);
    }

    // Read number of instances needed by each process
    int **n = malloc(sizeof(int *) * p);
    for (int i = 0; i < p; i++) {
        n[i] = malloc(sizeof(int) * r);
        for (int j = 0; j < r; j++) {
            scanf("%d", &n[i][j]);
        }
    }

    // Initialize resources
    Resource *resources = malloc(sizeof(Resource) * r);
    init_resources(resources, r, l);

    // Initialize processes
    Process *processes = malloc(sizeof(Process) * p);
    init_processes(processes, p, r, n);

    // Process the resource allocation log
    int deadlock_time = -1;
    for (int i = 1; i <= t; i++) {
        int process_id, resource_id;
        scanf("%d %d", &process_id, &resource_id);

        // Acquire the resource
        acquire(&processes[process_id - 1], resources, resource_id - 1);

        // Check for deadlock
        if (is_deadlock(processes, resources, p, r)) {
            deadlock_time = i;
            break;
        }
    }

    // Print the deadlock time
    printf("%d\n", deadlock_time);

    // Free allocated memory
    free(resources);
    free(processes);
    free(n);
    free(l);

    return 0;
}