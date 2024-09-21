#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is a palindrome
bool isPalindrome(int num) {
    // Convert the number to a string
    char str[10];
    sprintf(str, "%d", num);

    // Compare the string with its reverse
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int A, B;
    scanf("%d %d", &A, &B);

    // Count the number of palindromic numbers
    int count = 0;
    for (int i = A; i <= B; i++) {
        if (isPalindrome(i)) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}