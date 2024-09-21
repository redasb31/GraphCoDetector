#include <stdio.h>
#include <string.h>

int main() {
  char text[1000001]; // Declare an array to store the text
  int q; // Declare an integer to store the number of queries
  char pattern[1001]; // Declare an array to store the pattern

  // Read the text from the standard input
  scanf("%s", text); 
  // Read the number of queries from the standard input
  scanf("%d", &q); 

  // Loop through each query
  for (int i = 0; i < q; i++) {
    // Read the pattern from the standard input
    scanf("%s", pattern);

    // Use strstr() function to check if the pattern exists in the text
    if (strstr(text, pattern) != NULL) { // If pattern is found, print 1
      printf("1\n"); 
    } else { // If pattern is not found, print 0
      printf("0\n");
    }
  }

  return 0;
}