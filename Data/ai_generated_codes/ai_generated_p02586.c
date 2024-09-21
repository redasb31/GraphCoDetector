#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
typedef struct {
    int row;
    int col;
    int value;
} Item;

// Function to compare two items based on their column number
int compareItems(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    return itemA->col - itemB->col;
}

// Function to calculate the maximum possible sum of item values
int calculateMaxSum(int R, int C, Item *items, int K) {
    // Sort the items based on their column number
    qsort(items, K, sizeof(Item), compareItems);

    // Initialize variables for maximum sum and current row
    int maxSum = 0;
    int currentRow = 1;
    int itemCount = 0; // Counter for items picked in the current row

    // Iterate through the items
    for (int i = 0; i < K; i++) {
        // If the item is in the current row
        if (items[i].row == currentRow) {
            // If we can pick up the item
            if (itemCount < 3) {
                maxSum += items[i].value;
                itemCount++;
            }
        } else {
            // Move to the next row
            currentRow++;
            itemCount = 0; // Reset item count for the new row
            // Pick up the item in the new row if possible
            if (itemCount < 3) {
                maxSum += items[i].value;
                itemCount++;
            }
        }
    }

    return maxSum;
}

int main() {
    int R, C, K;
    scanf("%d %d %d", &R, &C, &K);

    // Allocate memory for the items
    Item *items = malloc(K * sizeof(Item));

    // Read item information from input
    for (int i = 0; i < K; i++) {
        scanf("%d %d %d", &items[i].row, &items[i].col, &items[i].value);
    }

    // Calculate and print the maximum sum
    int maxSum = calculateMaxSum(R, C, items, K);
    printf("%d\n", maxSum);

    // Free allocated memory
    free(items);

    return 0;
}