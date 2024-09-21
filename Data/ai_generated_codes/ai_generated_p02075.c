#include <stdio.h>
#include <math.h>

int main() {
  // N: the number of humans on the platform
  int N;
  // x_Z: the initial position of the zombie
  long long x_Z;
  // v_Z: the velocity of the zombie
  long long v_Z;
  // x_i: the initial position of the i-th human
  long long x_i;
  // v_i: the velocity of the i-th human
  long long v_i;

  // Read the number of humans
  scanf("%d", &N);

  // Read the initial position and velocity of the zombie
  scanf("%lld %lld", &x_Z, &v_Z);

  // Iterate over the humans
  for (int i = 0; i < N; i++) {
    // Read the initial position and velocity of the i-th human
    scanf("%lld %lld", &x_i, &v_i);

    // Calculate the time it takes for the zombie to reach the i-th human
    double time = (double)(x_i - x_Z) / (v_Z - v_i);

    // If the zombie will never reach the i-th human, print -1
    if (time < 0 || (v_Z == v_i && x_i != x_Z)) {
      printf("-1\n");
    } else {
      // Otherwise, print the time it takes for the zombie to reach the i-th human
      printf("%.12lf\n", time);
    }
  }

  return 0;
}