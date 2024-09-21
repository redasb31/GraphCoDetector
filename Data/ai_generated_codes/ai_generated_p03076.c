#include <stdio.h>

int main() {
  // Declare variables to store the serving times of each dish
  int A, B, C, D, E;

  // Read the serving times from the standard input
  scanf("%d", &A);
  scanf("%d", &B);
  scanf("%d", &C);
  scanf("%d", &D);
  scanf("%d", &E);

  // Calculate the earliest possible delivery time for each dish
  // by sorting the serving times in ascending order and adding them
  // cumulatively to the previous delivery time, rounded up to the
  // nearest multiple of 10
  int serving_times[5] = {A, B, C, D, E};
  int delivery_time = 0;
  int i;
  for (i = 0; i < 5; i++) {
    int min_time = serving_times[0];
    int min_index = 0;
    int j;
    for (j = 1; j < 5; j++) {
      if (serving_times[j] < min_time) {
        min_time = serving_times[j];
        min_index = j;
      }
    }
    delivery_time += min_time;
    serving_times[min_index] = 124; // Set the served dish's time to a large value
    delivery_time = ((delivery_time + 9) / 10) * 10; // Round up to the nearest multiple of 10
  }

  // Print the earliest possible time for the last dish to be delivered
  printf("%d\n", delivery_time);

  return 0;
}