// SPDX-License-Identifier: X11
// 2020-08-30
// Coprime (500pt)

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000005

#define u32 uint_fast32_t

bool *erato(u32 bound);
bool isset(u32 a, u32 *A, u32 len);

int main() {
  u32 N;
  scanf("%lu\n", &N);

  bool *ps = erato(MAX);
  u32 *pa = calloc(MAX, sizeof(u32));

  bool set = 0;
  bool p = 1;

  uint_fast8_t s;
  u32 A, i, j;
  scanf("%lu", &A);

  if (!(A & 1))
    pa[2] = 1;
  if (!(A % 3))
    pa[3] = 1;
  for (i = 5, s = 2; i < N; i += s, s = 6 - s)
    if (ps[i] && !(A % i))
      pa[i] = 1;

  for (i = 1; i < N; ++i) {
    scanf("%lu", &A);

    if (ps[A]) {
      set = 1;
      continue;
    }

    if (!(A & 1)) {
      if (pa[2]) {
        p = 0;
      }
      pa[2]++;
    }

    if (!(A % 3)) {
      if (pa[3])
        p = 0;
      pa[3]++;
    }

    for (j = 5, s = 2; j * j <= A; j += s, s = 6 - s)
      if (!(A % j)) {
        if (pa[j])
          p = 0;
        pa[j]++;
      }
  }

  if (p)
    printf("pairwise coprime\n");
  else if (set || isset(N, pa, MAX)) // !FIX contains 1 != setwise
    printf("setwise coprime\n");
  else
    printf("not coprime\n");

  free(ps);
  free(pa);
}

bool *erato(u32 bound) {
  if (!bound)
    return NULL;

  bool *array = calloc(bound, sizeof(bool));
  u32 i,j;
  uint_fast8_t s,ss;

  if (bound < 3)
    return array;
  array[2] = 1;

  if (bound < 4)
    return array;
  array[3] = 1;

  if (bound < 5)
    return array;

  for (i = 5, s = 2; i < bound; i += s, s = 6 - s)
    array[i] = 1;

  for (i = 5, s = 2; i < bound; i += s, s = 6 - s)
    if (array[i])
      for (j = i, ss = s; i * j < bound; j += ss, ss = 6 - ss)
        array[i * j] = 0;

  return array;
}

bool isset(u32 a, u32 *A, u32 len) {
  for (u32 i = 0; i < len; i++) {
    if (A[i] < a)
      return true;
  }
  return false;
}
