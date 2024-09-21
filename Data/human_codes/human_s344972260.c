#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<string.h>

typedef int32_t i32;

typedef struct node {
  char s[11];
  i32 p;
  i32 index;
} node;

int cmp_node (const void *a, const void *b) {
  node *p = (node *)a;
  node *q = (node *)b;
  int c = strcmp (p->s, q->s);
  if (c != 0) return c;
  return q->p - p->p;
}

void run (void) {
  i32 n;
  scanf ("%" SCNi32, &n);
  node *a = (node *) calloc (n, sizeof (node));
  for (i32 i = 0; i < n; ++i) {
    scanf ("%s%" SCNi32, a[i].s, &a[i].p);
    a[i].index = i + 1;
  }
  qsort (a, n, sizeof (node), cmp_node);
  for (i32 i = 0; i < n; ++i) {
    printf ("%" PRIi32 "\n", a[i].index);
  }
}

int main (void) {
  run();
  return 0;
}
