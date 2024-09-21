#include <stdio.h>
#include <math.h>

// Function to calculate the sum of digits in a sequence
int sum_digits(char *s, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += s[i] - '0';
    }
    return sum;
}

// Function to calculate the product of (digit + 1) in a sequence
long long prod_digits(char *s, int n) {
    long long prod = 1;
    for (int i = 0; i < n; i++) {
        prod *= (s[i] - '0' + 1);
    }
    return prod;
}

// Function to calculate the integer value of a digit sequence
long long int_value(char *s, int n) {
    long long value = 0;
    for (int i = 0; i < n; i++) {
        value += (s[i] - '0') * pow(10, n - i - 1);
    }
    return value;
}

// Function to count the number of sequences less than a given sequence
long long count_less_sequences(char *s, int n) {
    long long count = 0;
    // Iterate through all possible sequences
    for (int i = 0; i < pow(10, n); i++) {
        // Convert integer i to a digit sequence
        char temp[n + 1];
        sprintf(temp, "%0*d", n, i);

        // Compare the current sequence with the given sequence
        if (sum_digits(temp, n) < sum_digits(s, n)) {
            count++;
        } else if (sum_digits(temp, n) == sum_digits(s, n) && 
                   prod_digits(temp, n) < prod_digits(s, n)) {
            count++;
        } else if (sum_digits(temp, n) == sum_digits(s, n) && 
                   prod_digits(temp, n) == prod_digits(s, n) && 
                   int_value(temp, n) < int_value(s, n)) {
            count++;
        }
    }
    return count;
}

int main() {
    char s[15];
    scanf("%s", s);

    int n = strlen(s);

    // Calculate and print the count of less sequences
    printf("%lld\n", count_less_sequences(s, n));

    return 0;
}