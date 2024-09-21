#include <stdio.h>

int main() {
  // N: number of donuts
  // K: number of decoration tasks
  int N, K;

  // T: number of tasks Mr. D did
  int T;

  // l_i: start index of the i-th task
  // r_i: end index of the i-th task
  // x_i: ID of the i-th task
  int l_i, r_i, x_i;

  // task_done[i]: whether task i is done
  int task_done[200001];

  // donut_decorated[i]: whether donut i is decorated correctly
  int donut_decorated[200001];

  // Input N, K, and T
  scanf("%d %d\n%d", &N, &K, &T);

  // Initialize task_done and donut_decorated arrays
  for (int i = 1; i <= K; i++) {
    task_done[i] = 0;
  }

  for (int i = 1; i <= N; i++) {
    donut_decorated[i] = 0;
  }

  // Input tasks done by Mr. D
  for (int i = 0; i < T; i++) {
    scanf("%d %d %d", &l_i, &r_i, &x_i);

    // Mark task x_i as done
    task_done[x_i] = 1;

    // Mark donuts in the interval [l_i, r_i] as decorated
    for (int j = l_i; j <= r_i; j++) {
      donut_decorated[j] = 1;
    }
  }

  // Check if all tasks are done and count decorated donuts
  int count = 0;
  for (int i = 1; i <= K; i++) {
    // If a task is not done, no donuts can be sold
    if (task_done[i] == 0) {
      count = 0;
      break;
    }
  }

  // Count the number of correctly decorated donuts
  if (count != 0) {
    for (int i = 1; i <= N; i++) {
      if (donut_decorated[i] == 1) {
        count++;
      }
    }
  }

  // Output the number of donuts that can be sold
  printf("%d\n", count);

  return 0;
}