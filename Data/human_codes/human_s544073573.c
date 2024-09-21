// Aizu 0362: Trampoline
// 2017.9.28 bal4u@uu

#include <stdio.h>

#define MAX 300005
typedef struct { int t, b; } QUE;
QUE que[MAX+2]; int qsize;

#define PARENT(i) ((i)>>1)
#define LEFT(i)   ((i)<<1)
#define RIGHT(i)  (((i)<<1)+1)

void min_heapify(int i)
{
  int l, r, min;
  l = LEFT(i), r = RIGHT(i);
  if (l < qsize && que[l].t < que[i].t) min = l; else min = i;
  if (r < qsize && que[r].t < que[min].t) min = r;
  if (min != i) {
    QUE t = que[i]; que[i] = que[min]; que[min] = t;
    min_heapify(min);
  }
}

int deq1(int *t, int *b)
{
  if (qsize == 0) return 0;
  *t = que[0].t, *b = que[0].b;
  que[0] = que[--qsize];
  min_heapify(0);
  return 1;
}

void enq1(int t, int b)
{
  int i, min;

  i = qsize++;
  que[i].t = t, que[i].b = b;
  while (i > 0 && que[min = PARENT(i)].t > que[i].t) {
    QUE tt = que[i]; que[i] = que[min]; que[min] = tt;
    i = min;
  }
}

void max_heapify(int i)
{
	int l, r, max;
	l = LEFT(i), r = RIGHT(i);
	if (l < qsize && que[l].t > que[i].t) max = l; else max = i;
	if (r < qsize && que[r].t > que[max].t)	max = r;
	if (max != i) {
		QUE t = que[i]; que[i] = que[max], que[max] = t;
		max_heapify(max);
	}
}

int deq2(int *t, int *b)
{
	if (qsize == 0) return 0;
	*t = que[0].t, *b = que[0].b;
	que[0] = que[--qsize];
	max_heapify(0);
	return 1;
}

void enq2(int t, int b)
{
	int i, max;
	i = qsize++;
	que[i].t = t, que[i].b = b;
	while (i > 0 && que[max = PARENT(i)].t < que[i].t) {
		QUE t = que[i]; que[i] = que[max], que[max] = t;
		i = max;
	}
}

int d[MAX+2];

int main()
{
	int n, i, j, a, b;

	scanf("%d", &n);
	qsize = 0;					// ????????????????????£?????\???????????????
	for (a = 0, i = 0; i < n; i++, a += 10)	{
		scanf("%d", &b); d[i] = b;
		enq1(a, a+b);
	}

	for (j = 0, i = 0; i < n-1; i++, j += 10) {
		a = que[0].t, b = que[0].b;
		if (b < j+10) while (1) {
			if (qsize == 0) goto NO;
			deq1(&a, &b);
			if (a > j) goto NO;
			if (j+10 <= b) break;
		}
	}

	qsize = 0;
	for (a = (n-1)*10, i = n-1; i >= 0; i--, a -= 10) enq2(a, a-d[i]);
	for (j = (n-1)*10, i = n-1; i > 0; i--, j -= 10) {
		a = que[0].t, b = que[0].b;
		if (j-10 < b) while (1) {
			if (qsize == 0) goto NO;
			deq2(&a, &b);
			if (a < j) goto NO;
			if (b <= j-10) break;
		}
	}
	puts("yes");
	return 0;
NO: puts("no");
	return 0;
}