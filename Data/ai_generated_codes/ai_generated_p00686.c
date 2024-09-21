#include <stdio.h>
#include <string.h>

// Structure to represent the robot's state
typedef struct {
    int x; // Current x-coordinate
    int y; // Current y-coordinate
    int direction; // Facing direction (0: North, 1: East, 2: South, 3: West)
} Robot;

// Function to initialize the robot at the starting position
void init_robot(Robot *robot) {
    robot->x = 1;
    robot->y = 1;
    robot->direction = 0; // Facing North
}

// Function to process a FORWARD command
void forward(Robot *robot, int steps, int m, int n) {
    int i;
    for (i = 0; i < steps; i++) {
        switch (robot->direction) {
            case 0: // North
                if (robot->y < n) {
                    robot->y++;
                } else {
                    break; // Hit the wall
                }
                break;
            case 1: // East
                if (robot->x < m) {
                    robot->x++;
                } else {
                    break; // Hit the wall
                }
                break;
            case 2: // South
                if (robot->y > 1) {
                    robot->y--;
                } else {
                    break; // Hit the wall
                }
                break;
            case 3: // West
                if (robot->x > 1) {
                    robot->x--;
                } else {
                    break; // Hit the wall
                }
                break;
        }
    }
}

// Function to process a BACKWARD command
void backward(Robot *robot, int steps, int m, int n) {
    int i;
    for (i = 0; i < steps; i++) {
        switch (robot->direction) {
            case 0: // North
                if (robot->y > 1) {
                    robot->y--;
                } else {
                    break; // Hit the wall
                }
                break;
            case 1: // East
                if (robot->x > 1) {
                    robot->x--;
                } else {
                    break; // Hit the wall
                }
                break;
            case 2: // South
                if (robot->y < n) {
                    robot->y++;
                } else {
                    break; // Hit the wall
                }
                break;
            case 3: // West
                if (robot->x < m) {
                    robot->x++;
                } else {
                    break; // Hit the wall
                }
                break;
        }
    }
}

// Function to process a RIGHT command
void right(Robot *robot) {
    robot->direction = (robot->direction + 1) % 4;
}

// Function to process a LEFT command
void left(Robot *robot) {
    robot->direction = (robot->direction + 3) % 4;
}

int main() {
    int m, n;
    char command[50];
    Robot robot;

    while (1) {
        // Read the field size
        if (scanf("%d %d", &m, &n) != 2 || (m == 0 && n == 0)) {
            break; // End of input
        }

        // Initialize the robot
        init_robot(&robot);

        // Read and execute commands
        while (1) {
            scanf("%s", command);
            if (strcmp(command, "STOP") == 0) {
                break; // End of command sequence
            }

            if (strncmp(command, "FORWARD", 7) == 0) {
                int steps;
                sscanf(command, "FORWARD %d", &steps);
                forward(&robot, steps, m, n);
            } else if (strncmp(command, "BACKWARD", 8) == 0) {
                int steps;
                sscanf(command, "BACKWARD %d", &steps);
                backward(&robot, steps, m, n);
            } else if (strcmp(command, "RIGHT") == 0) {
                right(&robot);
            } else if (strcmp(command, "LEFT") == 0) {
                left(&robot);
            }
        }

        // Print the final coordinates of the robot
        printf("%d %d\n", robot.x, robot.y);
    }

    return 0;
}