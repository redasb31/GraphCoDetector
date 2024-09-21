#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a large integer
typedef struct {
    int *digits; // Array to store digits
    int size;    // Number of digits
} BigInt;

// Function to create a new BigInt from a string
BigInt *createBigInt(char *str) {
    BigInt *bi = malloc(sizeof(BigInt));
    if (bi == NULL) {
        fprintf(stderr, "Memory allocation error!\n");
        exit(1);
    }
    bi->size = strlen(str);
    bi->digits = malloc(bi->size * sizeof(int));
    if (bi->digits == NULL) {
        fprintf(stderr, "Memory allocation error!\n");
        exit(1);
    }
    // Extract digits and store them in the array
    for (int i = 0; i < bi->size; i++) {
        bi->digits[i] = str[i] - '0';
    }
    return bi;
}

// Function to multiply two BigInts
BigInt *multiplyBigInts(BigInt *a, BigInt *b) {
    // Resultant BigInt will have maximum size of sum of sizes of input BigInts
    int resultSize = a->size + b->size;
    BigInt *result = malloc(sizeof(BigInt));
    if (result == NULL) {
        fprintf(stderr, "Memory allocation error!\n");
        exit(1);
    }
    result->digits = malloc(resultSize * sizeof(int));
    if (result->digits == NULL) {
        fprintf(stderr, "Memory allocation error!\n");
        exit(1);
    }
    result->size = resultSize;
    // Initialize result to zero
    memset(result->digits, 0, resultSize * sizeof(int));

    // Multiply each digit of a with each digit of b and store the result in the appropriate position
    for (int i = 0; i < a->size; i++) {
        for (int j = 0; j < b->size; j++) {
            result->digits[i + j] += a->digits[i] * b->digits[j];
        }
    }

    // Handle carry over
    for (int i = 0; i < resultSize - 1; i++) {
        result->digits[i + 1] += result->digits[i] / 10;
        result->digits[i] %= 10;
    }

    // Adjust the size if leading zeros are present
    int leadingZeros = 0;
    for (int i = resultSize - 1; i >= 0; i--) {
        if (result->digits[i] == 0) {
            leadingZeros++;
        } else {
            break;
        }
    }
    result->size -= leadingZeros;
    // Reallocate memory for digits after removing leading zeros
    result->digits = realloc(result->digits, result->size * sizeof(int));
    return result;
}

// Function to print a BigInt
void printBigInt(BigInt *bi) {
    for (int i = bi->size - 1; i >= 0; i--) {
        printf("%d", bi->digits[i]);
    }
}

// Free memory allocated for BigInt
void freeBigInt(BigInt *bi) {
    free(bi->digits);
    free(bi);
}

int main() {
    char a[1001], b[1001];
    scanf("%s %s", a, b);

    // Create BigInt objects from input strings
    BigInt *A = createBigInt(a);
    BigInt *B = createBigInt(b);

    // Multiply the BigInts
    BigInt *result = multiplyBigInts(A, B);

    // Print the product
    printBigInt(result);

    // Free memory
    freeBigInt(A);
    freeBigInt(B);
    freeBigInt(result);

    return 0;
}