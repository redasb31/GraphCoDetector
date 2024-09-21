#include <stdio.h>
#include <string.h>

// Function to perform the bitwise AND and addition operation
void performOperation(char *takahashi, char *aoki, int k) {
    int n = strlen(takahashi);
    int m = strlen(aoki);
    int maxLen = (n > m) ? n : m;

    // Pad the shorter string with leading zeros
    if (n < maxLen) {
        char temp[maxLen + 1];
        memset(temp, '0', maxLen - n);
        strcpy(temp + maxLen - n, takahashi);
        strcpy(takahashi, temp);
    } else if (m < maxLen) {
        char temp[maxLen + 1];
        memset(temp, '0', maxLen - m);
        strcpy(temp + maxLen - m, aoki);
        strcpy(aoki, temp);
    }

    // Perform the operations for K iterations
    for (int i = 0; i < k; i++) {
        // Calculate the bitwise AND
        for (int j = 0; j < maxLen; j++) {
            if (takahashi[j] == '1' && aoki[j] == '1') {
                takahashi[j] = '1';
                aoki[j] = '1';
            } else {
                takahashi[j] = '0';
                aoki[j] = '0';
            }
        }

        // Add the result to both numbers
        for (int j = maxLen - 1; j >= 0; j--) {
            if (takahashi[j] == '1' && aoki[j] == '1') {
                takahashi[j] = '0';
                aoki[j] = '0';
                if (j > 0) {
                    takahashi[j - 1] = (takahashi[j - 1] == '0') ? '1' : '0';
                    aoki[j - 1] = (aoki[j - 1] == '0') ? '1' : '0';
                } else {
                    // Handle overflow by adding a leading '1'
                    char temp[maxLen + 2];
                    temp[0] = '1';
                    strcpy(temp + 1, takahashi);
                    strcpy(takahashi, temp);
                    temp[0] = '1';
                    strcpy(temp + 1, aoki);
                    strcpy(aoki, temp);
                }
            }
        }
    }
}

int main() {
    int n, m, k;
    char s[1000001], t[1000001];

    // Read input
    scanf("%d %d %d\n", &n, &m, &k);
    scanf("%s\n", s);
    scanf("%s", t);

    // Perform the operations
    performOperation(s, t, k);

    // Print the final values
    printf("%s\n", s);
    printf("%s\n", t);

    return 0;
}