#include <stdio.h>
#include <stdlib.h>

typedef struct sushi {
  long long int x; // position of the sushi
  long long int v; // nutritive value of the sushi
} Sushi;

// compare function for qsort
int compare_sushi(const void *a, const void *b) {
  Sushi *sushi_a = (Sushi *)a;
  Sushi *sushi_b = (Sushi *)b;
  return sushi_a->x - sushi_b->x;
}

int main() {
  long long int n, c; // number of sushi, circumference
  long long int i;
  long long int max_nutrition = 0;
  long long int total_nutrition = 0;
  long long int total_energy = 0;
  Sushi *sushi;

  // input
  scanf("%lld %lld", &n, &c);
  sushi = (Sushi *)malloc(sizeof(Sushi) * n);
  for (i = 0; i < n; i++) {
    scanf("%lld %lld", &sushi[i].x, &sushi[i].v);
  }

  // sort sushi by position
  qsort(sushi, n, sizeof(Sushi), compare_sushi);

  // calculate maximum nutrition
  for (i = 0; i < n; i++) {
    // calculate total nutrition and energy
    total_nutrition += sushi[i].v;
    total_energy += sushi[i].x;
    // calculate max nutrition
    max_nutrition = (total_nutrition - total_energy) > max_nutrition
                    ? (total_nutrition - total_energy)
                    : max_nutrition;
  }

  // output
  printf("%lld\n", max_nutrition);
  free(sushi);
  return 0;
}