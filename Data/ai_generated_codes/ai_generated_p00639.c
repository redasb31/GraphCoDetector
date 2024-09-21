#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to calculate the distance between two points
double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// Function to calculate the angle between two vectors
double angle(double x1, double y1, double x2, double y2) {
    return acos((x1 * x2 + y1 * y2) / (sqrt(x1 * x1 + y1 * y1) * sqrt(x2 * x2 + y2 * y2)));
}

// Function to check if the railgun hits the laboratory
int hit(double D, double px, double py, double vx, double vy) {
    // Calculate the initial distance from the starting point to the origin
    double initial_distance = distance(px, py, 0, 0);

    // Calculate the angle between the velocity vector and the line connecting the starting point and the origin
    double initial_angle = angle(vx, vy, -px, -py);

    // Calculate the angle between the velocity vector and the normal vector of the virtual wall
    double wall_angle = PI / 2 - initial_angle;

    // Calculate the distance the projectile travels until it hits the virtual wall
    double wall_distance = initial_distance / sin(wall_angle);

    // Calculate the distance the projectile travels until it hits the laboratory
    double lab_distance = wall_distance * cos(wall_angle);

    // Check if the railgun hits the laboratory within the range
    if (lab_distance <= D) {
        return lab_distance;
    } else {
        return -1;
    }
}

int main() {
    double D, px, py, vx, vy;

    // Loop through each dataset
    while (1) {
        scanf("%lf", &D);

        // Check if the input is the end of the file
        if (D == 0) {
            break;
        }

        // Read the coordinates and velocity vector
        scanf("%lf %lf %lf %lf", &px, &py, &vx, &vy);

        // Check if the railgun hits the laboratory
        int result = hit(D, px, py, vx, vy);

        // Print the result
        if (result == -1) {
            printf("impossible\n");
        } else {
            printf("%.8lf\n", result);
        }
    }

    return 0;
}