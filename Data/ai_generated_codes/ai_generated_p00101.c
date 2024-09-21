#include <stdio.h>
#include <string.h>

int main() {
  // Get the number of datasets
  int n;
  scanf("%d", &n);

  // Loop through each dataset
  for (int i = 0; i < n; i++) {
    // Read the input string
    char str[1001];
    scanf("%s", str);

    // Replace all occurrences of "Hoshino" with "Hoshina"
    char *ptr = strstr(str, "Hoshino");
    while (ptr != NULL) {
      // Copy "Hoshina" over "Hoshino"
      strcpy(ptr, "Hoshina");

      // Find the next occurrence of "Hoshino"
      ptr = strstr(ptr + 7, "Hoshino");
    }

    // Print the converted string
    printf("%s\n", str);
  }

  return 0;
}