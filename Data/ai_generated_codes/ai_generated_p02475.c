#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a big integer
typedef struct {
    char *digits; // Array to store digits of the big integer
    int sign;     // 1 for positive, -1 for negative
    int len;      // Length of the digit array
} BigInt;

// Function to initialize a BigInt structure
BigInt *initBigInt(char *str) {
    BigInt *bi = (BigInt *)malloc(sizeof(BigInt));
    bi->sign = 1;
    if (str[0] == '-') {
        bi->sign = -1;
        str++;
    }
    bi->len = strlen(str);
    bi->digits = (char *)malloc((bi->len + 1) * sizeof(char));
    strcpy(bi->digits, str);
    return bi;
}

// Function to free the memory allocated for a BigInt structure
void freeBigInt(BigInt *bi) {
    free(bi->digits);
    free(bi);
}

// Function to perform big integer division
BigInt *divideBigInt(BigInt *A, BigInt *B) {
    // Handle division by zero
    if (B->len == 1 && B->digits[0] == '0') {
        printf("Error: Division by zero\n");
        return NULL;
    }

    // Create a BigInt to store the quotient
    BigInt *quotient = initBigInt("0");

    // If both A and B have the same sign, the quotient is positive
    if (A->sign == B->sign) {
        quotient->sign = 1;
    } else {
        // If A and B have different signs, the quotient is negative
        quotient->sign = -1;
    }

    // Special case: if A is smaller than B, the quotient is 0
    if (compareBigInt(A, B) < 0) {
        return quotient;
    }

    // Perform long division
    char *dividend = A->digits;
    int dividendLen = A->len;
    char *divisor = B->digits;
    int divisorLen = B->len;

    // Initialize the starting index for the dividend
    int index = 0;

    // Loop until the dividend is smaller than the divisor
    while (index <= dividendLen - divisorLen) {
        // Find the largest multiple of the divisor that is less than or equal to the current portion of the dividend
        int multiple = 0;
        char *currentDividend = dividend + index;
        while (compareBigInt(initBigInt(currentDividend), B) >= 0) {
            multiple++;
            currentDividend = addBigInt(currentDividend, divisor, dividendLen - index, divisorLen);
        }

        // Update the quotient
        quotient->digits[quotient->len++] = '0' + multiple;

        // Subtract the multiple of the divisor from the current portion of the dividend
        subtractBigInt(dividend, divisor, dividendLen, divisorLen, index);
        index++;
    }

    // Handle leading zeros in the quotient
    while (quotient->len > 1 && quotient->digits[0] == '0') {
        quotient->len--;
        memmove(quotient->digits, quotient->digits + 1, quotient->len);
    }

    return quotient;
}

// Function to compare two BigInts
int compareBigInt(BigInt *A, BigInt *B) {
    // If the signs are different, the larger sign is bigger
    if (A->sign != B->sign) {
        return (A->sign > B->sign) ? 1 : -1;
    }

    // If the lengths are different, the longer length is bigger
    if (A->len != B->len) {
        return (A->len > B->len) ? (A->sign) : -(A->sign);
    }

    // If the lengths are the same, compare digit by digit
    for (int i = 0; i < A->len; i++) {
        if (A->digits[i] != B->digits[i]) {
            return (A->digits[i] > B->digits[i]) ? (A->sign) : -(A->sign);
        }
    }

    // If all digits are equal, the numbers are equal
    return 0;
}

// Function to add two BigInts
char *addBigInt(char *A, char *B, int A_len, int B_len) {
    int maxLen = (A_len > B_len) ? A_len : B_len;
    char *result = (char *)malloc((maxLen + 2) * sizeof(char));
    result[maxLen + 1] = '\0';

    int carry = 0;
    int i = A_len - 1, j = B_len - 1, k = maxLen;

    // Add digits from right to left
    while (i >= 0 || j >= 0) {
        int sum = carry;
        if (i >= 0) {
            sum += A[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += B[j] - '0';
            j--;
        }
        result[k] = '0' + (sum % 10);
        carry = sum / 10;
        k--;
    }

    // Handle the final carry
    if (carry) {
        result[k] = '0' + carry;
    } else {
        memmove(result, result + 1, maxLen + 1);
    }

    return result;
}

// Function to subtract two BigInts
void subtractBigInt(char *A, char *B, int A_len, int B_len, int index) {
    int borrow = 0;
    int i = A_len - 1, j = B_len - 1;

    // Subtract digits from right to left
    while (j >= 0) {
        int diff = (A[i] - '0') - (B[j] - '0') - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        A[i] = '0' + diff;
        i--;
        j--;
    }

    // Handle remaining digits in A
    while (i >= index) {
        int diff = (A[i] - '0') - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        A[i] = '0' + diff;
        i--;
    }
}

int main() {
    char A[1001], B[1001];
    scanf("%s %s", A, B);

    BigInt *A_bi = initBigInt(A);
    BigInt *B_bi = initBigInt(B);

    BigInt *quotient = divideBigInt(A_bi, B_bi);

    // Print the quotient
    printf("%d\n", quotient->sign * atoi(quotient->digits));

    freeBigInt(A_bi);
    freeBigInt(B_bi);
    freeBigInt(quotient);

    return 0;
}