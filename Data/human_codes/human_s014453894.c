/*
 * 1071.c: BD Shelf
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* constant */

#define STRLEN	(10)
#define QLEN	(5)

#define MAX_N	(20000)
#define MAX_W	(20)
#define MAX_Q	(20000)

/* typedef */

typedef char str_t[STRLEN + 1];

typedef struct _anime_t {
  char str[STRLEN + 1];
  int slen, exp, pri;
} anime_t;

typedef struct _query_t {
  char str[QLEN + 1];
  int len, qmin;
} query_t;

/* global variables */

static anime_t animes[MAX_N];
static query_t queries[MAX_Q];
static angs[MAX_N];
static int ws[MAX_W + 1], pws[MAX_W + 1], amins[MAX_W + 1], pamins[MAX_W + 1];

/* subrouines */

void print_animes(int n) {
  int i;

  printf("[");
  for (i = 0; i < n; i++) {
    if (i > 0) printf(", ");
    printf("[%s, %d, %d]", animes[i].str, animes[i].exp, animes[i].pri);
  }
  printf("]\n");
}

/* main */

int main(int argc, char **argv) {
  int aminj, i, j, k, n, qlen, qn, w, wsj;
  anime_t *aj;
  query_t *qi, *qj;
  char line[1024];

  for (;;) {
    sscanf(gets(line), "%d %d", &n, &w);
    if ((n | w) == 0) break;

    for (i = 0; i < n; i++) {
      sscanf(gets(line), "%s %d %d",
	     &(animes[i].str), &(animes[i].exp), &(animes[i].pri));
      animes[i].slen = strlen(animes[i].str);
    }
    /* print_animes(n); */

    sscanf(gets(line), "%d", &qn);

    for (i = 0; i < qn; i++) {
      qi = &(queries[i]);
      gets(qi->str);
      qi->len = strlen(qi->str);
    }

    for (i = 0; i < qn; i++) {
      qi = &(queries[i]);
      bzero(angs, sizeof(angs));

      for (j = 0; j < i; j++) {
	qj = &(queries[j]);

	qlen = (qi->len < qj->len) ? qi->len : qj->len;
	if (strncmp(qi->str, qj->str, qlen) == 0)
	  angs[qj->qmin] = 1;
      }

      bzero(ws, sizeof(ws));
      for (j = 0; j <= w; j++) amins[j] = -1;

      for (j = 0; j < n; j++) {
	if (angs[j]) continue;

	aj = &(animes[j]);

	if (strstr(aj->str, qi->str) == NULL) continue;

	bcopy(ws, pws, sizeof(ws));
	bcopy(amins, pamins, sizeof(amins));

	for (k = 0; k <= w; k++) {
	  if (aj->pri <= k) {
	    wsj = pws[k - aj->pri] + aj->exp;
	    if (ws[k] < wsj) {
	      ws[k] = wsj;
	      aminj = pamins[k - aj->pri];
	      if (aminj < 0 || animes[aminj].exp > aj->exp)
		amins[k] = j;
	    }
	  }
	}
      }

      qi->qmin = amins[w];

      printf("%d\n", (ws[w] > 0) ? ws[w] : -1);
    }
  }

  return 0;
}