#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an item
typedef struct Item {
    int value;
    int weight;
    char type;
    long long date;
    char name[21]; // Allocate enough space for the name (20 + null terminator)
} Item;

// Function to compare two items based on the sorting criteria
int compareItems(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;

    // Compare values
    if (itemA->value != itemB->value) {
        return itemA->value - itemB->value;
    }

    // Compare weights if values are equal
    if (itemA->weight != itemB->weight) {
        return itemA->weight - itemB->weight;
    }

    // Compare types if weights are equal
    if (itemA->type != itemB->type) {
        return itemA->type - itemB->type;
    }

    // Compare dates if types are equal
    if (itemA->date != itemB->date) {
        return itemA->date - itemB->date;
    }

    // Compare names if dates are equal
    return strcmp(itemA->name, itemB->name);
}

int main() {
    int n;
    scanf("%d", &n);

    // Allocate memory for items
    Item *items = (Item *)malloc(n * sizeof(Item));

    // Read item attributes
    for (int i = 0; i < n; i++) {
        scanf("%d %d %c %lld %s",
              &items[i].value, &items[i].weight, &items[i].type,
              &items[i].date, items[i].name);
    }

    // Sort items using qsort
    qsort(items, n, sizeof(Item), compareItems);

    // Print sorted items
    for (int i = 0; i < n; i++) {
        printf("%d %d %c %lld %s\n",
               items[i].value, items[i].weight, items[i].type,
               items[i].date, items[i].name);
    }

    // Free allocated memory
    free(items);

    return 0;
}