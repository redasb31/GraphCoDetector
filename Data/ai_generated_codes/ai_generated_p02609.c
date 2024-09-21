#include <stdio.h>
#include <math.h>

// Function to count the number of set bits in a number
int popcount(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

// Function to calculate f(n)
int calculate_f(int n) {
    int count = 0;
    while (n) {
        count++;
        n = n % popcount(n);
    }
    return count;
}

int main() {
    int N, X, i;

    scanf("%d", &N);
    scanf("%d", &X);

    for (i = 1; i <= N; i++) {
        // Invert the i-th bit from the top
        int X_i = X ^ (1 << (N - i));
        // Calculate and print f(X_i)
        printf("%d\n", calculate_f(X_i));
    }

    return 0;
}