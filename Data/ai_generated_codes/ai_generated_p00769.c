#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the minimum number of votes required to win a district
int min_votes(char *district, int stage) {
  // Base case: If it's the first stage, return the number of voters
  if (stage == 1) {
    return atoi(district + 1) / 2 + 1; // Divide by 2 and add 1 for majority
  }

  int sub_district_count = 0; // Count sub-districts
  int total_votes = 0; // Total votes in the sub-districts
  int min_votes_needed = 0; // Minimum votes needed for the district

  // Iterate over sub-districts
  for (int i = 1; district[i] != ']'; i++) {
    // If we encounter a new sub-district
    if (district[i] == '[') {
      // Calculate the minimum votes needed for the sub-district
      int sub_district_votes = min_votes(district + i, stage - 1);

      // Add to the total votes and increment the sub-district count
      total_votes += sub_district_votes;
      sub_district_count++;
    }
  }

  // Calculate the minimum votes needed for the district
  min_votes_needed = total_votes / 2 + 1; // Divide by 2 and add 1 for majority

  // Return the minimum votes needed
  return min_votes_needed;
}

int main() {
  int n; // Number of datasets
  scanf("%d", &n);

  // Iterate over datasets
  for (int i = 0; i < n; i++) {
    char district[10001]; // String to store the district representation
    scanf("%s", district);

    // Find the stage of the district
    int stage = 1;
    for (int j = 0; district[j] != '\0'; j++) {
      if (district[j] == '[') {
        stage++;
      }
    }

    // Calculate and print the minimum votes needed for the district
    printf("%d\n", min_votes(district, stage));
  }

  return 0;
}