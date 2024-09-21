#include <stdio.h>
#include <string.h>

// Function to determine if a string is balanced
int isBalanced(char *str) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == '(') {
            count++;
        } else {
            count--;
        }
        if (count < 0) {
            return 0; // Unbalanced
        }
    }
    return (count == 0); // Balanced if count is 0
}

// Function to generate Dave's string
void generateString(int A) {
    char str[A * 2 + 1];
    int left = 0; // Number of '('
    int right = 0; // Number of ')'
    int swaps = 0; // Number of swaps made

    // Build the string starting with '(', ')', '(', ')', ...
    for (int i = 0; i < A; i++) {
        str[2 * i] = '(';
        str[2 * i + 1] = ')';
        left++;
        right++;
    }

    // Swap adjacent characters to get the minimum lexicographic string
    // and ensure the string is balanced after A swaps
    str[2 * A] = '\0'; // Null terminator
    while (swaps < A) {
        // Find the first ')(' substring
        for (int i = 0; str[i]; i++) {
            if (str[i] == ')' && str[i + 1] == '(') {
                // Swap adjacent characters
                str[i] = '(';
                str[i + 1] = ')';
                swaps++;
                left++;
                right--;
                break;
            }
        }

        // Check if the string is balanced after each swap
        if (isBalanced(str)) {
            printf("%s\n", str);
            return;
        }
    }

    // If the string is not balanced after A swaps, adjust '(' and ')' positions
    // to find the lexicographically minimum balanced string
    if (left > right) {
        // Move '(' from the right side to the left side
        for (int i = 2 * A - 1; i >= 0; i--) {
            if (str[i] == '(') {
                for (int j = 0; j < i; j++) {
                    if (str[j] == ')') {
                        str[i] = ')';
                        str[j] = '(';
                        left--;
                        right++;
                        break;
                    }
                }
            }
            if (left == right) {
                break;
            }
        }
    } else if (left < right) {
        // Move ')' from the left side to the right side
        for (int i = 0; str[i]; i++) {
            if (str[i] == ')') {
                for (int j = i + 1; str[j]; j++) {
                    if (str[j] == '(') {
                        str[i] = '(';
                        str[j] = ')';
                        left++;
                        right--;
                        break;
                    }
                }
            }
            if (left == right) {
                break;
            }
        }
    }
    printf("%s\n", str);
}

int main() {
    int A;
    scanf("%d", &A);
    generateString(A);
    return 0;
}