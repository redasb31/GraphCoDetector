#include <stdio.h>
#include <string.h>

// Function to check if a given string is a valid tournament chart
int is_valid_chart(char *chart) {
  // Base case: If the chart is a single person, it's valid
  if (strlen(chart) == 1) {
    return 1;
  }

  // Check if the chart is in the format "[winner-winner]"
  if (chart[0] == '[' && chart[strlen(chart) - 1] == ']') {
    // Find the middle '-'
    int mid = 0;
    for (int i = 1; i < strlen(chart) - 1; i++) {
      if (chart[i] == '-') {
        mid = i;
        break;
      }
    }

    // Check if the left and right sides of the '-' are valid winners
    return is_valid_chart(chart + 1) && is_valid_chart(chart + mid + 1);
  }

  // If the chart is not a single person or in the correct format, it's invalid
  return 0;
}

// Function to calculate the number of wins for each contestant based on the tournament chart
void calculate_wins(char *chart, int wins[], int *num_contestants) {
  // Base case: If the chart is a single person, they have 1 win
  if (strlen(chart) == 1) {
    wins[(int)chart[0] - (int)'a']++;
    (*num_contestants)++;
    return;
  }

  // Recursively calculate the wins for the left and right sides of the chart
  calculate_wins(chart + 1, wins, num_contestants);
  calculate_wins(chart + strlen(chart) - 2, wins, num_contestants);
}

int main() {
  char chart[100];
  int wins[26] = {0}; // Array to store the number of wins for each contestant
  int num_contestants = 0; // Number of contestants

  // Read the tournament chart
  scanf("%s", chart);

  // Calculate the number of wins for each contestant based on the chart
  calculate_wins(chart, wins, &num_contestants);

  // Read the reported number of wins for each contestant
  for (int i = 0; i < num_contestants; i++) {
    char contestant;
    int reported_wins;
    scanf(" %c %d", &contestant, &reported_wins);
    if (reported_wins != wins[(int)contestant - (int)'a']) {
      printf("No\n");
      return 0;
    }
  }

  // If all reported wins match the calculated wins, print "Yes"
  printf("Yes\n");

  return 0;
}