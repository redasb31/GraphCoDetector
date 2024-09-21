#include <stdio.h>
#include <string.h>
#include <math.h>

// Function to convert an integer to its ternary representation
char *toTernary(int n, char *ternary) {
    int i = 0;
    while (n > 0) {
        ternary[i++] = (n % 3) + '0';
        n /= 3;
    }
    ternary[i] = '\0';
    return ternary;
}

// Function to swap the digits '1' and '2' in a ternary string
char *swapDigits(char *ternary) {
    for (int i = 0; ternary[i] != '\0'; i++) {
        if (ternary[i] == '1') {
            ternary[i] = '2';
        } else if (ternary[i] == '2') {
            ternary[i] = '1';
        }
    }
    return ternary;
}

// Function to perform the salsa move
int salsaMove(int i, int n) {
    char ternary[15];
    toTernary(i, ternary);
    swapDigits(ternary);
    return (int)strtol(ternary, NULL, 3);
}

// Function to perform the rumba move
int rumbaMove(int i, int n) {
    return (i + 1) % (int)pow(3, n);
}

int main() {
    int n;
    char T[200001];

    scanf("%d\n", &n);
    scanf("%s", T);

    int p[1000000];
    for (int i = 0; i < (int)pow(3, n); i++) {
        p[i] = i;
    }

    for (int i = 0; i < strlen(T); i++) {
        if (T[i] == 'S') {
            for (int j = 0; j < (int)pow(3, n); j++) {
                p[j] = salsaMove(p[j], n);
            }
        } else {
            for (int j = 0; j < (int)pow(3, n); j++) {
                p[j] = rumbaMove(p[j], n);
            }
        }
    }

    for (int i = 0; i < (int)pow(3, n); i++) {
        printf("%d ", p[i]);
    }

    printf("\n");
    return 0;
}