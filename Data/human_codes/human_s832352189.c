/*  ex5-4 TSP 2opt
    matsuura.m.ag
    Mikihito Matsuura        */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INSERTIONSORT_THRESHOLD 7

/*** UTILITY ***/
void swap(void *foo, void *bar, size_t len) {
    unsigned char *hoge = foo, *fuga = bar, tmp;
    for (size_t i = 0; i != len; ++i) {
        tmp = hoge[i];
        hoge[i] = fuga[i];
        fuga[i] = tmp;
    }
}

/*** SORT ***/
void insertion_sort(void *base, size_t low, size_t high, size_t size, int (*compare)(const void*, const void*)) {
  size_t i, j;
  char *base_ptr = base;
  for (i = low; i < high; i++) {
    for (j = i; j > low && compare(base_ptr + (j - 1) * size, base_ptr + j * size) > 0; j--) {
      swap(base + (j - 1) * size, base + j * size, size);
    }
  }
}

void merge_sort(void *src, void *dest, size_t low, size_t high, size_t off, size_t size, int (*compare)(const void*, const void*)) {
  size_t length = high - low;
  int dest_low, dest_high, mid, i, p, q;
  char *src_ptr = src, *dest_ptr = dest;
  if (length < INSERTIONSORT_THRESHOLD) {
    insertion_sort(dest, low, high, size, compare);
    return;
  }
  dest_low = low;
  dest_high = high;
  low += off;
  high += off;
  mid = low + (high - low) / 2;
  merge_sort(dest, src, low, mid, -off, size, compare);
  merge_sort(dest, src, mid, high, -off, size, compare);
  if (compare(src_ptr + (mid - 1) * size, src_ptr + mid * size) <= 0) {
    memcpy(dest_ptr + dest_low, src_ptr + low, length * size);
    return;
  }
  for (i = dest_low, p = low, q = mid; i < dest_high; i++) {
    if (q >= high || (p < mid && compare(src_ptr + p * size, src_ptr + q * size) <= 0)) {
      memcpy(dest_ptr + i * size, src_ptr + p * size, size);
      ++p;
    } else {
      memcpy(dest_ptr + i * size, src_ptr + q * size, size);
      ++q;
    }
  }
}

int msort(void *base, size_t num, size_t size, int (*compare)(const void*, const void*)) {
  void *tmp = malloc(size * num);
  if (tmp == NULL) return 1;
  memcpy(tmp, base, num * size);
  merge_sort(tmp, base, 0, num, 0, size, compare);
  free(tmp);
  return 0;
}

/*** DISJOINT SET DATA STRUCTURE ***/
int* ds_init(int num) {
  int i, *tree;
  tree = malloc(sizeof(int) * num);
  if (tree == NULL) return NULL;
  for (i = 0; i < num; i++) tree[i] = i;
  return tree;
}

int ds_find(int *tree, int node) {
  if (tree[node] == node) return node;
  return tree[node] = ds_find(tree, tree[node]);
}

int ds_union(int *tree, int parent, int child) {
  parent = ds_find(tree, parent);
  child = ds_find(tree, child);
  if (parent == child) return 0;
  tree[child] = parent;
  return 1;
}

struct pair {
  int x, y;
};

int cmp(const void *foo, const void *bar) {
  struct pair foo_val = *((struct pair*) foo), bar_val = *((struct pair*) bar);
  if (foo_val.x == bar_val.x) {
    return (foo_val.y > bar_val.y) - (foo_val.y < bar_val.y);
  } else {
    return (foo_val.x > bar_val.x) - (foo_val.x < bar_val.x);
  }
  
}

/*** ENTRY POINT ***/
int main(void) {
  int n, i;
  struct pair array[100000];

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d %d", &array[i].x, &array[i].y);
  }
  msort(array, n, sizeof(struct pair), cmp);
  for (i = 0; i < n; i++) {
    printf("%d %d\n", array[i].x, array[i].y);
  }
  return 0;
}

