#include <stdio.h>
#include <string.h>

int main() {
  char S[10]; // Array to store the input string (weather today)

  // Read the weather for today from standard input
  scanf("%s", S);

  // Predict the weather tomorrow based on the cycle
  if (strcmp(S, "Sunny") == 0) {
    printf("Cloudy\n"); // Sunny day followed by cloudy day
  } else if (strcmp(S, "Cloudy") == 0) {
    printf("Rainy\n"); // Cloudy day followed by rainy day
  } else if (strcmp(S, "Rainy") == 0) {
    printf("Sunny\n"); // Rainy day followed by sunny day
  }

  return 0;
}