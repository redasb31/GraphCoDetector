#include <stdio.h>

int main() {
  // N: number of vertices
  // X, Y: vertices connected by an extra edge
  int N, X, Y;
  scanf("%d %d %d", &N, &X, &Y);

  // Array to store the number of pairs for each distance
  int distances[N];
  for (int i = 0; i < N; i++) {
    distances[i] = 0;
  }

  // Calculate the number of pairs for each distance
  // For distances 1 to X-1, it's simply i*(N-i)
  for (int i = 1; i < X; i++) {
    distances[i] = i * (N - i);
  }

  // For distance X, we need to add the pairs (X, Y) and (X+1, Y)
  distances[X] = X * (N - X) + 2;

  // For distances X+1 to Y-1, we need to add the pair (X, Y)
  for (int i = X + 1; i < Y - 1; i++) {
    distances[i] = i * (N - i) + 1;
  }

  // For distance Y, we need to add the pair (X, Y) and the pairs (Y, Y+1) to (Y, N)
  distances[Y] = Y * (N - Y) + 1 + (N - Y);

  // For distances Y+1 to N-1, it's simply i*(N-i)
  for (int i = Y + 1; i < N; i++) {
    distances[i] = i * (N - i);
  }

  // Print the number of pairs for each distance
  for (int i = 1; i < N; i++) {
    printf("%d\n", distances[i]);
  }

  return 0;
}