#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

// Function to calculate the difference between two passwords
int calculateDifference(char *oldPassword, char *newPassword, int n) {
    int oldInt = atoi(oldPassword);
    int newInt = atoi(newPassword);
    int diff = abs(oldInt - newInt);
    return (diff < (1 << n) - diff) ? diff : (1 << n) - diff;
}

// Function to generate a new password
char *generateNewPassword(char *oldPassword, int n) {
    // Create an array to store the frequency of each digit
    int frequency[10] = {0};
    for (int i = 0; i < n; i++) {
        frequency[oldPassword[i] - '0']++;
    }

    // Create a new password string
    char *newPassword = (char *)malloc((n + 1) * sizeof(char));
    if (newPassword == NULL) {
        return NULL;
    }
    
    // Initialize the new password with '0's
    memset(newPassword, '0', n);
    newPassword[n] = '\0';

    // Find the digit with the maximum frequency
    int maxDigit = 0;
    int maxFrequency = frequency[0];
    for (int i = 1; i < 10; i++) {
        if (frequency[i] > maxFrequency) {
            maxDigit = i;
            maxFrequency = frequency[i];
        }
    }

    // Find the digit with the maximum frequency in the new password
    int newPasswordFrequency[10] = {0};
    for (int i = 0; i < n; i++) {
        newPasswordFrequency[newPassword[i] - '0']++;
    }
    int maxDigitNewPassword = 0;
    int maxFrequencyNewPassword = newPasswordFrequency[0];
    for (int i = 1; i < 10; i++) {
        if (newPasswordFrequency[i] > maxFrequencyNewPassword) {
            maxDigitNewPassword = i;
            maxFrequencyNewPassword = newPasswordFrequency[i];
        }
    }

    // Fill the new password with digits, starting from the maximum frequency digit
    int digitIndex = 0;
    for (int i = 0; i < 10; i++) {
        if (frequency[i] > 0) {
            for (int j = 0; j < frequency[i]; j++) {
                newPassword[digitIndex++] = i + '0';
            }
        }
    }
    // If new password is 000..0, swap last digit with first digit
    if (digitIndex == n) {
        int tmp = newPassword[0];
        newPassword[0] = newPassword[n - 1];
        newPassword[n - 1] = tmp;
    }

    // Find the best candidate new password
    char *bestPassword = strdup(newPassword);
    int bestDifference = calculateDifference(oldPassword, bestPassword, n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Swap digits
            char temp = newPassword[i];
            newPassword[i] = newPassword[j];
            newPassword[j] = temp;
            
            // Calculate the difference
            int currentDifference = calculateDifference(oldPassword, newPassword, n);

            // Update the best password if the difference is smaller
            if (currentDifference < bestDifference) {
                bestDifference = currentDifference;
                free(bestPassword);
                bestPassword = strdup(newPassword);
            } else if (currentDifference == bestDifference && atoi(newPassword) < atoi(bestPassword)) {
                free(bestPassword);
                bestPassword = strdup(newPassword);
            }

            // Swap digits back
            temp = newPassword[i];
            newPassword[i] = newPassword[j];
            newPassword[j] = temp;
        }
    }

    free(newPassword);
    return bestPassword;
}

int main() {
    char oldPassword[11];
    scanf("%s", oldPassword);
    int n = strlen(oldPassword);

    char *newPassword = generateNewPassword(oldPassword, n);
    if (newPassword != NULL) {
        printf("%s\n", newPassword);
        free(newPassword);
    } else {
        printf("Error allocating memory.\n");
    }

    return 0;
}