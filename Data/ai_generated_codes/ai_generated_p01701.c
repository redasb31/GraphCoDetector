#include <stdio.h>
#include <string.h>

// Function to calculate the angle of a given direction
int calculateAngle(char *direction) {
    int angle = 0; // Initial angle
    int n = 0; // Count of "north" and "west"
    int i = 0;

    // Iterate through the direction string
    while (direction[i] != '\0') {
        if (direction[i] == 'n') {
            // If "north", decrement angle by 90 / 2^n
            angle -= 90 / (1 << n);
        } else if (direction[i] == 'w') {
            // If "west", increment angle by 90 / 2^n
            angle += 90 / (1 << n);
        }
        n++; // Increment the count of "north" and "west"
        i++;
    }

    // Return the angle
    return angle;
}

// Function to print the angle in the desired format
void printAngle(int angle) {
    // If angle is divisible by 90, print as an integer
    if (angle % 90 == 0) {
        printf("%d\n", angle);
    } else {
        // Otherwise, print as an irreducible fraction
        int numerator = angle;
        int denominator = 1;
        // Find the greatest common divisor (GCD)
        while (numerator % denominator != 0) {
            int temp = numerator % denominator;
            numerator = denominator;
            denominator = temp;
        }
        // Print the fraction
        printf("%d/%d\n", angle / denominator, 90 / denominator);
    }
}

int main() {
    char direction[100]; // Buffer to store the direction string

    // Read input until '#' is encountered
    while (scanf("%s", direction) != EOF && strcmp(direction, "#") != 0) {
        // Calculate the angle
        int angle = calculateAngle(direction);
        // Print the angle
        printAngle(angle);
    }

    return 0;
}