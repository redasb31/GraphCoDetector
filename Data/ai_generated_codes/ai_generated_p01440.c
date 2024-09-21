#include <stdio.h>
#include <string.h>

// Function to calculate the position of the first occurrence of the sequence S in Champernowne constant
long long find_position(char *S) {
    long long position = 0; // Initialize the position
    int len = strlen(S);  // Length of the sequence
    int digits = 1; // Number of digits in the current number
    int current_number = 1; // The current number being concatenated
    int i = 0;  // Index for iterating through the sequence

    while (i < len) {
        // Calculate the number of digits in the current number
        int num_digits = digits;
        if (current_number >= 10) {
            num_digits = 1;
            while (current_number / 10) {
                current_number /= 10;
                num_digits++;
            }
        }

        // Check if the current number has enough digits to match the sequence
        if (num_digits >= len - i) {
            // Compare the current number with the remaining sequence
            char temp[100]; // Temporary array to store the digits of the current number
            int j = 0;
            int current = current_number;
            while (current) {
                temp[j++] = current % 10 + '0';
                current /= 10;
            }
            temp[j] = '\0';
            // Reverse the digits of the current number
            int start = 0, end = j - 1;
            while (start < end) {
                char tmp = temp[start];
                temp[start] = temp[end];
                temp[end] = tmp;
                start++;
                end--;
            }

            // Check if the remaining sequence matches the digits of the current number
            for (; i < len; i++) {
                if (temp[i - position - digits] != S[i]) {
                    break;
                }
            }
            // If the sequence is matched, break the loop
            if (i == len) {
                break;
            }
        }
        // Update the position and the current number
        position += digits;
        current_number++;
        // Update the number of digits for the next number
        if (current_number == 10) {
            digits++;
            current_number = 1;
        }
    }
    // Return the final position
    return position;
}

int main() {
    char S[101];
    while (1) {
        scanf("%s", S);
        if (strcmp(S, "#") == 0) {
            break;
        }
        printf("%lld\n", find_position(S));
    }
    return 0;
}