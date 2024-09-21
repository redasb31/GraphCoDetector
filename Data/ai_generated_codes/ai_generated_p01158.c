#include <stdio.h>
#include <string.h>

#define MAX_TOOLS 1000
#define MAX_NAME_LEN 32

// Structure to represent a tool order
typedef struct {
  char name[MAX_NAME_LEN];
  int days_without_support;
  char support_tool[MAX_NAME_LEN];
  int days_with_support;
} ToolOrder;

// Function to find the minimum number of days to fill all orders
int findMinDays(ToolOrder orders[], int n) {
  // Create a table to store the minimum days required to fill the orders up to a certain index
  int min_days[MAX_TOOLS];

  // Initialize the table
  min_days[0] = orders[0].days_without_support;

  // Iterate over the remaining orders
  for (int i = 1; i < n; i++) {
    // Find the minimum days required to fill the order without using any support tool
    int days_without_support = min_days[i - 1] + orders[i].days_without_support;

    // Find the minimum days required to fill the order using the support tool
    int days_with_support = 0;
    for (int j = 0; j < i; j++) {
      if (strcmp(orders[j].name, orders[i].support_tool) == 0) {
        // If the support tool has already been filled, use the minimum days required to fill the support tool
        // plus the days required to fill the current order using the support tool
        days_with_support = min_days[j] + orders[i].days_with_support;
        break;
      }
    }

    // Choose the minimum of the two options
    min_days[i] = (days_without_support < days_with_support) ? days_without_support : days_with_support;
  }

  // Return the minimum days required to fill all orders
  return min_days[n - 1];
}

int main() {
  int n;

  // Read the number of tools in each test case
  while (scanf("%d", &n) == 1 && n != 0) {
    // Create an array of tool orders
    ToolOrder orders[MAX_TOOLS];

    // Read the tool order information
    for (int i = 0; i < n; i++) {
      scanf("%s %d %s %d", orders[i].name, &orders[i].days_without_support, orders[i].support_tool, &orders[i].days_with_support);
    }

    // Find the minimum number of days required to fill all orders
    int min_days = findMinDays(orders, n);

    // Print the result
    printf("%d\n", min_days);
  }

  return 0;
}