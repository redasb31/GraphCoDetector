#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 128
#define MAX_QUERIES 850

int editDistance(char *s1, char *s2, int len1, int len2) {
    // Create a 2D array to store edit distances
    int dp[len1 + 1][len2 + 1];

    // Initialize the first row and column
    for (int i = 0; i <= len1; ++i) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= len2; ++j) {
        dp[0][j] = j;
    }

    // Calculate edit distances for each substring
    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
            }
        }
    }

    // Return the edit distance between the entire strings
    return dp[len1][len2];
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    char query[MAX_LEN + 1];
    int queries = 0;
    int edit_dist;

    // Guess a random password to start
    char password[MAX_LEN + 1] = "a";

    while (queries < MAX_QUERIES) {
        // Ask the query
        printf("? %s\n", password);
        fflush(stdout);

        // Get the edit distance from the judge
        scanf("%d", &edit_dist);

        // If edit distance is 0, we found the password
        if (edit_dist == 0) {
            printf("! %s\n", password);
            fflush(stdout);
            return 0;
        }

        // Modify the password based on the edit distance
        // This is a simple strategy, more sophisticated approaches can be used
        if (edit_dist == 1) {
            // Try adding a character to the password
            for (int i = 0; i < 26; ++i) {
                password[strlen(password)] = 'a' + i;
                printf("? %s\n", password);
                fflush(stdout);
                scanf("%d", &edit_dist);
                if (edit_dist == 0) {
                    printf("! %s\n", password);
                    fflush(stdout);
                    return 0;
                }
                password[strlen(password) - 1] = '\0';
            }
            // Try replacing a character in the password
            for (int i = 0; i < strlen(password); ++i) {
                for (int j = 0; j < 26; ++j) {
                    password[i] = 'a' + j;
                    printf("? %s\n", password);
                    fflush(stdout);
                    scanf("%d", &edit_dist);
                    if (edit_dist == 0) {
                        printf("! %s\n", password);
                        fflush(stdout);
                        return 0;
                    }
                    password[i] = 'a' + i;
                }
            }
        } else {
            // Try removing a character from the password
            for (int i = 0; i < strlen(password); ++i) {
                char tmp[MAX_LEN + 1];
                strcpy(tmp, password);
                tmp[i] = '\0';
                printf("? %s\n", tmp);
                fflush(stdout);
                scanf("%d", &edit_dist);
                if (edit_dist == 0) {
                    printf("! %s\n", tmp);
                    fflush(stdout);
                    return 0;
                }
            }
        }

        queries++;
    }

    return 0;
}