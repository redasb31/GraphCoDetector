#include <stdio.h>

// Function to calculate the n-th Fibonacci number
int fibonacci(int n) {
    // Base cases for n = 0 and n = 1
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        // Recursive step: Calculate the n-th Fibonacci number 
        // by summing the (n-1)-th and (n-2)-th Fibonacci numbers
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n; // Declare an integer variable 'n' to store the input

    // Prompt the user to enter an integer
    printf("Enter an integer (0 <= n <= 44): ");
    scanf("%d", &n); // Read the input integer and store it in 'n'

    // Calculate the n-th Fibonacci number using the 'fibonacci' function
    int result = fibonacci(n);

    // Print the calculated n-th Fibonacci number
    printf("%d\n", result);

    return 0; // Indicate successful program execution
}