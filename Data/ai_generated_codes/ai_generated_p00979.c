#include <stdio.h>
#include <math.h>

int main() {
  long long t; // Target scene start time
  scanf("%lld", &t); // Read input

  // Initialize variables for time and speed
  long long time = 0;
  double speed = 1.0; // Normal speed

  // Keep track of whether speed buttons are pressed
  bool pressed_3x = false;
  bool pressed_1_3x = false;

  // Simulate playback until the target scene is reached
  while (time < t) {
    // Check button states every second
    time++;

    // Apply speed changes based on button presses
    if (pressed_3x) {
      speed *= 3;
      pressed_3x = false;
    } else if (pressed_1_3x) {
      if (speed > 1) {
        speed /= 3;
      }
      pressed_1_3x = false;
    }

    // Calculate how much time is needed to reach the target scene at the current speed
    long long time_needed = ceil((t - time) / speed);

    // If the time needed is 1 second, the scene will be reached in the next second
    if (time_needed == 1) {
      break;
    } else {
      // If the time needed is longer than 1 second, we need to wait for the next button press
      time += time_needed - 1;
    }
  }

  // Print the minimum time to reach the target scene in normal speed
  printf("%lld\n", time);

  return 0;
}