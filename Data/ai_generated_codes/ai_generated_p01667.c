#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_COMMANDS 100
#define MAX_SKILLS 100

// Structure to store a condition
typedef struct {
    int skill;
    char cond[3];
    int threshold;
} Condition;

// Structure to store a command
typedef struct {
    int num_conditions;
    Condition conditions[MAX_SKILLS];
} Command;

int main() {
    int M, N; // Number of commands and skills
    int i, j, k;

    // Read the number of commands and skills
    scanf("%d %d", &M, &N);

    // Array to store commands
    Command commands[MAX_COMMANDS];

    // Read the conditions for each command
    for (i = 0; i < M; i++) {
        scanf("%d", &commands[i].num_conditions);
        for (j = 0; j < commands[i].num_conditions; j++) {
            scanf("%d %s %d", &commands[i].conditions[j].skill, 
                  commands[i].conditions[j].cond, 
                  &commands[i].conditions[j].threshold);
        }
    }

    // Array to store skill points
    int skill_points[MAX_SKILLS] = {0};

    // Flag to indicate whether all commands can be learned
    bool can_learn_all = true;

    // Iterate through each command
    for (i = 0; i < M; i++) {
        // Flag to indicate whether the current command can be learned
        bool can_learn_command = true;

        // Iterate through the conditions of the current command
        for (j = 0; j < commands[i].num_conditions; j++) {
            // Check if the condition is met
            if (strcmp(commands[i].conditions[j].cond, ">=") == 0) {
                if (skill_points[commands[i].conditions[j].skill - 1] < 
                    commands[i].conditions[j].threshold) {
                    can_learn_command = false;
                    break;
                }
            } else if (strcmp(commands[i].conditions[j].cond, "<=") == 0) {
                if (skill_points[commands[i].conditions[j].skill - 1] > 
                    commands[i].conditions[j].threshold) {
                    can_learn_command = false;
                    break;
                }
            }
        }

        // If the command cannot be learned, set the overall flag to false
        if (!can_learn_command) {
            can_learn_all = false;
            break;
        }

        // If the command can be learned, update the skill points
        for (j = 0; j < commands[i].num_conditions; j++) {
            skill_points[commands[i].conditions[j].skill - 1] = 
                commands[i].conditions[j].threshold;
        }
    }

    // Print the result
    if (can_learn_all) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}