#include <stdio.h>

int main() {
  // Declare variables
  int N;
  double total_yen = 0.0;
  double bitcoin_to_yen_rate = 380000.0;

  // Read the number of relatives
  scanf("%d", &N);

  // Read the otoshidama amounts and currencies
  for (int i = 0; i < N; i++) {
    double amount;
    char currency[4];
    scanf("%lf %s", &amount, currency);

    // Convert bitcoins to yen if necessary
    if (currency[0] == 'B') {
      amount *= bitcoin_to_yen_rate;
    }

    // Add the amount to the total
    total_yen += amount;
  }

  // Print the total value in yen
  printf("%.5lf\n", total_yen);

  return 0;
}