#include <stdio.h>
#include <stdlib.h>

// Function to calculate the factorial of a number
long long factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to calculate the lexicographical order of a permutation
long long lexicographicalOrder(int* permutation, int n) {
    long long order = 0;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = i + 1; j < n; j++) {
            if (permutation[j] < permutation[i]) {
                count++;
            }
        }
        order += count * factorial(n - i - 1);
    }
    return order + 1; // Add 1 to start from 1
}

int main() {
    int n;
    scanf("%d", &n);

    int* p = malloc(n * sizeof(int));
    int* q = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }

    long long a = lexicographicalOrder(p, n);
    long long b = lexicographicalOrder(q, n);

    printf("%lld\n", abs(a - b));

    free(p);
    free(q);

    return 0;
}