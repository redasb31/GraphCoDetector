#include <stdio.h>
#include <string.h>

int main() {
  char cross_section[20001]; // Maximum length of the cross-section string
  int length, i, flood_count = 0, total_area = 0, current_area = 0;

  // Read the cross-section diagram from the user
  scanf("%[^\n]", cross_section);
  length = strlen(cross_section);

  // Iterate through the cross-section string
  for (i = 0; i < length; i++) {
    // If we encounter a '/' or '_'
    if (cross_section[i] == '/' || cross_section[i] == '_') {
      // If it's a '/', it starts a flood
      if (cross_section[i] == '/') {
        current_area = 1; // Start a new flood with area 1
        flood_count++; // Increase the flood count
      } else {
        // If it's a '_', it ends a flood
        total_area += current_area; // Add the current flood area to the total area
        current_area = 0; // Reset the current area
      }
    } else {
      // If it's not '/' or '_', it's part of a flood
      current_area++; // Increase the area of the current flood
    }
  }

  // Add the last flood area if any
  total_area += current_area;

  // Print the output
  printf("%d\n", total_area); // Total flood area
  printf("%d", flood_count); // Number of floods
  // Print the area of each flood
  for (i = 0; i < flood_count; i++) {
    printf(" %d", total_area - current_area); // Print the area of the flood
    current_area = 0; // Reset the current area for the next flood
  }
  printf("\n");

  return 0;
}