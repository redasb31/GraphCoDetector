#include <stdio.h>
#include <string.h>

#define MOD 1000000007

// Function to calculate the median of three bits
int median(int a, int b, int c) {
    if (a <= b && b <= c || c <= b && b <= a) {
        return b;
    } else if (a <= c && c <= b || b <= c && c <= a) {
        return c;
    } else {
        return a;
    }
}

// Recursive function to count the number of beautiful strings
long long countBeautiful(char *S, int start, int end) {
    if (start >= end) {
        return 1;
    }

    long long count = 0;
    if (S[start] == '?') {
        // Try both 0 and 1 for the first bit
        for (int i = 0; i <= 1; i++) {
            S[start] = i + '0';
            count = (count + countBeautiful(S, start + 1, end)) % MOD;
            S[start] = '?';
        }
    } else if (S[end] == '?') {
        // Try both 0 and 1 for the last bit
        for (int i = 0; i <= 1; i++) {
            S[end] = i + '0';
            count = (count + countBeautiful(S, start, end - 1)) % MOD;
            S[end] = '?';
        }
    } else {
        // Calculate the median of the three bits and recursively count
        int mid = (start + end) / 2;
        int middle = median(S[start] - '0', S[mid] - '0', S[end] - '0');
        count = countBeautiful(S, start + 1, end - 1);
        if (middle == 1) {
            count = (count + countBeautiful(S, start, end - 2)) % MOD;
        }
    }
    return count;
}

int main() {
    char S[300001];
    scanf("%s", S);

    int n = strlen(S);
    long long answer = countBeautiful(S, 0, n - 1);

    printf("%lld\n", answer);

    return 0;
}