#include <stdio.h>

int main() {
  int n, i, id, p, q, total_sales;
  // Loop through each dataset
  while (1) {
    // Read the number of data in the list
    scanf("%d", &n);
    // If the input is 0, exit the loop
    if (n == 0) {
      break;
    }
    // Initialize total_sales to 0
    total_sales = 0;
    // Loop through each data in the list
    for (i = 0; i < n; i++) {
      // Read the employee ID, unit price, and amount of sales
      scanf("%d %d %d", &id, &p, &q);
      // Calculate the sales proceeds
      total_sales += p * q;
    }
    // Check if the total sales proceeds is greater than or equal to 1,000,000
    if (total_sales >= 1000000) {
      // Print the employee ID
      printf("%d\n", id);
    } else {
      // Print "NA"
      printf("NA\n");
    }
  }
  return 0;
}