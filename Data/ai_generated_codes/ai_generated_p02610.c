#include <stdio.h>
#include <stdlib.h>

// Structure to store camel information
typedef struct {
    int k; // Number of frontmost camels for happiness
    int l; // Happiness if among the k frontmost
    int r; // Happiness otherwise
} Camel;

// Function to compare two camels based on their happiness values
int compare(const void *a, const void *b) {
    Camel *ca = (Camel *)a;
    Camel *cb = (Camel *)b;
    // Prioritize higher 'l' (happiness when among the frontmost)
    if (ca->l > cb->l) {
        return -1;
    } else if (ca->l < cb->l) {
        return 1;
    } else {
        // If 'l' is equal, prioritize lower 'r' (happiness when not among the frontmost)
        return ca->r - cb->r;
    }
}

int main() {
    int t; // Number of test cases
    scanf("%d", &t);

    while (t--) {
        int n; // Number of camels
        scanf("%d", &n);

        Camel camels[n]; // Array to store camel information
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &camels[i].k, &camels[i].l, &camels[i].r);
        }

        // Sort the camels based on happiness values
        qsort(camels, n, sizeof(Camel), compare);

        // Calculate the total happiness
        long long total_happiness = 0;
        for (int i = 0; i < n; i++) {
            if (i < camels[i].k) {
                total_happiness += camels[i].l; // Happiness if among the frontmost
            } else {
                total_happiness += camels[i].r; // Happiness otherwise
            }
        }

        printf("%lld\n", total_happiness); // Print the maximum possible happiness
    }

    return 0;
}