#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

typedef struct {
  int topping;
  int deliciousness;
} Sushi;

Sushi sushi[MAX_N];

int compare(const void *a, const void *b) {
  return ((Sushi *)a)->deliciousness - ((Sushi *)b)->deliciousness;
}

int main() {
  int N, K;
  scanf("%d %d", &N, &K);

  for (int i = 0; i < N; i++) {
    scanf("%d %d", &sushi[i].topping, &sushi[i].deliciousness);
  }

  // Sort the sushi by deliciousness in descending order
  qsort(sushi, N, sizeof(Sushi), compare);

  // Initialize variables
  long long total_deliciousness = 0;
  int num_toppings = 0;
  int toppings[MAX_N]; // Array to keep track of the unique toppings
  toppings[0] = -1; // Initialize to an invalid topping

  // Iterate through the sorted sushi array
  for (int i = 0; i < K; i++) {
    // If the topping is not already included
    if (toppings[sushi[i].topping] == 0) {
      // Add the topping to the list
      toppings[sushi[i].topping] = 1;
      num_toppings++;
    }
    // Add the deliciousness to the total
    total_deliciousness += sushi[i].deliciousness;
  }

  // Calculate the satisfaction
  long long satisfaction = total_deliciousness + (long long)num_toppings * num_toppings;

  // Print the maximum satisfaction
  printf("%lld\n", satisfaction);

  return 0;
}