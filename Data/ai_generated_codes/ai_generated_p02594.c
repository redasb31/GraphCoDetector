#include <stdio.h>

int main() {
  // Declare a variable to store the temperature.
  int temperature;

  // Read the temperature from the user.
  scanf("%d", &temperature);

  // Check if the temperature is 30 degrees Celsius or above.
  if (temperature >= 30) {
    // Print "Yes" if the temperature is 30 degrees Celsius or above.
    printf("Yes\n");
  } else {
    // Print "No" if the temperature is below 30 degrees Celsius.
    printf("No\n");
  }

  return 0;
}