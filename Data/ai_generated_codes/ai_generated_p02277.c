#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char suit;
    int number;
} Card;

// Function to swap two cards
void swap(Card *a, Card *b) {
    Card temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for Quick Sort
int partition(Card A[], int p, int r) {
    Card x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j].number <= x.number) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[r]);
    return i + 1;
}

// Quick Sort function
void quickSort(Card A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

// Function to check the stability of the sorting algorithm
int checkStability(Card A[], int n, Card B[], int n1) {
    if (n != n1) {
        return 0; // Not stable if sizes are different
    }
    for (int i = 0; i < n; i++) {
        if (A[i].number != B[i].number) {
            return 0; // Not stable if numbers are different
        }
        if (A[i].number == B[i].number && A[i].suit != B[i].suit) {
            return 0; // Not stable if numbers are same but suits are different
        }
    }
    return 1; // Stable if all conditions are satisfied
}

int main() {
    int n;
    scanf("%d", &n);

    // Input the cards
    Card cards[n];
    Card originalCards[n]; // Store the original order for stability check
    for (int i = 0; i < n; i++) {
        scanf(" %c %d", &cards[i].suit, &cards[i].number);
        originalCards[i] = cards[i]; // Copy the original card order
    }

    // Sort the cards using Quick Sort
    quickSort(cards, 0, n - 1);

    // Check the stability of the sorting algorithm
    int stable = checkStability(cards, n, originalCards, n);

    // Print the stability status
    printf("%s\n", stable ? "Stable" : "Not stable");

    // Print the sorted cards
    for (int i = 0; i < n; i++) {
        printf("%c %d\n", cards[i].suit, cards[i].number);
    }

    return 0;
}