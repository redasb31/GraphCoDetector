#include <stdio.h>
#include <stdlib.h>

// Structure to represent a store
typedef struct {
    int a;
    int b;
    int timeTaken; // Time taken to shop at this store
    int visited;   // Flag to track if the store has been visited
} Store;

// Function to compare two stores based on their time taken to shop
int compareStores(const void *a, const void *b) {
    Store *storeA = (Store *)a;
    Store *storeB = (Store *)b;
    return storeA->timeTaken - storeB->timeTaken;
}

int main() {
    int N, T;
    scanf("%d %d", &N, &T);

    // Allocate memory for stores
    Store *stores = (Store *)malloc(N * sizeof(Store));
    if (stores == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read store information
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &stores[i].a, &stores[i].b);
        stores[i].visited = 0;
    }

    // Calculate time taken to shop at each store
    for (int i = 0; i < N; i++) {
        stores[i].timeTaken = stores[i].a * (i + 1) + stores[i].b;
    }

    // Sort stores based on time taken to shop
    qsort(stores, N, sizeof(Store), compareStores);

    // Initialize current time and count of shoppings
    int currentTime = 1;
    int shoppingCount = 0;

    // Iterate through sorted stores
    for (int i = 0; i < N; i++) {
        // If the store can be visited within the time limit
        if (currentTime + stores[i].timeTaken <= T + 0.5 && !stores[i].visited) {
            // Update current time and mark store as visited
            currentTime += stores[i].timeTaken;
            stores[i].visited = 1;
            shoppingCount++;
        }
    }

    // Print the maximum number of shoppings
    printf("%d\n", shoppingCount);

    // Free allocated memory
    free(stores);

    return 0;
}