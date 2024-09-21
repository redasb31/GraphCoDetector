#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the digit at the given position
char get_digit(long long int product, long long int position) {
    // If the position is greater than the number of digits in the product
    if (position > (long long int)log10(product) + 1) {
        return 'x';
    }

    // Calculate the digit at the given position
    long long int digit = (product / (long long int)pow(10, position - 1)) % 10;
    return (char)(digit + '0');
}

int main() {
    // Input variables
    long long int N, M, Q, a[100000], b[100000], d[300000];

    // Input the dimensions of the grid
    scanf("%lld %lld", &N, &M);

    // Input the values in the additional column
    for (long long int i = 0; i < N; i++) {
        scanf("%lld", &a[i]);
    }

    // Input the values in the additional row
    for (long long int j = 0; j < M; j++) {
        scanf("%lld", &b[j]);
    }

    // Input the number of questions
    scanf("%lld", &Q);

    // Input the question positions
    for (long long int k = 0; k < Q; k++) {
        scanf("%lld", &d[k]);
    }

    // Output string to store the answers
    char output[Q + 1];
    output[Q] = '\0';

    // Calculate the digits for each question
    for (long long int k = 0; k < Q; k++) {
        // Calculate the product for the current question
        long long int product = a[(k / M)] * b[(k % M)];

        // Get the digit at the given position
        output[k] = get_digit(product, d[k]);
    }

    // Output the answers
    printf("%s\n", output);

    return 0;
}