#include <stdio.h>
#define MOD 1000000007

// Function to calculate the number of digits in a number
int numDigits(long long int n) {
    int count = 0;
    while (n > 0) {
        n /= 10;
        count++;
    }
    return count;
}

int main() {
    long long int S;
    scanf("%lld", &S);

    // dp[i][j] stores the number of pairs (l, r) such that
    // f(l) + f(l + 1) + ... + f(r) = i and r <= j
    long long int dp[S + 1][1000001] = {0}; 

    // Base case: for i = 0, there is only 1 pair (1, 1)
    for (int j = 1; j <= 1000000; j++) {
        dp[0][j] = 1;
    }

    // Iterate over all possible sums (i) and right endpoints (j)
    for (int i = 1; i <= S; i++) {
        for (int j = 1; j <= 1000000; j++) {
            // Add the number of pairs ending at j - 1
            dp[i][j] = dp[i][j - 1];

            // If the sum of digits from j - numDigits(j) to j is equal to i
            // then add the number of pairs ending at j - numDigits(j) - 1
            if (i >= numDigits(j)) {
                dp[i][j] = (dp[i][j] + dp[i - numDigits(j)][j - numDigits(j) - 1]) % MOD;
            }
        }
    }

    // The answer is dp[S][1000000]
    printf("%lld\n", dp[S][1000000]);

    return 0;
}