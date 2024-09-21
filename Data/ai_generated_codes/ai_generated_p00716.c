#include <stdio.h>
#include <math.h>

// Function to calculate the final amount for simple interest
double simpleInterest(double initialFund, double interestRate, int years, int operationCharge) {
  double finalAmount = initialFund;
  double totalInterest = 0.0;

  for (int year = 1; year <= years; year++) {
    // Calculate interest for the year
    double interest = finalAmount * interestRate;
    totalInterest += interest;
    finalAmount = finalAmount - operationCharge;
  }

  finalAmount += totalInterest;
  return finalAmount;
}

// Function to calculate the final amount for compound interest
double compoundInterest(double initialFund, double interestRate, int years, int operationCharge) {
  double finalAmount = initialFund;

  for (int year = 1; year <= years; year++) {
    // Calculate interest for the year
    double interest = finalAmount * interestRate;
    finalAmount += interest;
    finalAmount -= operationCharge;
  }

  return finalAmount;
}

int main() {
  int m, n, initialFund, years;
  char interestType;
  double interestRate, maxFinalAmount;

  // Read the number of datasets
  scanf("%d", &m);

  // Iterate over each dataset
  for (int i = 0; i < m; i++) {
    // Read input for each dataset
    scanf("%d %d %d", &initialFund, &years, &n);

    maxFinalAmount = initialFund; // Assume initial amount as the maximum
    
    // Iterate over each operation
    for (int j = 0; j < n; j++) {
      scanf(" %c %lf %d", &interestType, &interestRate, &operationCharge);

      // Calculate the final amount based on interest type
      if (interestType == '0') {
        double finalAmount = simpleInterest(initialFund, interestRate, years, operationCharge);
        if (finalAmount > maxFinalAmount) {
          maxFinalAmount = finalAmount;
        }
      } else if (interestType == '1') {
        double finalAmount = compoundInterest(initialFund, interestRate, years, operationCharge);
        if (finalAmount > maxFinalAmount) {
          maxFinalAmount = finalAmount;
        }
      }
    }

    // Print the maximum final amount
    printf("%.0lf\n", maxFinalAmount);
  }

  return 0;
}