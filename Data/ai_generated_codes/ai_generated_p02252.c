#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
typedef struct Item {
    int value;
    int weight;
    double valuePerUnitWeight;
} Item;

// Function to compare two items based on their value per unit weight
int compareItems(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;

    // Descending order based on value per unit weight
    if (itemA->valuePerUnitWeight > itemB->valuePerUnitWeight) {
        return -1;
    } else if (itemA->valuePerUnitWeight < itemB->valuePerUnitWeight) {
        return 1;
    } else {
        return 0;
    }
}

// Function to solve the fractional knapsack problem
double fractionalKnapsack(Item items[], int n, int capacity) {
    // Calculate value per unit weight for each item
    for (int i = 0; i < n; i++) {
        items[i].valuePerUnitWeight = (double)items[i].value / items[i].weight;
    }

    // Sort items in descending order based on value per unit weight
    qsort(items, n, sizeof(Item), compareItems);

    // Initialize total value and remaining capacity
    double totalValue = 0.0;
    int remainingCapacity = capacity;

    // Iterate through sorted items
    for (int i = 0; i < n; i++) {
        // If the current item fits entirely
        if (items[i].weight <= remainingCapacity) {
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
        } else {
            // If the item doesn't fit entirely, take a fraction
            totalValue += items[i].valuePerUnitWeight * remainingCapacity;
            remainingCapacity = 0;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;
    scanf("%d %d", &n, &capacity);

    // Allocate memory for items
    Item *items = (Item *)malloc(n * sizeof(Item));

    // Read item values and weights
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    // Calculate and print the maximum total value
    double maxValue = fractionalKnapsack(items, n, capacity);
    printf("%.9lf\n", maxValue);

    // Free allocated memory
    free(items);

    return 0;
}