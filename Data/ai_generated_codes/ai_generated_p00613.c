#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate the sum of sales quantities for a pair of cakes
int calculate_pair_sum(int *sales, int i, int j) {
  return sales[i] + sales[j];
}

// Function to generate a random permutation of an array
void shuffle(int *arr, int n) {
  srand(time(NULL));
  for (int i = n - 1; i > 0; i--) {
    int j = rand() % (i + 1);
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}

int main() {
  int K;
  while (1) {
    scanf("%d", &K);
    if (K == 0) {
      break;
    }

    // Allocate memory for sales quantities of each cake
    int *sales = (int *)malloc(K * sizeof(int));

    // Read sales quantities of each cake
    for (int i = 0; i < K; i++) {
      scanf("%d", &sales[i]);
    }

    // Calculate the number of pairs of cakes
    int num_pairs = K * (K - 1) / 2;

    // Allocate memory for the shuffled pair sums
    int *pair_sums = (int *)malloc(num_pairs * sizeof(int));

    // Calculate the sum of sales quantities for each pair of cakes
    int index = 0;
    for (int i = 0; i < K; i++) {
      for (int j = i + 1; j < K; j++) {
        pair_sums[index++] = calculate_pair_sum(sales, i, j);
      }
    }

    // Shuffle the pair sums
    shuffle(pair_sums, num_pairs);

    // Replace the original sales record with the shuffled pair sums
    index = 0;
    for (int i = 0; i < K; i++) {
      for (int j = i + 1; j < K; j++) {
        sales[index++] = pair_sums[index];
      }
    }

    // Calculate the total sales quantity
    int total_sales = 0;
    for (int i = 0; i < K; i++) {
      total_sales += sales[i];
    }

    // Output the total sales quantity
    printf("%d\n", total_sales);

    // Free allocated memory
    free(sales);
    free(pair_sums);
  }
  return 0;
}