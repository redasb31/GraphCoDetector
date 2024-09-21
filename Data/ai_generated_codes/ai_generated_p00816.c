#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the sum of the numbers in an array
int calculateSum(int* arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function to check if a combination of numbers is valid
// It checks if the sum of the numbers is less than or equal to the target number
int isValidCombination(int* arr, int n, int target) {
    return calculateSum(arr, n) <= target;
}

// Function to find the closest combination of numbers to the target number
// It returns the sum of the closest combination if found, otherwise it returns -1
int findClosestCombination(int* arr, int n, int target, int* closestCombination) {
    int maxSum = -1;
    int numCombinations = 0;

    // Iterate through all possible combinations of numbers
    for (int i = 1; i < (1 << n); i++) {
        // Create an array to store the current combination
        int combination[n];
        int combinationIndex = 0;

        // Iterate through the bits of the current combination
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                combination[combinationIndex++] = arr[j];
            }
        }

        // Check if the current combination is valid
        if (isValidCombination(combination, combinationIndex, target)) {
            // Calculate the sum of the current combination
            int currentSum = calculateSum(combination, combinationIndex);

            // If the sum of the current combination is greater than the previous maximum sum
            // update the maximum sum and the closest combination
            if (currentSum > maxSum) {
                maxSum = currentSum;
                numCombinations = 1;
                memcpy(closestCombination, combination, sizeof(combination));
            } else if (currentSum == maxSum) {
                // If there is more than one combination with the same maximum sum
                // increment the number of combinations
                numCombinations++;
            }
        }
    }

    // If there is only one combination with the maximum sum
    if (numCombinations == 1) {
        return maxSum;
    } else {
        // If there are multiple combinations with the same maximum sum
        // return -1
        return -1;
    }
}

// Function to convert a string to an integer
int stringToInt(const char* str) {
    return atoi(str);
}

int main() {
    char targetNumStr[10];
    char shredNumStr[10];

    while (1) {
        scanf("%s %s", targetNumStr, shredNumStr);

        // Check if the input is 0 0, which signals the end of the input
        if (strcmp(targetNumStr, "0") == 0 && strcmp(shredNumStr, "0") == 0) {
            break;
        }

        // Convert the target number and the shred number from strings to integers
        int targetNum = stringToInt(targetNumStr);
        int shredNum = stringToInt(shredNumStr);

        // If the target number is the same as the shred number
        // print the shred number without any changes
        if (targetNum == shredNum) {
            printf("%d %d\n", shredNum, shredNum);
        } else {
            // Create an array to store the digits of the shred number
            int digits[6];
            int digitIndex = 0;

            // Extract the digits of the shred number
            while (shredNum > 0) {
                digits[digitIndex++] = shredNum % 10;
                shredNum /= 10;
            }

            // Create an array to store the closest combination of numbers
            int closestCombination[6];

            // Find the closest combination of numbers
            int closestSum = findClosestCombination(digits, digitIndex, targetNum, closestCombination);

            // If the closest sum is -1, it means there are multiple combinations with the same maximum sum
            // print "rejected"
            if (closestSum == -1) {
                printf("rejected\n");
            } else if (closestSum == -2) {
                // If the closest sum is -2, it means there is no valid combination
                // print "error"
                printf("error\n");
            } else {
                // Print the closest combination of numbers
                printf("%d ", closestSum);
                for (int i = 0; i < digitIndex; i++) {
                    printf("%d ", closestCombination[i]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}