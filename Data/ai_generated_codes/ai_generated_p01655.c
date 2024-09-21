#include <stdio.h>
#include <string.h>
#include <limits.h>

// Function to calculate the Hamming distance between two strings
int hammingDistance(char *str1, char *str2, int l) {
    int distance = 0;
    for (int i = 0; i < l; i++) {
        if (str1[i] != str2[i]) {
            distance++;
        }
    }
    return distance;
}

// Function to find the lexicographically minimum string
char *findLexicographicallyMinimumString(char *str1, char *str2, char *str3, int l, int d) {
    char *minString = NULL;
    int minDistance = INT_MAX;

    // Iterate through all possible combinations of strings
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            for (int k = 0; k < l; k++) {
                // Calculate the Hamming distance between the current combination and each of the input strings
                int distance1 = hammingDistance(str1, str1 + i, l);
                int distance2 = hammingDistance(str2, str2 + j, l);
                int distance3 = hammingDistance(str3, str3 + k, l);

                // Check if the total Hamming distance is within the allowed limit
                if (distance1 <= d && distance2 <= d && distance3 <= d) {
                    // If the current combination has a lower Hamming distance or is lexicographically smaller than the current minimum string, update the minimum string
                    if (distance1 + distance2 + distance3 < minDistance || (distance1 + distance2 + distance3 == minDistance && strncmp(str1 + i, minString, l) < 0)) {
                        minDistance = distance1 + distance2 + distance3;
                        minString = str1 + i;
                    }
                }
            }
        }
    }

    return minString;
}

int main() {
    int l, d;

    // Read input until encountering two zeros
    while (scanf("%d %d", &l, &d) != EOF && (l != 0 || d != 0)) {
        char str1[100001], str2[100001], str3[100001];

        // Read the three strings
        scanf("%s", str1);
        scanf("%s", str2);
        scanf("%s", str3);

        // Find the lexicographically minimum string
        char *originalString = findLexicographicallyMinimumString(str1, str2, str3, l, d);

        // Print the original string or -1 if no valid string exists
        if (originalString != NULL) {
            printf("%s\n", originalString);
        } else {
            printf("-1\n");
        }
    }

    return 0;
}