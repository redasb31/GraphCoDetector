#include <stdio.h>
#include <math.h>

// Function to calculate the probability of winning with a given bet
double calculateProbability(int bet, int money, int debt, double p) {
  // Base cases
  if (money >= debt) {
    return 1.0; // Already won
  }
  if (bet > money || bet <= 0) {
    return 0.0; // Invalid bet
  }

  // Calculate the probabilities of winning and losing
  double winProbability = p / 100.0;
  double loseProbability = 1 - winProbability;

  // Recursively calculate the probabilities
  return winProbability * calculateProbability(bet, money + bet, debt, p) +
         loseProbability * calculateProbability(bet, money - bet, debt, p);
}

// Function to find the maximum probability and the optimal bets
void findOptimalBets(int p, int m, int n, double *maxProbability, int *numOptimalBets, int *optimalBets) {
  *maxProbability = 0.0;
  *numOptimalBets = 0;

  // Iterate through possible bets
  for (int bet = 1; bet <= m; ++bet) {
    double probability = calculateProbability(bet, m, n, p);

    // Update the maximum probability and count optimal bets
    if (probability > *maxProbability) {
      *maxProbability = probability;
      *numOptimalBets = 1;
      optimalBets[0] = bet;
    } else if (probability == *maxProbability) {
      *numOptimalBets += 1;
      optimalBets[*numOptimalBets - 1] = bet;
    }
  }
}

int main() {
  int p, m, n;
  scanf("%d %d %d", &p, &m, &n);

  double maxProbability;
  int numOptimalBets;
  int optimalBets[200]; // Array to store the optimal bets

  findOptimalBets(p, m, n, &maxProbability, &numOptimalBets, optimalBets);

  printf("%.6lf\n", maxProbability);
  printf("%d\n", numOptimalBets);

  // Print the optimal bets
  if (numOptimalBets <= 200) {
    for (int i = 0; i < numOptimalBets; ++i) {
      printf("%d ", optimalBets[i]);
    }
  } else {
    // Print the 100 smallest and 100 largest bets
    for (int i = 0; i < 100; ++i) {
      printf("%d ", optimalBets[i]);
    }
    for (int i = numOptimalBets - 100; i < numOptimalBets; ++i) {
      printf("%d ", optimalBets[i]);
    }
  }
  printf("\n");

  return 0;
}