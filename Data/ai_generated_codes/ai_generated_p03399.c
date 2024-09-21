#include <stdio.h>

int main() {
  // Declare variables to store the train and bus fares.
  int A, B, C, D;

  // Read the train fares from the standard input.
  scanf("%d", &A);
  scanf("%d", &B);

  // Read the bus fares from the standard input.
  scanf("%d", &C);
  scanf("%d", &D);

  // Calculate the minimum total fare.
  // If the unlimited train fare is less than the ordinary train fare,
  // use the unlimited train ticket. Otherwise, use ordinary tickets.
  int train_fare = (B < A) ? B : A;

  // If the unlimited bus fare is less than the ordinary bus fare,
  // use the unlimited bus ticket. Otherwise, use ordinary tickets.
  int bus_fare = (D < C) ? D : C;

  // Calculate the total fare.
  int total_fare = train_fare + bus_fare;

  // Print the minimum total fare.
  printf("%d\n", total_fare);

  return 0;
}