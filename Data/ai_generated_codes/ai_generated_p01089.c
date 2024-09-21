#include <stdio.h>
#include <string.h>

#define MAX_THREADS 10
#define MAX_INSTRUCTIONS 10000

// Structure to represent a thread's state
typedef struct {
    int currentInstruction; // Index of the current instruction
    int locksHeld[10];     // Array to track held locks (1 if held, 0 otherwise)
} Thread;

// Function to check if a deadlock has occurred
int isDeadlock(Thread threads[MAX_THREADS], int n, char *sequence) {
    int i;

    // Check if all threads are blocked on acquiring a lock
    for (i = 0; i < MAX_THREADS; i++) {
        if (threads[i].currentInstruction < n) {
            // If a thread is not finished and its next instruction is a lock
            // and the lock is already held, it's blocked
            if (sequence[threads[i].currentInstruction] >= '0' &&
                sequence[threads[i].currentInstruction] <= '9' &&
                threads[i].locksHeld[sequence[threads[i].currentInstruction] - '0'] == 1) {
                return 1; // Deadlock detected
            }
        }
    }

    return 0; // No deadlock
}

// Function to simulate thread execution
int simulateExecution(char *sequence, int n) {
    Thread threads[MAX_THREADS] = {{0}}; // Initialize threads
    int currentThread = 0;              // Start with thread 0

    while (threads[currentThread].currentInstruction < n) {
        // Get the next instruction
        char instruction = sequence[threads[currentThread].currentInstruction];

        // Process the instruction
        if (instruction >= '0' && instruction <= '9') {
            // Acquire lock if not held
            if (threads[currentThread].locksHeld[instruction - '0'] == 0) {
                threads[currentThread].locksHeld[instruction - '0'] = 1;
                threads[currentThread].currentInstruction++;
            }
        } else if (instruction == 'u') {
            // Release all held locks
            for (int i = 0; i < 10; i++) {
                threads[currentThread].locksHeld[i] = 0;
            }
            threads[currentThread].currentInstruction++;
        }

        // Check for deadlock after each instruction
        if (isDeadlock(threads, n, sequence)) {
            return 0; // Unsafe sequence
        }

        // Move to the next thread (round-robin)
        currentThread = (currentThread + 1) % MAX_THREADS;
    }

    return 1; // Safe sequence
}

int main() {
    int n;
    char sequence[MAX_INSTRUCTIONS + 1];

    while (1) {
        scanf("%d\n", &n);

        if (n == 0) {
            break;
        }

        scanf("%s", sequence);

        // Check for safety
        if (simulateExecution(sequence, n)) {
            printf("SAFE\n");
        } else {
            printf("UNSAFE\n");
        }
    }

    return 0;
}