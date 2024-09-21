#include <stdio.h>

// Function to calculate the modular inverse of a number
int modInverse(int a, int m) {
    for (int x = 1; x < m; x++)
        if (((a % m) * (x % m)) % m == 1)
            return x;
    return 1;
}

int main() {
    int T; // Number of test cases
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        int N, K; // Size of the sequence and multiplier
        scanf("%d %d", &N, &K);

        // Store the first element of each sequence
        int B[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &B[i]);
        }

        // Calculate the original sequence elements
        int a[N];
        a[N - 1] = B[N - 1]; 
        for (int i = N - 2; i >= 0; i--) {
            // Calculate a[i] using the formula provided
            a[i] = ((B[i] - B[i + 1]) * modInverse(K, 65537)) % 65537;
            // Ensure the value is within the range 0 to 65536
            if (a[i] < 0) {
                a[i] += 65537;
            }
        }

        // Output the original sequence elements
        for (int i = 0; i < N; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }

    return 0;
}