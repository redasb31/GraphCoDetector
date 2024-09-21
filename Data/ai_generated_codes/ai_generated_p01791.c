#include <stdio.h>
#include <stdlib.h>

// Function to find the sum of the k largest numbers in an array
int find_sum_of_k_largest(int *arr, int n, int k) {
    // Sort the array in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Calculate the sum of the k largest numbers
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int n, k, a, b;
    scanf("%d %d %d %d", &n, &k, &a, &b);

    int *cards = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &cards[i]);
    }

    // Find the best value of t
    int t = b;
    int best_diff = b - find_sum_of_k_largest(cards, n, k);

    for (int i = b - 1; i >= a; i--) {
        int diff = abs(i - find_sum_of_k_largest(cards, n, k));
        if (diff < best_diff) {
            t = i;
            best_diff = diff;
        }
    }

    // Find the indices of the k cards Bob will choose
    int *chosen_cards = (int *)malloc(sizeof(int) * k);
    for (int i = 0; i < n; i++) {
        chosen_cards[i] = i + 1; // Initialize with all indices
    }

    // Sort the indices based on the card values in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cards[chosen_cards[i] - 1] < cards[chosen_cards[j] - 1]) {
                int temp = chosen_cards[i];
                chosen_cards[i] = chosen_cards[j];
                chosen_cards[j] = temp;
            }
        }
    }

    // Print the results
    printf("%d\n", t);
    for (int i = 0; i < k; i++) {
        printf("%d ", chosen_cards[i]);
    }
    printf("\n");

    free(cards);
    free(chosen_cards);

    return 0;
}