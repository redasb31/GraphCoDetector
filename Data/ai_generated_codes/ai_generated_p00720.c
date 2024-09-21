#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ROBOTS 100
#define MAX_TIME 1000
#define MAX_DISTANCE 10
#define EPSILON 1e-6

typedef struct {
    char nickname[9];
    int num_points;
    int times[MAX_TIME];
    int x[MAX_TIME];
    int y[MAX_TIME];
} Robot;

Robot robots[MAX_ROBOTS];
int num_robots;
int simulation_time;
int max_distance;

// Calculate the distance between two robots at a given time
double distance(Robot robot1, Robot robot2, int time) {
    int i, j;
    int x1, y1, x2, y2;

    // Find the indices of the time intervals containing the given time
    for (i = 0; i < robot1.num_points; i++) {
        if (robot1.times[i] > time) {
            break;
        }
    }
    for (j = 0; j < robot2.num_points; j++) {
        if (robot2.times[j] > time) {
            break;
        }
    }

    // Calculate the coordinates of the robots at the given time
    x1 = robot1.x[i - 1] + (time - robot1.times[i - 1]) * (robot1.x[i] - robot1.x[i - 1]) / (robot1.times[i] - robot1.times[i - 1]);
    y1 = robot1.y[i - 1] + (time - robot1.times[i - 1]) * (robot1.y[i] - robot1.y[i - 1]) / (robot1.times[i] - robot1.times[i - 1]);
    x2 = robot2.x[j - 1] + (time - robot2.times[j - 1]) * (robot2.x[j] - robot2.x[j - 1]) / (robot2.times[j] - robot2.times[j - 1]);
    y2 = robot2.y[j - 1] + (time - robot2.times[j - 1]) * (robot2.y[j] - robot2.y[j - 1]) / (robot2.times[j] - robot2.times[j - 1]);

    // Return the distance
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

// Check if two robots are within communication range at a given time
int in_range(Robot robot1, Robot robot2, int time) {
    return distance(robot1, robot2, time) <= max_distance;
}

// Simulate the spread of information among robots
void simulate() {
    // Initialize a boolean array to track which robots have received data
    int received_data[MAX_ROBOTS] = {0};
    received_data[0] = 1; // The first robot starts with data

    // Iterate over time
    for (int time = 0; time <= simulation_time; time++) {
        // Iterate over all robots
        for (int i = 0; i < num_robots; i++) {
            // If a robot has received data, it can transmit it to others in range
            if (received_data[i]) {
                for (int j = 0; j < num_robots; j++) {
                    // Check if the robots are in range and the other robot hasn't received data yet
                    if (i != j && in_range(robots[i], robots[j], time) && !received_data[j]) {
                        received_data[j] = 1; // Mark the robot as having received data
                    }
                }
            }
        }
    }

    // Print the nicknames of robots that have received data
    for (int i = 0; i < num_robots; i++) {
        if (received_data[i]) {
            printf("%s\n", robots[i].nickname);
        }
    }
}

int main() {
    while (1) {
        // Read input data
        scanf("%d %d %d", &num_robots, &simulation_time, &max_distance);

        // Check for end of input
        if (num_robots == 0 && simulation_time == 0 && max_distance == 0) {
            break;
        }

        // Read robot data
        for (int i = 0; i < num_robots; i++) {
            scanf("%s", robots[i].nickname);
            scanf("%d %d %d", &robots[i].times[0], &robots[i].x[0], &robots[i].y[0]);
            robots[i].num_points = 1;
            while (1) {
                int ti, vxi, vyi;
                scanf("%d %d %d", &ti, &vxi, &vyi);
                if (ti == simulation_time) {
                    break;
                }
                robots[i].times[robots[i].num_points] = ti;
                robots[i].x[robots[i].num_points] = robots[i].x[robots[i].num_points - 1] + vxi * (ti - robots[i].times[robots[i].num_points - 1]);
                robots[i].y[robots[i].num_points] = robots[i].y[robots[i].num_points - 1] + vyi * (ti - robots[i].times[robots[i].num_points - 1]);
                robots[i].num_points++;
            }
        }

        // Simulate and print results
        simulate();
    }

    return 0;
}