#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 25

struct product {
  int weight;
  double value;
  int total_value;
};

int comp(const void *a, const void *b) {
  return ((struct product*)a)->value < ((struct product*)b)->value;
}

int main(void) {
  FILE *fp = stdin;
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, fp)) return 0;
  int num, weight;
  sscanf(line, "%d %d", &num, &weight);

  struct product *prods = malloc(sizeof(struct product)*num);

  int i, j;
  for(i = 0; i < num; i++) {
    if(!fgets(line, BUF_SIZE, fp)) return 0;
    int val, wei;
    sscanf(line, "%d %d", &val, &wei);
    prods[i].weight = wei;
    prods[i].value = (double)val/(double)wei;
    prods[i].total_value = val;
  }

  qsort(prods, num, sizeof(struct product), comp);
  int cur_weight = 0;
  double sum = 0;
  for(i = 0; i < num; i++) {
    int rem = weight - cur_weight;
    if(rem > prods[i].weight) {
      cur_weight += prods[i].weight;
      sum += prods[i].total_value;
    } else {
      sum += prods[i].value * rem;
      break;
    }
  }
  printf("%lf\n", sum);
  return 0;
}
