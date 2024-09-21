#include <stdio.h>
#include <stdlib.h>

// Function to check if a solution exists and print it if it does
void solve(int p, int s, int **sales, int *totals_product, int *totals_store) {
    int i, j, k;
    int **solution = (int **)malloc(p * sizeof(int *));
    for (i = 0; i < p; i++) {
        solution[i] = (int *)malloc(s * sizeof(int));
        for (j = 0; j < s; j++) {
            if (sales[i][j] == -1) {
                solution[i][j] = totals_product[i] - totals_store[j] + sales[i][0] + sales[i][1] + sales[i][2] + sales[i][3];
            } else {
                solution[i][j] = sales[i][j];
            }
        }
    }
    int count = 0;
    // Checking if the solution is unique
    for (i = 0; i < p; i++) {
        for (j = 0; j < s; j++) {
            if (sales[i][j] == -1) {
                count++;
            }
        }
    }
    if (count == 0) {
        // Print the solution
        for (i = 0; i < p; i++) {
            for (j = 0; j < s; j++) {
                if (sales[i][j] == -1) {
                    printf("%d\n", solution[i][j]);
                }
            }
        }
    } else {
        // If no unique solution is found
        printf("NO\n");
    }
    // Free allocated memory
    for (i = 0; i < p; i++) {
        free(solution[i]);
    }
    free(solution);
}

int main() {
    int p, s;
    while (scanf("%d %d", &p, &s) == 2 && p != 0) {
        int **sales = (int **)malloc(p * sizeof(int *));
        int *totals_product = (int *)malloc(p * sizeof(int));
        int *totals_store = (int *)malloc(s * sizeof(int));
        for (int i = 0; i < p; i++) {
            sales[i] = (int *)malloc((s + 1) * sizeof(int));
            for (int j = 0; j <= s; j++) {
                char c;
                scanf(" %c", &c);
                if (c == '?') {
                    sales[i][j] = -1;
                } else {
                    sales[i][j] = atoi(&c);
                }
            }
            totals_product[i] = sales[i][s];
        }
        for (int i = 0; i < s; i++) {
            char c;
            scanf(" %c", &c);
            totals_store[i] = atoi(&c);
        }
        // Calling the function to solve the problem
        solve(p, s, sales, totals_product, totals_store);
        // Freeing allocated memory
        for (int i = 0; i < p; i++) {
            free(sales[i]);
        }
        free(sales);
        free(totals_product);
        free(totals_store);
        printf("\n");
    }
    return 0;
}