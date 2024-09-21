#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 14
#define EPS 1e-6

typedef struct {
  int rating;
  int rock, paper, scissors;
} Player;

double dp[1 << MAX_N][MAX_N]; // dp[mask][i]: probability of winning when mask represents the remaining players and the player with rating i is the highest rated player among the remaining players.
Player players[MAX_N];

// Calculate the probability of winning a round given the current players and their choices
double calculate_round_probability(int mask, int i, int choice) {
  double probability = 1.0;
  for (int j = 1; j <= MAX_N; ++j) {
    if (mask & (1 << (j - 1))) { // Check if player j is still in the game
      if (j == i) {
        continue;
      }
      if (choice == 0) { // Rock
        probability *= (double)players[j].scissors / 100.0; // Probability of player j showing scissors
      } else if (choice == 1) { // Paper
        probability *= (double)players[j].rock / 100.0; // Probability of player j showing rock
      } else { // Scissors
        probability *= (double)players[j].paper / 100.0; // Probability of player j showing paper
      }
    }
  }
  return probability;
}

// Calculate the probability of winning the game from the current state
double calculate_probability(int mask, int i) {
  if (dp[mask][i] != -1) {
    return dp[mask][i];
  }

  // Base case: only one player left
  if (__builtin_popcount(mask) == 1) {
    return 1.0;
  }

  // Calculate the probability of winning the round by playing each choice
  double rock_probability = calculate_round_probability(mask, i, 0);
  double paper_probability = calculate_round_probability(mask, i, 1);
  double scissors_probability = calculate_round_probability(mask, i, 2);

  // Find the optimal choice
  double max_probability = fmax(rock_probability, fmax(paper_probability, scissors_probability));

  // Recursively calculate the probability of winning from the next round
  if (fabs(rock_probability - max_probability) < EPS) {
    dp[mask][i] = rock_probability * calculate_probability(mask ^ (1 << (i - 1)), i); // Exclude player i from the mask if they win
  } else if (fabs(paper_probability - max_probability) < EPS) {
    dp[mask][i] = paper_probability * calculate_probability(mask ^ (1 << (i - 1)), i);
  } else {
    dp[mask][i] = scissors_probability * calculate_probability(mask ^ (1 << (i - 1)), i);
  }

  return dp[mask][i];
}

int main() {
  int N;
  scanf("%d", &N);

  for (int i = 1; i <= N; ++i) {
    scanf("%d", &players[i].rating);
  }

  // Read player information
  for (int i = 2; i <= N; ++i) {
    scanf("%d %d %d %d", &players[i].rating, &players[i].rock, &players[i].paper, &players[i].scissors);
  }

  // Initialize dp array
  for (int mask = 0; mask < (1 << N); ++mask) {
    for (int i = 1; i <= N; ++i) {
      dp[mask][i] = -1;
    }
  }

  // Find the highest rated player in the game
  int highest_rating_player = 1;
  for (int i = 2; i <= N; ++i) {
    if (players[i].rating > players[highest_rating_player].rating) {
      highest_rating_player = i;
    }
  }

  // Calculate the probability of winning the game
  double probability = calculate_probability((1 << N) - 1, highest_rating_player);

  printf("%.12lf\n", probability);

  return 0;
}