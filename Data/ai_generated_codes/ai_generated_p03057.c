#include <stdio.h>
#include <string.h>

#define MOD 1000000007

// Function to calculate the modular exponentiation (a^b) % MOD
long long mod_pow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

// Function to count the number of valid colorings
int count_valid_colorings(int N, char* S, int M) {
    // Calculate the number of valid colorings when the first arc is red
    long long count_red = 1;
    long long count_blue = 0;
    for (int i = 0; i < M; i++) {
        if (S[i] == 'R') {
            // If the current character is R, count_red increases
            count_red = (count_red + count_blue) % MOD;
        } else {
            // If the current character is B, count_blue increases
            count_blue = (count_blue + count_red) % MOD;
        }
    }

    // Calculate the total number of valid colorings (consider rotations)
    long long total_count = (count_red + count_blue) % MOD;
    total_count = (total_count * mod_pow(2, N - M)) % MOD;

    return total_count;
}

int main() {
    int N, M;
    char S[200005];

    scanf("%d %d\n", &N, &M);
    scanf("%s", S);

    // Calculate and print the result
    printf("%lld\n", count_valid_colorings(N, S, M));

    return 0;
}