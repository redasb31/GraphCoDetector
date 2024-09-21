#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a run in RLE
typedef struct {
    char letter;
    int count;
} Run;

// Function to parse an RLE string into an array of Runs
Run* parseRLE(char* rle, int* runCount) {
    // Count the number of runs in the RLE string
    int count = 0;
    for (int i = 0; rle[i] != '$'; i++) {
        if (rle[i] >= 'A' && rle[i] <= 'Z') {
            count++;
        }
    }
    *runCount = count;

    // Allocate memory for the Runs array
    Run* runs = malloc(sizeof(Run) * count);
    if (runs == NULL) {
        fprintf(stderr, "Memory allocation error!\n");
        exit(1);
    }

    // Parse the RLE string and store the Runs in the array
    int i = 0, j = 0;
    while (rle[i] != '$') {
        runs[j].letter = rle[i];
        i++;
        runs[j].count = 0;
        while (rle[i] >= '0' && rle[i] <= '9') {
            runs[j].count = runs[j].count * 10 + (rle[i] - '0');
            i++;
        }
        j++;
        i++;
    }

    return runs;
}

// Function to convert an array of Runs back to an RLE string
char* generateRLE(Run* runs, int runCount) {
    // Calculate the maximum possible length of the RLE string
    int maxLen = 0;
    for (int i = 0; i < runCount; i++) {
        maxLen += 2 + (int)log10(runs[i].count) + 1; // 2 for letter and space, log10 for count digits, 1 for '$'
    }

    // Allocate memory for the RLE string
    char* rle = malloc(sizeof(char) * maxLen);
    if (rle == NULL) {
        fprintf(stderr, "Memory allocation error!\n");
        exit(1);
    }

    // Generate the RLE string
    int i = 0, j = 0;
    while (i < runCount) {
        rle[j++] = runs[i].letter;
        rle[j++] = ' ';
        sprintf(&rle[j], "%d", runs[i].count);
        j += (int)log10(runs[i].count) + 1;
        i++;
    }
    rle[j] = '$';

    return rle;
}

// Function to replace the first occurrence of substring B in A with C
char* replaceRLE(Run* aRuns, int aRunCount, Run* bRuns, int bRunCount, Run* cRuns, int cRunCount) {
    // Find the first occurrence of B in A
    int i = 0, j = 0;
    int bIndex = -1;
    while (i < aRunCount && j < bRunCount) {
        if (aRuns[i].letter == bRuns[j].letter && aRuns[i].count >= bRuns[j].count) {
            if (j == 0) {
                bIndex = i;
            }
            j++;
            aRuns[i].count -= bRuns[j - 1].count;
            if (aRuns[i].count == 0) {
                i++;
            }
        } else {
            i++;
            j = 0;
        }
    }

    // If B is found in A, replace it with C
    if (bIndex != -1) {
        // Insert C runs before the replaced B runs
        Run* newRuns = malloc(sizeof(Run) * (aRunCount + cRunCount - bRunCount));
        if (newRuns == NULL) {
            fprintf(stderr, "Memory allocation error!\n");
            exit(1);
        }

        int k = 0;
        for (int i = 0; i < bIndex; i++) {
            newRuns[k++] = aRuns[i];
        }
        for (int i = 0; i < cRunCount; i++) {
            newRuns[k++] = cRuns[i];
        }
        for (int i = bIndex + bRunCount; i < aRunCount; i++) {
            newRuns[k++] = aRuns[i];
        }

        free(aRuns);
        aRuns = newRuns;
        aRunCount += cRunCount - bRunCount;
    }

    // Generate the RLE string from the updated Runs array
    char* rle = generateRLE(aRuns, aRunCount);
    free(aRuns);

    return rle;
}

int main() {
    char rleA[1000], rleB[1000], rleC[1000];
    fgets(rleA, 1000, stdin);
    fgets(rleB, 1000, stdin);
    fgets(rleC, 1000, stdin);

    // Remove newline characters from input strings
    rleA[strcspn(rleA, "\n")] = 0;
    rleB[strcspn(rleB, "\n")] = 0;
    rleC[strcspn(rleC, "\n")] = 0;

    // Parse the RLE strings into arrays of Runs
    int aRunCount, bRunCount, cRunCount;
    Run* aRuns = parseRLE(rleA, &aRunCount);
    Run* bRuns = parseRLE(rleB, &bRunCount);
    Run* cRuns = parseRLE(rleC, &cRunCount);

    // Replace the first occurrence of B in A with C
    char* result = replaceRLE(aRuns, aRunCount, bRuns, bRunCount, cRuns, cRunCount);

    // Print the result
    printf("%s\n", result);

    free(bRuns);
    free(cRuns);
    free(result);

    return 0;
}