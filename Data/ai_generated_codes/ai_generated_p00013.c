#include <stdio.h>

int main() {
  // Array to store the cars currently on the tracks
  int cars[10] = {0}; // Initialize all elements to 0 (empty)
  int car_count = 0; // Tracks the number of cars on the tracks
  int car_number;

  // Loop to read input and process car movements
  while (scanf("%d", &car_number) != EOF) {
    if (car_number == 0) {
      // If the input is 0, it indicates a car exiting
      if (car_count > 0) {
        // Print the car number that exits
        printf("%d\n", cars[0]);
        // Shift the remaining cars to the left to fill the gap
        for (int i = 1; i < car_count; i++) {
          cars[i - 1] = cars[i];
        }
        // Decrement the car count
        car_count--;
      }
    } else {
      // If the input is a car number, it indicates an entry
      // Add the car number to the end of the 'cars' array
      cars[car_count] = car_number;
      // Increment the car count
      car_count++;
    }
  }

  return 0;
}