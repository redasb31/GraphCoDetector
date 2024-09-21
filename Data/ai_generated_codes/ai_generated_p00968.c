#include <stdio.h>
#include <string.h>

// Function to compare two items (letters or numbers)
int compare_items(char *item1, char *item2) {
    // Number items come before letter items
    if (isdigit(*item1) && isalpha(*item2)) {
        return -1;
    } else if (isalpha(*item1) && isdigit(*item2)) {
        return 1;
    } else if (isdigit(*item1) && isdigit(*item2)) {
        // Compare numeric values
        return atoi(item1) - atoi(item2);
    } else {
        // Compare ASCII codes for letters
        return *item1 - *item2;
    }
}

// Function to compare two file names
int compare_filenames(char *filename1, char *filename2) {
    int i = 0, j = 0;
    char item1[10], item2[10];

    while (filename1[i] != '\0' || filename2[j] != '\0') {
        // Extract items from both filenames
        int k = 0;
        while (isalnum(filename1[i]) && filename1[i] != '\0') {
            item1[k++] = filename1[i++];
        }
        item1[k] = '\0';

        k = 0;
        while (isalnum(filename2[j]) && filename2[j] != '\0') {
            item2[k++] = filename2[j++];
        }
        item2[k] = '\0';

        // Compare items
        int comparison = compare_items(item1, item2);
        if (comparison != 0) {
            return comparison;
        }
    }

    // If all items are the same, the shorter filename comes first
    return strlen(filename1) - strlen(filename2);
}

int main() {
    int n;
    char filename0[10], filename[10];

    // Read the number of file names
    scanf("%d", &n);

    // Read the reference file name
    scanf("%s", filename0);

    // Compare and output results for each file name
    for (int i = 0; i < n; i++) {
        scanf("%s", filename);
        if (compare_filenames(filename, filename0) < 0) {
            printf("-\n");
        } else {
            printf("+\n");
        }
    }

    return 0;
}