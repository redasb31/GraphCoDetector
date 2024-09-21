#include <stdio.h>

int main() {
    // Declare variables to store the input integers
    int a, b;

    // Loop until the end of the input (EOF) is reached
    while (scanf("%d %d", &a, &b) != EOF) {
        // Calculate the sum of a and b
        int sum = a + b;

        // Print the sum to the console
        printf("%d\n", sum);
    }

    return 0;
}