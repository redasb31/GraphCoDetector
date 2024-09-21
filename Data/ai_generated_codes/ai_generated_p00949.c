#include <stdio.h>
#include <string.h>

// Function to check if two strings are anagrams
int isAnagram(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // If lengths are different, they can't be anagrams
    if (len1 != len2) {
        return 0;
    }

    // Create an array to store the frequency of each character in str1
    int charCount[26] = {0};
    for (int i = 0; i < len1; i++) {
        charCount[str1[i] - 'a']++;
    }

    // Decrement the count for each character in str2
    for (int i = 0; i < len2; i++) {
        charCount[str2[i] - 'a']--;
    }

    // If all counts are zero, they are anagrams
    for (int i = 0; i < 26; i++) {
        if (charCount[i] != 0) {
            return 0;
        }
    }

    return 1;
}

// Function to find the length of the longest hidden anagram
int longestHiddenAnagram(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int maxLength = 0;

    // Iterate through all possible substrings of str1
    for (int i = 0; i < len1; i++) {
        for (int j = i + 1; j <= len1; j++) {
            // Extract the substring from str1
            char *substring1 = str1 + i;
            substring1[j - i] = '\0'; // Null-terminate the substring

            // Iterate through all possible substrings of str2
            for (int k = 0; k < len2; k++) {
                for (int l = k + 1; l <= len2; l++) {
                    // Extract the substring from str2
                    char *substring2 = str2 + k;
                    substring2[l - k] = '\0'; // Null-terminate the substring

                    // Check if the substrings are anagrams
                    if (isAnagram(substring1, substring2)) {
                        // Update maxLength if the current anagram is longer
                        maxLength = (j - i) > maxLength ? (j - i) : maxLength;
                    }
                }
            }
        }
    }

    return maxLength;
}

int main() {
    char str1[4001], str2[4001];

    // Read input strings
    fgets(str1, sizeof(str1), stdin);
    fgets(str2, sizeof(str2), stdin);

    // Remove newline characters from input strings
    str1[strcspn(str1, "\n")] = 0;
    str2[strcspn(str2, "\n")] = 0;

    // Find the length of the longest hidden anagram
    int maxLength = longestHiddenAnagram(str1, str2);

    // Print the result
    printf("%d\n", maxLength);

    return 0;
}