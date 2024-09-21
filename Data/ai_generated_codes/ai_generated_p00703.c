#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a digit appears twice in a number
int hasDuplicateDigits(char *number) {
    int len = strlen(number);
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (number[i] == number[j]) {
                return 1; // Duplicate digit found
            }
        }
    }
    return 0; // No duplicate digits
}

// Function to calculate hit and blow values
void calculateHitBlow(char *number, char *try, int *hit, int *blow) {
    *hit = 0;
    *blow = 0;
    int len = strlen(number);
    for (int i = 0; i < len; i++) {
        if (number[i] == try[i]) {
            (*hit)++;
        } else {
            for (int j = 0; j < len; j++) {
                if (number[i] == try[j]) {
                    (*blow)++;
                    break; // Avoid counting the same digit multiple times
                }
            }
        }
    }
}

// Function to check if a given number is consistent with all the hints
int isConsistent(char *number, int L, int H, char **hints) {
    for (int i = 0; i < H; i++) {
        int hit, blow;
        char *try = strtok(hints[i], " ");
        char *hitStr = strtok(NULL, " ");
        char *blowStr = strtok(NULL, " ");
        hit = atoi(hitStr);
        blow = atoi(blowStr);
        int calculatedHit, calculatedBlow;
        calculateHitBlow(number, try, &calculatedHit, &calculatedBlow);
        if (calculatedHit != hit || calculatedBlow != blow) {
            return 0; // Inconsistent
        }
    }
    return 1; // Consistent with all hints
}

// Function to generate all possible numbers of length L
void generateNumbers(int L, int index, char *number, int *count, int H, char **hints) {
    if (index == L) {
        if (!hasDuplicateDigits(number)) {
            if (isConsistent(number, L, H, hints)) {
                printf("%s\n", number);
                (*count)++; // Increment count if a consistent number is found
            }
        }
        return;
    }

    for (int i = 0; i <= 9; i++) {
        number[index] = i + '0';
        generateNumbers(L, index + 1, number, count, H, hints);
    }
}

int main() {
    int L, H;
    while (1) {
        scanf("%d %d", &L, &H);
        if (L == 0 && H == 0) {
            break;
        }

        char **hints = (char **)malloc(H * sizeof(char *));
        for (int i = 0; i < H; i++) {
            hints[i] = (char *)malloc(100 * sizeof(char));
            scanf("%s", hints[i]);
        }

        char *number = (char *)malloc((L + 1) * sizeof(char));
        number[L] = '\0'; // Null-terminate the string
        int count = 0;
        generateNumbers(L, 0, number, &count, H, hints);

        if (count == 0) {
            printf("NO\n");
        }

        for (int i = 0; i < H; i++) {
            free(hints[i]);
        }
        free(hints);
        free(number);
    }

    return 0;
}