#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 70
#define MAX_HEIGHT 70

// Function to check if a character is a digit
int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

// Function to compare two strings representing numbers
int compareNumbers(const char *num1, const char *num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    // Compare lengths first
    if (len1 > len2) {
        return 1;
    } else if (len1 < len2) {
        return -1;
    }

    // Compare digit by digit
    for (int i = 0; i < len1; i++) {
        if (num1[i] > num2[i]) {
            return 1;
        } else if (num1[i] < num2[i]) {
            return -1;
        }
    }

    return 0; // Numbers are equal
}

// Function to find the secret number in the matrix
void findSecretNumber(char matrix[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    char currentNumber[MAX_WIDTH * MAX_HEIGHT];
    int currentNumberLength = 0;
    char largestNumber[MAX_WIDTH * MAX_HEIGHT] = ""; // Initialize with an empty string
    int largestNumberLength = 0;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (isDigit(matrix[i][j])) {
                currentNumber[currentNumberLength++] = matrix[i][j];

                // Check if the next digit is valid
                if (j + 1 < width && isDigit(matrix[i][j + 1])) {
                    // Next digit is to the right
                    continue;
                } else if (i + 1 < height && isDigit(matrix[i + 1][j])) {
                    // Next digit is below
                    continue;
                } else {
                    // End of a number sequence
                    currentNumber[currentNumberLength] = '\0';

                    // Compare with the largest number found so far
                    if (compareNumbers(currentNumber, largestNumber) > 0) {
                        strcpy(largestNumber, currentNumber);
                        largestNumberLength = currentNumberLength;
                    }

                    currentNumberLength = 0; // Reset for the next number
                }
            }
        }
    }

    // Print the largest number (the secret number)
    if (largestNumberLength > 0) {
        printf("%s\n", largestNumber);
    } else {
        printf("No secret number found.\n"); // Handle cases where no valid number is found
    }
}

int main() {
    int width, height;
    char matrix[MAX_HEIGHT][MAX_WIDTH];

    while (1) {
        scanf("%d %d", &width, &height);

        if (width == 0 && height == 0) {
            break;
        }

        // Read the matrix
        for (int i = 0; i < height; i++) {
            scanf("%s", matrix[i]);
        }

        findSecretNumber(matrix, width, height);
    }

    return 0;
}