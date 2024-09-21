#include <stdio.h>
#include <stdlib.h>

// Structure to store the integers and their indices
typedef struct {
    int val;
    int index;
} Integer;

// Comparison function for qsort
int compare(const void *a, const void *b) {
    Integer *ia = (Integer *)a;
    Integer *ib = (Integer *)b;
    return ia->val - ib->val;
}

int main() {
    int N;
    scanf("%d", &N);

    // Allocate memory for the integers
    Integer *integers = malloc(sizeof(Integer) * N);

    // Read the integers from the input
    for (int i = 0; i < N; i++) {
        scanf("%d", &integers[i].val);
        integers[i].index = i + 1;
    }

    // Sort the integers in ascending order
    qsort(integers, N, sizeof(Integer), compare);

    // Calculate the maximum possible value and the operations
    int max_value = integers[N - 1].val - integers[0].val;
    printf("%d\n", max_value);

    // Print the operations
    for (int i = 0; i < N - 1; i++) {
        // Choose the two integers with the smallest and largest values
        int x = integers[i].index;
        int y = integers[N - 1 - i].index;
        printf("%d %d\n", x, y);
    }

    // Free the allocated memory
    free(integers);

    return 0;
}