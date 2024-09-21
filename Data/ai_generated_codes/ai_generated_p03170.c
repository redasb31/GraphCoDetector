// This program determines the winner of a stone removal game.
//
// The game involves two players, Taro and Jiro, who alternate turns removing
// stones from a pile. Each player can remove a number of stones equal to one
// of the elements in a set A. The player who cannot remove any stones loses.
//
// The program uses a dynamic programming approach to determine the winner.
// A table dp is used to store whether a player can win given a particular
// number of stones remaining.
//
// Input:
// N K
// a_1 a_2 ... a_N
//
// Output:
// First if Taro wins, Second if Jiro wins.

#include <stdio.h>
#include <stdbool.h>

int main() {
  // N is the number of elements in the set A.
  int N;
  // K is the initial number of stones.
  int K;
  // a is an array containing the elements of the set A.
  int a[100];

  // Read the input.
  scanf("%d %d", &N, &K);
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  // dp[i] is true if the player can win given i stones remaining.
  bool dp[100001] = {false};

  // If there are 0 stones remaining, the player cannot win.
  dp[0] = false;

  // For each number of stones remaining.
  for (int i = 1; i <= K; i++) {
    // For each element in the set A.
    for (int j = 0; j < N; j++) {
      // If the player can remove a[j] stones and the opponent cannot win with the
      // remaining stones, then the player can win.
      if (i >= a[j] && !dp[i - a[j]]) {
        dp[i] = true;
        break;
      }
    }
  }

  // If the player can win with K stones remaining, then Taro wins.
  if (dp[K]) {
    printf("First\n");
  } else {
    // Otherwise, Jiro wins.
    printf("Second\n");
  }

  return 0;
}