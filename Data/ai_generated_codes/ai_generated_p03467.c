#include <stdio.h>
#include <string.h>

#define MOD 998244353

// Function to calculate the number of distinct encodings for a substring
long long count_encodings(char *s, int start, int end) {
    if (start == end) {
        return 1; // Empty string has one encoding
    }

    long long count = 0;
    long long current_count = 1; // Count for the current character
    int consecutive_ones = 0;

    for (int i = start; i < end; i++) {
        if (s[i] == '1') {
            consecutive_ones++;
            current_count = (current_count * 2) % MOD; // Each '1' doubles the count
        } else {
            // If we encounter a '0', add the current count to the total
            count = (count + current_count) % MOD;
            current_count = 1; // Reset the count for the next substring
            consecutive_ones = 0;
        }
    }
    count = (count + current_count) % MOD; // Add the final count for the last substring

    // Count encodings for substrings with consecutive '1's
    for (int i = 2; i <= consecutive_ones; i++) {
        count = (count + current_count) % MOD; // Add count for (1x2), (1x3), etc.
    }

    return count;
}

int main() {
    char s[101];
    scanf("%s", s);

    int n = strlen(s);
    long long total_encodings = 0;

    // Iterate through all possible substrings
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // Calculate encodings for the substring s[i:j]
            total_encodings = (total_encodings + count_encodings(s, i, j + 1)) % MOD;
        }
    }

    printf("%lld\n", total_encodings);
    return 0;
}