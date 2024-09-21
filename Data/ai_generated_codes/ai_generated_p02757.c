#include <stdio.h>
#include <string.h>

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int N, P;
    char S[200001];

    // Input the length of the string, the prime number, and the string itself
    scanf("%d %d\n", &N, &P);
    scanf("%s", S);

    // Check if P is a prime number (given in the problem statement)
    if (!isPrime(P)) {
        printf("Error: P is not a prime number.\n");
        return 1;
    }

    // Initialize a variable to count the number of divisible substrings
    int count = 0;

    // Iterate through all possible substrings
    for (int i = 0; i < N; i++) {
        // Initialize a variable to store the current substring value
        long long substringValue = 0;
        // Iterate through the characters of the current substring
        for (int j = i; j < N; j++) {
            // Calculate the current substring value (base-10 representation)
            substringValue = (substringValue * 10) + (S[j] - '0');
            // Check if the current substring is divisible by P
            if (substringValue % P == 0) {
                count++; // Increment the count if it is divisible
            }
        }
    }

    // Print the count of divisible substrings
    printf("%d\n", count);

    return 0;
}